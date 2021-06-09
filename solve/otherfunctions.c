#include "declaration.h"
#include <stdio.h>

COLOR side_up[9] = { CR_UP, CR_UP, CR_UP, CR_UP, CR_UP, CR_UP, CR_UP, CR_UP, CR_UP };
COLOR side_dn[9] = { CR_DN, CR_DN, CR_DN, CR_DN, CR_DN, CR_DN, CR_DN, CR_DN, CR_DN };
COLOR side_lf[9] = { CR_LF, CR_LF, CR_LF, CR_LF, CR_LF, CR_LF, CR_LF, CR_LF, CR_LF };
COLOR side_rt[9] = { CR_RT, CR_RT, CR_RT, CR_RT, CR_RT, CR_RT, CR_RT, CR_RT, CR_RT };
COLOR side_fr[9] = { CR_FR, CR_FR, CR_FR, CR_FR, CR_FR, CR_FR, CR_FR, CR_FR, CR_FR };
COLOR side_bk[9] = { CR_BK, CR_BK, CR_BK, CR_BK, CR_BK, CR_BK, CR_BK, CR_BK, CR_BK };

void _addnewline_and_COMsend(char* str)
{
	addnewline(str, count_string(str));
	COMsend(str, count_string(str));
}

// 输入到字符串str，最多允许输入len个字符（不含'\0'）
int mygetline(char* str, int len)
{
	char c;
	char* s = str;
	while ((c = getchar()) != '\n')
	{
		if (s < str + len) *s++ = c;
		else
		{
			printf("ERROR: TOO MANY CHARACTERS! INPUT AGAIN:\n");
			while ((c = getchar()) != '\n'); // 刷掉缓冲区
			s = str; // 重新初始化
		}
	}
	*s = '\0';
	return s - str;
}

// 添加换行符
int addnewline(char* str, int len)
{
	*(str + len) = '\n';
	*(str + len + 1) = '\0';
	return len + 1;
}
