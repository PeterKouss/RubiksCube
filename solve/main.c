/*
#ifdef LINUX
#include <sys/time.h>
#define CLOCK_VARIABLE struct timeval t1, t2
#define GET_T1 gettimeofday(&t1, NULL)
#define GET_T2 gettimeofday(&t2, NULL)
#define GET_T double t = (int)t2.tv_sec - (int)t1.tv_sec + ((int)t2.tv_usec - (int)t1.tv_usec) / 1000000.0
#else
#include <time.h>
#define CLOCK_VARIABLE clock_t t1, t2
#define GET_T1 t1 = clock()
#define GET_T2 t2 = clock()
#define GET_T double t = (double)(t2 - t1) / CLOCKS_PER_SEC
#endif // LINUX
*/

#include "declaration.h"

int main()
{
	/* 0-1. RubiksCubeCOM_param.exe **************************************************
	while (1)
	{
		char setting[6];
		printf("Enter your setting (c000 - c999 for speed, o to out, i to in, q to quit):\n");
		mygetline(setting, 4);
		if (setting[0] == 'c'
			&& setting[1] >= '0' && setting[1] <= '9'
			&& setting[2] >= '0' && setting[2] <= '9'
			&& setting[3] >= '0' && setting[3] <= '9'
			&& setting[4] == '\0'
			|| setting[0] == 'o' && setting[1] == '\0'
			|| setting[0] == 'i' && setting[1] == '\0')
		{
			_addnewline_and_COMsend(setting);
		}
		else if (setting[0] == 'q' && setting[1] == '\0')
		{
			break;
		}
		else
		{
			printf("Error: Illegal setting.\n");
		}
	}
	// */

	/* x-1. RubiksCubeCamera.exe **************************************************
	cube_fread();
	FILE* fp;
	// if ((fp = fopen("pic_1.txt", "w")) == NULL) // x = 1
	// if ((fp = fopen("pic_2.txt", "w")) == NULL) // x = 2
	// if ((fp = fopen("pic_3.txt", "w")) == NULL) // x = 3
	// if ((fp = fopen("pic_4.txt", "w")) == NULL) // x = 4
	// if ((fp = fopen("pic_5.txt", "w")) == NULL) // x = 5
	if ((fp = fopen("pic_6.txt", "w")) == NULL) // x = 6
	{
		printf("Error: No such file or directory.\n");
		system("pause"); exit(1);
	}
	fprintf(fp, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c", \
		side_up[0], side_up[3], side_up[6], side_fr[0], side_fr[3], side_fr[6], \
		side_up[7], side_fr[1], \
		side_up[2], side_up[5], side_up[8], side_fr[2], side_fr[5], side_fr[8]);
	fclose(fp);
	return 0;
	// */

	/* x-2. RubiksCubeCOM.exe **************************************************
	// COMsend("ULDRFBuldrfb\n", 13); // x = 0
	// COMsend("u\n", 2); // x = 1
	// COMsend("UDfBUdLr\n", 9); // x = 2
	// COMsend("RlDubFdFFLLRRBB\n", 16); // x = 3
	// COMsend("U\n", 2); // x = 4
	// COMsend("udFbuDLr\n", 9); // x = 5
	// */

	/* x-3. RubiksCubePre.exe **************************************************
	// cube_fread();
	// operation_analysis("ULDRFBuldrfb"); // x = 0
	// operation_analysis("u"); // x = 1
	// operation_analysis("UDfBUdLr"); // x = 2
	// operation_analysis("RlDubFdFFLLRRBB"); // x = 3
	// operation_analysis("U"); // x = 4
	// operation_analysis("udFbuDLr"); // x = 5
	// cube_fprintf();
	// */

	/* 7-1. RubiksCubeImgproc.exe **************************************************
	system("copy \"pic_1.txt\" \"ipt_1.txt\"");
	system("copy \"pic_2.txt\" \"ipt_2.txt\"");
	system("copy \"pic_3.txt\" \"ipt_3.txt\"");
	system("copy \"pic_4.txt\" \"ipt_4.txt\"");
	system("copy \"pic_5.txt\" \"ipt_5.txt\"");
	system("copy \"pic_6.txt\" \"ipt_6.txt\"");
	// */

	/* 7-2. RubiksCubeInput.exe **************************************************
	char temp[14];

	FILE* fp1;
	if ((fp1 = fopen("ipt_1.txt", "rb")) == NULL)
	{
		printf("Error: No such file or directory.\n");
		system("pause"); exit(1);
	}
	fseek(fp1, 0, SEEK_SET);
	fread(temp, 14, 1, fp1);
	side_up[0] = temp[0]; // new
	side_up[3] = temp[1]; // new
	side_up[6] = temp[2]; // new
	side_fr[0] = temp[3]; // new
	side_fr[3] = temp[4]; // new
	side_fr[6] = temp[5]; // new
	side_up[7] = temp[6]; // new
	side_fr[1] = temp[7]; // new
	side_up[2] = temp[8]; // new
	side_up[5] = temp[9]; // new
	side_up[8] = temp[10]; // new
	side_fr[2] = temp[11]; // new
	side_fr[5] = temp[12]; // new
	side_fr[8] = temp[13]; // new
	fclose(fp1);

	FILE* fp2;
	if ((fp2 = fopen("ipt_2.txt", "rb")) == NULL)
	{
		printf("Error: No such file or directory.\n");
		system("pause"); exit(1);
	}
	fseek(fp2, 0, SEEK_SET);
	fread(temp, 14, 1, fp2);
	if (side_up[2] != temp[0]) { printf("Error: Input error 2-0.\n"); system("pause"); exit(1); }
	side_up[1] = temp[1]; // new
	if (side_up[0] != temp[2]) { printf("Error: Input error 2-2.\n"); system("pause"); exit(1); }
	side_lf[0] = temp[3]; // new
	if (side_fr[3] != temp[4]) { printf("Error: Input error 2-4.\n"); system("pause"); exit(1); }
	if (side_fr[6] != temp[5]) { printf("Error: Input error 2-5.\n"); system("pause"); exit(1); }
	if (side_up[3] != temp[6]) { printf("Error: Input error 2-6.\n"); system("pause"); exit(1); }
	side_lf[1] = temp[7]; // new
	if (side_up[8] != temp[8]) { printf("Error: Input error 2-8.\n"); system("pause"); exit(1); }
	if (side_up[7] != temp[9]) { printf("Error: Input error 2-9.\n"); system("pause"); exit(1); }
	if (side_up[6] != temp[10]) { printf("Error: Input error 2-10.\n"); system("pause"); exit(1); }
	side_lf[2] = temp[11]; // new
	if (side_fr[5] != temp[12]) { printf("Error: Input error 2-12.\n"); system("pause"); exit(1); }
	if (side_fr[8] != temp[13]) { printf("Error: Input error 2-13.\n"); system("pause"); exit(1); }
	fclose(fp2);

	FILE* fp3;
	if ((fp3 = fopen("ipt_3.txt", "rb")) == NULL)
	{
		printf("Error: No such file or directory.\n");
		system("pause"); exit(1);
	}
	fseek(fp3, 0, SEEK_SET);
	fread(temp, 14, 1, fp3);
	if (side_up[6] != temp[0]) { printf("Error: Input error 3-0.\n"); system("pause"); exit(1); }
	side_bk[1] = temp[1]; // new
	if (side_up[8] != temp[2]) { printf("Error: Input error 3-2.\n"); system("pause"); exit(1); }
	side_rt[0] = temp[3]; // new
	side_rt[3] = temp[4]; // new
	if (side_fr[6] != temp[5]) { printf("Error: Input error 3-5.\n"); system("pause"); exit(1); }
	if (side_up[5] != temp[6]) { printf("Error: Input error 3-6.\n"); system("pause"); exit(1); }
	side_rt[1] = temp[7]; // new
	if (side_up[0] != temp[8]) { printf("Error: Input error 3-8.\n"); system("pause"); exit(1); }
	side_rt[7] = temp[9]; // new
	if (side_up[2] != temp[10]) { printf("Error: Input error 3-10.\n"); system("pause"); exit(1); }
	side_rt[2] = temp[11]; // new
	side_rt[5] = temp[12]; // new
	if (side_fr[8] != temp[13]) { printf("Error: Input error 3-13.\n"); system("pause"); exit(1); }
	fclose(fp3);

	FILE* fp4;
	if ((fp4 = fopen("ipt_4.txt", "rb")) == NULL)
	{
		printf("Error: No such file or directory.\n");
		system("pause"); exit(1);
	}
	fseek(fp4, 0, SEEK_SET);
	fread(temp, 14, 1, fp4);
	side_dn[0] = temp[0]; // new
	side_dn[3] = temp[1]; // new
	side_dn[6] = temp[2]; // new
	side_bk[8] = temp[3]; // new
	side_bk[5] = temp[4]; // new
	side_bk[2] = temp[5]; // new
	side_dn[1] = temp[6]; // new
	side_fr[7] = temp[7]; // new
	side_dn[2] = temp[8]; // new
	side_dn[5] = temp[9]; // new
	side_dn[8] = temp[10]; // new
	side_bk[6] = temp[11]; // new
	side_bk[3] = temp[12]; // new
	side_bk[0] = temp[13]; // new
	fclose(fp4);

	FILE* fp5;
	if ((fp5 = fopen("ipt_5.txt", "rb")) == NULL)
	{
		printf("Error: No such file or directory.\n");
		system("pause"); exit(1);
	}
	fseek(fp5, 0, SEEK_SET);
	fread(temp, 14, 1, fp5);
	if (side_dn[6] != temp[0]) { printf("Error: Input error 5-0.\n"); system("pause"); exit(1); }
	if (side_dn[1] != temp[1]) { printf("Error: Input error 5-1.\n"); system("pause"); exit(1); }
	if (side_dn[8] != temp[2]) { printf("Error: Input error 5-2.\n"); system("pause"); exit(1); }
	side_rt[8] = temp[3]; // new
	if (side_bk[5] != temp[4]) { printf("Error: Input error 5-4.\n"); system("pause"); exit(1); }
	if (side_bk[2] != temp[5]) { printf("Error: Input error 5-5.\n"); system("pause"); exit(1); }
	if (side_dn[5] != temp[6]) { printf("Error: Input error 5-6.\n"); system("pause"); exit(1); }
	if (side_rt[7] != temp[7]) { printf("Error: Input error 5-7.\n"); system("pause"); exit(1); }
	if (side_dn[0] != temp[8]) { printf("Error: Input error 5-8.\n"); system("pause"); exit(1); }
	side_dn[7] = temp[9]; // new
	if (side_dn[2] != temp[10]) { printf("Error: Input error 5-10.\n"); system("pause"); exit(1); }
	side_rt[6] = temp[11]; // new
	if (side_bk[3] != temp[12]) { printf("Error: Input error 5-12.\n"); system("pause"); exit(1); }
	if (side_bk[0] != temp[13]) { printf("Error: Input error 5-13.\n"); system("pause"); exit(1); }
	fclose(fp5);

	FILE* fp6;
	if ((fp6 = fopen("ipt_6.txt", "rb")) == NULL)
	{
		printf("Error: No such file or directory.\n");
		system("pause"); exit(1);
	}
	fseek(fp6, 0, SEEK_SET);
	fread(temp, 14, 1, fp6);
	if (side_dn[2] != temp[0]) { printf("Error: Input error 6-0.\n"); system("pause"); exit(1); }
	if (side_lf[1] != temp[1]) { printf("Error: Input error 6-1.\n"); system("pause"); exit(1); }
	if (side_dn[0] != temp[2]) { printf("Error: Input error 6-2.\n"); system("pause"); exit(1); }
	side_lf[8] = temp[3]; // new
	side_lf[5] = temp[4]; // new
	if (side_bk[2] != temp[5]) { printf("Error: Input error 6-5.\n"); system("pause"); exit(1); }
	if (side_dn[3] != temp[6]) { printf("Error: Input error 6-6.\n"); system("pause"); exit(1); }
	side_lf[7] = temp[7]; // new
	if (side_dn[8] != temp[8]) { printf("Error: Input error 6-8.\n"); system("pause"); exit(1); }
	side_bk[7] = temp[9]; // new
	if (side_dn[6] != temp[10]) { printf("Error: Input error 6-10.\n"); system("pause"); exit(1); }
	side_lf[6] = temp[11]; // new
	side_lf[3] = temp[12]; // new
	if (side_bk[0] != temp[13]) { printf("Error: Input error 6-13.\n"); system("pause"); exit(1); }
	fclose(fp6);

	operation_analysis("FFLLRRBBdFbuDLr");
	cube_fprintf();
	// */

	// /* 7-3. RubiksCubeSolve.exe **************************************************
	while (1)
	{
		int have_had_command_z = 0;
		int have_had_command_x = 0;

		// 控制指令
		while (1)
		{
			if (have_had_command_z == 0)
			{
				cube_solve();
				_addnewline_and_COMsend(planB);
				have_had_command_z = 1;
			}
			else
			{
				char command[3];
				printf("Enter your command (x to stop, q to quit):\n");
				mygetline(command, 1);
				if (command[0] == 'x' && command[1] == '\0')
				{
					_addnewline_and_COMsend(command);
					have_had_command_x = 1;
					break;
				}
				else if (command[0] == 'q' && command[1] == '\0')
				{
					break;
				}
				else
				{
					printf("Error: Illegal command.\n");
				}
			}
		}

		if (have_had_command_x == 0) break;

		// 初始化指令
		while (1)
		{
			char setting[6];
			printf("Enter your setting (c000 - c999 for speed, o to out, i to in, q to quit):\n");
			mygetline(setting, 4);
			if (setting[0] == 'c'
				&& setting[1] >= '0' && setting[1] <= '9'
				&& setting[2] >= '0' && setting[2] <= '9'
				&& setting[3] >= '0' && setting[3] <= '9'
				&& setting[4] == '\0'
				|| setting[0] == 'o' && setting[1] == '\0'
				|| setting[0] == 'i' && setting[1] == '\0')
			{
				_addnewline_and_COMsend(setting);
			}
			else if (setting[0] == 'q' && setting[1] == '\0')
			{
				break;
			}
			else
			{
				printf("Error: Illegal setting.\n");
			}
		}
	}
	// */

	return 0;
}
