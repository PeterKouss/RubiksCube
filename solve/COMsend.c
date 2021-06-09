/*
* Reference
* [1] https://blog.csdn.net/sinat_23039991/java/article/details/78642351
* [2] https://www.cnblogs.com/code7854/p/4287650.html
*/

#include "declaration.h"

#include <Windows.h>
#include <tchar.h>

#define PATH_OF_COM "HARDWARE\\DEVICEMAP\\SERIALCOMM"
#define KEY_LEN 100

wchar_t KeyName[KEY_LEN];
wchar_t KeyData[KEY_LEN];
char KeyData_in_char[KEY_LEN];

void readCOM()
{
	HKEY hKEY;
	LPCTSTR lpSubKey = _T(PATH_OF_COM);

	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, lpSubKey, NULL, KEY_READ, &hKEY) != ERROR_SUCCESS)
	{
		printf("Error: Fail to RegOpenKeyEx().\n");
		system("pause"); exit(1);
	}

	LONG status;
	DWORD dwIndex = 0;
	DWORD dwKeyName = KEY_LEN;
	DWORD dwKeyData = KEY_LEN;

	printf("Selectable COM list (KeyName - KeyData):\n");
	while (1)
	{
		status = RegEnumValue(hKEY, dwIndex, KeyName, &dwKeyName, NULL, NULL, KeyData, &dwKeyData);
		if (status == ERROR_NO_MORE_ITEMS) break; // �������������
		if (status != ERROR_SUCCESS) // ���ʧ���򱨴�
		{
			printf("Error: Fail to RegEnumValue().\n");
			system("pause"); exit(1);
		}

		wprintf(L"Index %d: %s - %s\n", dwIndex, KeyName, KeyData);

		dwIndex++;
		dwKeyName = KEY_LEN;
		dwKeyData = KEY_LEN;
	}

	while (1)
	{
		char command[3];
		printf("Select an Index (0 - 9):\n");
		mygetline(command, 1);
		if (command[0] >= '0' && command[1] <= '9' && command[1] == '\0')
		{
			dwIndex = command[0] - '0';
			break;
		}
		else
		{
			printf("Error: Illegal index.\n");
		}
	}
	
	dwKeyName = KEY_LEN;
	dwKeyData = KEY_LEN;
	status = RegEnumValue(hKEY, dwIndex, KeyName, &dwKeyName, NULL, NULL, KeyData, &dwKeyData);
	if (status != ERROR_SUCCESS) // ���ʧ���򱨴�
	{
		printf("Error: Fail to RegEnumValue().\n");
		system("pause"); exit(1);
	}

	RegCloseKey(hKEY);
}

void COMsend(char* str, int len)
{
	FILE* fp1;
	if ((fp1 = fopen("COM.txt", "rb")) == NULL)
	{
		readCOM();
		WideCharToMultiByte(CP_ACP, 0, KeyData, KEY_LEN, KeyData_in_char, KEY_LEN, NULL, NULL); // ��KeyDataת����խ�ַ���

		FILE* fp2;
		if ((fp2 = fopen("COM.txt", "w")) == NULL)
		{
			printf("Error: Fail to create \"COM.txt\".\n");
			system("pause"); exit(1);
		}
		printf("Create \"COM.txt\" successfully.\n");
		fprintf(fp2, "%s", KeyData_in_char);
		fclose(fp2);
	}
	else
	{
		printf("Open \"COM.txt\" successfully.\n");
		fseek(fp1, 0, SEEK_SET);
		fread(KeyData_in_char, KEY_LEN, 1, fp1);
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, KeyData_in_char, KEY_LEN, KeyData, KEY_LEN);
		fclose(fp1);
	}
	wprintf(L"KeyData: %s\n", KeyData);

	/* �򿪴��� */
	HANDLE hCom;
	hCom = CreateFile(
		KeyData, // COM��
		GENERIC_READ | GENERIC_WRITE, // �������д
		0, // ��ռ��ʽ
		NULL,
		OPEN_EXISTING, // �򿪶����Ǵ���
		0, // ͬ����ʽ
		NULL
	);
	if (hCom == (HANDLE)-1)
	{
		printf("Error: Fail to open COM.\n");
		system("pause"); exit(1);
	}
	printf("COM: Open COM successfully.\n");

	/* ���ô��� */
	// ���뻺����������������Ĵ�С����20480
	SetupComm(hCom, 20480, 20480);
	COMMTIMEOUTS TimeOuts;
	// �趨����ʱ
	TimeOuts.ReadIntervalTimeout = 1000;
	TimeOuts.ReadTotalTimeoutMultiplier = 500;
	TimeOuts.ReadTotalTimeoutConstant = 5000;
	// �趨д��ʱ
	TimeOuts.WriteTotalTimeoutMultiplier = 500;
	TimeOuts.WriteTotalTimeoutConstant = 2000;
	// ���ó�ʱ
	SetCommTimeouts(hCom, &TimeOuts);

	DCB dcb;
	GetCommState(hCom, &dcb);
	dcb.BaudRate = 115200; // ������Ϊ115200
	dcb.ByteSize = 8; // ÿ���ֽ���8λ
	dcb.Parity = NOPARITY; // ����żУ��λ
	dcb.StopBits = ONESTOPBIT; // 1λֹͣλ
	dcb.fParity = FALSE;
	dcb.fNull = FALSE;
	SetCommState(hCom, &dcb);
	PurgeComm(hCom, PURGE_TXCLEAR | PURGE_RXCLEAR); // �ڶ�д����֮ǰ��ջ�����

	DWORD DWORDnNumberOfBytesToWrite = len;
	DWORD DWORDlpNumberOfBytesWritten = 0;
	if (!WriteFile(hCom, str, DWORDnNumberOfBytesToWrite, &DWORDlpNumberOfBytesWritten, NULL))
	{
		printf("Error: Fail to send data.\n");
		system("pause"); exit(1);
	}
	printf("COM: Send data successfully.\n");

	/* �رմ��� */
	CloseHandle(hCom);
}
