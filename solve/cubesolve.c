/* declaration from cubesolvePrimary.c, cubesolveCFOP.c and cubesnapshot.c */

#include "declaration.h"

void solve_down_edge(); // void CROSS();
void F2L();
void OLL();
void PLL();

void cube_create_snapshot();
void cube_recover_from_snapshot();

/* declaration end */

char planA[MAXSTEPNUM];
char planB[MAXSTEPNUM];
int planA_iend = 0;
int planB_iend = 0;

void initialize_string(char* str, int len)
{
	for (int i = 0; i != len; ++i) str[i] = '\0';
}

int count_string(char* str)
{
	int count = 0;
	for (int i = 0; str[i] != '\0'; ++i) count++;
	return count;
}

int match_string(char* str1, char* str2, int begin)
{
	int i = 0;
	for (; str2[i] != '\0'; ++i)
	{
		if (str1[begin + i] != str2[i]) return 0;
	}
	return 1;
}

int copy_string(char* str1, char* str2, int begin)
{
	int i = 0;
	for (; str2[i] != '\0'; ++i) str1[begin + i] = str2[i];
	return begin + i;
}

void write_string_and_perform(char* str)
{
	planA_iend = copy_string(planA, str, planA_iend);
	operation_analysis(str);
}

void plan_AtoB()
{
	planB_iend = planA_iend;

	// 第一轮简化：去除整体旋转
	for (int i = planB_iend; i >= 0; --i)
	{
		if (planA[i] == 'y')
		{
			planB[i] = '-';
			for (int j = i; j != planB_iend; ++j)
			{
				if (planB[j] == 'L') planB[j] = 'F';
				else if (planB[j] == 'l') planB[j] = 'f';
				else if (planB[j] == 'R') planB[j] = 'B';
				else if (planB[j] == 'r') planB[j] = 'b';
				else if (planB[j] == 'F') planB[j] = 'R';
				else if (planB[j] == 'f') planB[j] = 'r';
				else if (planB[j] == 'B') planB[j] = 'L';
				else if (planB[j] == 'b') planB[j] = 'l';
				else
					;
			}
		}
		else if (planA[i] == 'Y')
		{
			planB[i] = '-';
			for (int j = i; j != planB_iend; ++j)
			{
				if (planB[j] == 'L') planB[j] = 'B';
				else if (planB[j] == 'l') planB[j] = 'b';
				else if (planB[j] == 'R') planB[j] = 'F';
				else if (planB[j] == 'r') planB[j] = 'f';
				else if (planB[j] == 'F') planB[j] = 'L';
				else if (planB[j] == 'f') planB[j] = 'l';
				else if (planB[j] == 'B') planB[j] = 'R';
				else if (planB[j] == 'b') planB[j] = 'r';
				else
					;
			}
		}
		else if (planA[i] == 'x')
		{
			planB[i] = '-';
			for (int j = i; j != planB_iend; ++j)
			{
				if (planB[j] == 'U') planB[j] = 'F';
				else if (planB[j] == 'u') planB[j] = 'f';
				else if (planB[j] == 'D') planB[j] = 'B';
				else if (planB[j] == 'd') planB[j] = 'b';
				else if (planB[j] == 'F') planB[j] = 'D';
				else if (planB[j] == 'f') planB[j] = 'd';
				else if (planB[j] == 'B') planB[j] = 'U';
				else if (planB[j] == 'b') planB[j] = 'u';
				else
					;
			}
		}
		else if (planA[i] == 'X')
		{
			planB[i] = '-';
			for (int j = i; j != planB_iend; ++j)
			{
				if (planB[j] == 'U') planB[j] = 'B';
				else if (planB[j] == 'u') planB[j] = 'b';
				else if (planB[j] == 'D') planB[j] = 'F';
				else if (planB[j] == 'd') planB[j] = 'f';
				else if (planB[j] == 'F') planB[j] = 'U';
				else if (planB[j] == 'f') planB[j] = 'u';
				else if (planB[j] == 'B') planB[j] = 'D';
				else if (planB[j] == 'b') planB[j] = 'd';
				else
					;
			}
		}
		else if (planA[i] == 'z')
		{
			planB[i] = '-';
			for (int j = i; j != planB_iend; ++j)
			{
				if (planB[j] == 'U') planB[j] = 'L';
				else if (planB[j] == 'u') planB[j] = 'l';
				else if (planB[j] == 'D') planB[j] = 'R';
				else if (planB[j] == 'd') planB[j] = 'r';
				else if (planB[j] == 'L') planB[j] = 'D';
				else if (planB[j] == 'l') planB[j] = 'd';
				else if (planB[j] == 'R') planB[j] = 'U';
				else if (planB[j] == 'r') planB[j] = 'u';
				else
					;
			}
		}
		else if (planA[i] == 'Z')
		{
			planB[i] = '-';
			for (int j = i; j != planB_iend; ++j)
			{
				if (planB[j] == 'U') planB[j] = 'R';
				else if (planB[j] == 'u') planB[j] = 'r';
				else if (planB[j] == 'D') planB[j] = 'L';
				else if (planB[j] == 'd') planB[j] = 'l';
				else if (planB[j] == 'L') planB[j] = 'U';
				else if (planB[j] == 'l') planB[j] = 'u';
				else if (planB[j] == 'R') planB[j] = 'D';
				else if (planB[j] == 'r') planB[j] = 'd';
				else
					;
			}
		}
		else
			planB[i] = planA[i];
	}

	// 第二轮简化：检查以下情况，直到不再出现为止
	while (1)
	{
		int flag = 0;
		for (int i = planB_iend; i >= 0; --i)
		{
			if (planB[i] == '-')
			{
				for (int j = i; j < planB_iend - 1; ++j) planB[j] = planB[j + 1];
				planB[--planB_iend] = '\0';
				flag = 1;
			}
			if (i - 1 >= 0)
			{
				if (match_string(planB, "Uu", i - 1) || match_string(planB, "uU", i - 1)
					|| match_string(planB, "Dd", i - 1) || match_string(planB, "dD", i - 1)
					|| match_string(planB, "Ll", i - 1) || match_string(planB, "lL", i - 1)
					|| match_string(planB, "Rr", i - 1) || match_string(planB, "rR", i - 1)
					|| match_string(planB, "Ff", i - 1) || match_string(planB, "fF", i - 1)
					|| match_string(planB, "Bb", i - 1) || match_string(planB, "bB", i - 1))
				{
					copy_string(planB, "--", i - 1); flag = 1;
				}
			}
			if (i - 2 >= 0)
			{
				if (match_string(planB, "UUU", i - 2))
				{
					copy_string(planB, "--u", i - 2); flag = 1;
				}
				else if (match_string(planB, "uuu", i - 2))
				{
					copy_string(planB, "--U", i - 2); flag = 1;
				}
				else if (match_string(planB, "DDD", i - 2))
				{
					copy_string(planB, "--d", i - 2); flag = 1;
				}
				else if (match_string(planB, "ddd", i - 2))
				{
					copy_string(planB, "--D", i - 2); flag = 1;
				}
				else if (match_string(planB, "LLL", i - 2))
				{
					copy_string(planB, "--l", i - 2); flag = 1;
				}
				else if (match_string(planB, "lll", i - 2))
				{
					copy_string(planB, "--L", i - 2); flag = 1;
				}
				else if (match_string(planB, "RRR", i - 2))
				{
					copy_string(planB, "--r", i - 2); flag = 1;
				}
				else if (match_string(planB, "rrr", i - 2))
				{
					copy_string(planB, "--R", i - 2); flag = 1;
				}
				else if (match_string(planB, "FFF", i - 2))
				{
					copy_string(planB, "--f", i - 2); flag = 1;
				}
				else if (match_string(planB, "fff", i - 2))
				{
					copy_string(planB, "--F", i - 2); flag = 1;
				}
				else if (match_string(planB, "BBB", i - 2))
				{
					copy_string(planB, "--b", i - 2); flag = 1;
				}
				else if (match_string(planB, "bbb", i - 2))
				{
					copy_string(planB, "--B", i - 2); flag = 1;
				}
				else
					;
			}
			if (i - 3 >= 0)
			{
				if (match_string(planB, "UUUU", i - 3) || match_string(planB, "uuuu", i - 3)
					|| match_string(planB, "DDDD", i - 3) || match_string(planB, "dddd", i - 3)
					|| match_string(planB, "LLLL", i - 3) || match_string(planB, "llll", i - 3)
					|| match_string(planB, "RRRR", i - 3) || match_string(planB, "rrrr", i - 3)
					|| match_string(planB, "FFFF", i - 3) || match_string(planB, "ffff", i - 3)
					|| match_string(planB, "BBBB", i - 3) || match_string(planB, "bbbb", i - 3))
				{
					copy_string(planB, "----", i - 3); flag = 1;
				}
			}
		}
		if (flag == 0) break;
	}
}

void cube_solve()
{
	/* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */
	cube_fread();
	printf("Cube: Read successfully.\n");
	cube_printf();

	/* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */
	cube_create_snapshot();
	printf("Cube: Create snapshot successfully.\n");

	/* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */
	initialize_string(planA, MAXSTEPNUM);
	planA_iend = 0; // 重新初始化注意！

	solve_down_edge(); // CROSS();
	F2L();
	OLL();
	PLL();

	cube_printf();
	printf("str: %s\ncnt: %d\n", planA, count_string(planA));

	/* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */
	cube_recover_from_snapshot();
	printf("Cube: Recover from snapshot successfully.\n");

	/* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */
	initialize_string(planB, MAXSTEPNUM);
	planB_iend = 0; // 重新初始化注意！
	plan_AtoB();
	operation_analysis(planB);

	if (initialized_cube_verify())
	{
		printf("Error: Fail to solve with planB.\n");
		system("pause"); exit(1);
	}
	cube_printf();
	printf("Cube: Solve with planB successfully.\nstr: %s\ncnt: %d\n", planB, count_string(planB));
}
