/* declaration from cubesolve.c */

#include "declaration.h"

void write_string_and_perform(char* str);

/* declaration end */

void CROSS()
{

}

void F2L()
{
	write_string_and_perform("-");

	int i = 0;
	for (; i != 4; ++i)
	{
		COLOR dn = side_dn[4];
		COLOR fr = side_fr[4];
		COLOR rt = side_rt[4];

		// 角块预处理
		if (side_rt[8] == fr && side_bk[6] == rt && side_dn[8] == dn
			|| side_rt[8] == dn && side_bk[6] == fr && side_dn[8] == rt
			|| side_rt[8] == rt && side_bk[6] == dn && side_dn[8] == fr)
		{
			// 保护
			if (side_lf[1] == fr && side_up[3] == rt || side_lf[1] == rt && side_up[3] == fr) write_string_and_perform("U");
			write_string_and_perform("BUb");
		}
		else if (side_bk[8] == fr && side_lf[6] == rt && side_dn[6] == dn
			|| side_bk[8] == dn && side_lf[6] == fr && side_dn[6] == rt
			|| side_bk[8] == rt && side_lf[6] == dn && side_dn[6] == fr)
		{
			// 保护
			if (side_rt[1] == fr && side_up[5] == rt || side_rt[1] == rt && side_up[5] == fr) write_string_and_perform("U");
			write_string_and_perform("LUUl");
		}
		else if (side_lf[8] == fr && side_fr[6] == rt && side_dn[0] == dn
			|| side_lf[8] == dn && side_fr[6] == fr && side_dn[0] == rt
			|| side_lf[8] == rt && side_fr[6] == dn && side_dn[0] == fr)
		{
			// 保护
			if (side_bk[1] == fr && side_up[1] == rt || side_bk[1] == rt && side_up[1] == fr) write_string_and_perform("U");
			write_string_and_perform("luL");
		}
		else if (side_bk[0] == fr && side_rt[2] == rt && side_up[2] == dn
			|| side_bk[0] == dn && side_rt[2] == fr && side_up[2] == rt
			|| side_bk[0] == rt && side_rt[2] == dn && side_up[2] == fr)
		{
			write_string_and_perform("U");
		}
		else if (side_lf[0] == fr && side_bk[2] == rt && side_up[0] == dn
			|| side_lf[0] == dn && side_bk[2] == fr && side_up[0] == rt
			|| side_lf[0] == rt && side_bk[2] == dn && side_up[0] == fr)
		{
			write_string_and_perform("UU");
		}
		else if (side_fr[0] == fr && side_lf[2] == rt && side_up[6] == dn
			|| side_fr[0] == dn && side_lf[2] == fr && side_up[6] == rt
			|| side_fr[0] == rt && side_lf[2] == dn && side_up[6] == fr)
		{
			write_string_and_perform("u");
		}
		else
			;

		// 二层棱块预处理
		if (side_rt[5] == fr && side_bk[3] == rt
			|| side_rt[5] == rt && side_bk[3] == fr)
			write_string_and_perform("BUbu");
		else if (side_bk[5] == fr && side_lf[3] == rt
			|| side_bk[5] == rt && side_lf[3] == fr)
			write_string_and_perform("LulU");
		else if (side_lf[5] == fr && side_fr[3] == rt
			|| side_lf[5] == rt && side_fr[3] == fr)
			write_string_and_perform("luLU");
		else
			;

		// 顶层棱块预处理
		if (side_fr[8] == fr && side_rt[6] == rt && side_dn[2] == dn
			|| side_fr[8] == dn && side_rt[6] == fr && side_dn[2] == rt
			|| side_fr[8] == rt && side_rt[6] == dn && side_dn[2] == fr)
		{
			if (side_lf[1] == fr && side_up[3] == rt)
				write_string_and_perform("u");
			else if (side_bk[1] == fr && side_up[1] == rt)
				write_string_and_perform("UU");
			else if (side_rt[1] == fr && side_up[5] == rt)
				write_string_and_perform("U");
			else if (side_fr[1] == rt && side_up[7] == fr)
				write_string_and_perform("u");
			else if (side_lf[1] == rt && side_up[3] == fr)
				write_string_and_perform("UU");
			else if (side_bk[1] == rt && side_up[1] == fr)
				write_string_and_perform("U");
			else
				;
		}
		else
			;

		// F2L
		if (side_fr[8] == fr && side_rt[6] == rt && side_dn[2] == dn)
		{
			if (side_fr[5] == fr && side_rt[3] == rt);
			else if (side_fr[5] == rt && side_rt[3] == fr) write_string_and_perform("RUUrURUUrUfuF"); // 1
			else if (side_fr[1] == fr && side_up[7] == rt) write_string_and_perform("URurufUF"); // 2
			else if (side_rt[1] == rt && side_up[5] == fr) write_string_and_perform("ufUFURur"); // 3
			else
				ERRORPRINT("Error: Fail to perform F2L (1-3).\n")
		}
		else if (side_fr[8] == dn && side_rt[6] == fr && side_dn[2] == rt)
		{
			if (side_fr[5] == fr && side_rt[3] == rt) write_string_and_perform("RUruRUUruRUr"); // 4
			else if (side_fr[5] == rt && side_rt[3] == fr) write_string_and_perform("RFURurfur"); // 5
			else if (side_fr[1] == fr && side_up[7] == rt) write_string_and_perform("fuFUfuF"); // 6
			else if (side_rt[1] == rt && side_up[5] == fr) write_string_and_perform("RurURur"); // 7
			else
				ERRORPRINT("Error: Fail to perform F2L (4-7).\n")
		}
		else if (side_fr[8] == rt && side_rt[6] == dn && side_dn[2] == fr)
		{
			if (side_fr[5] == fr && side_rt[3] == rt) write_string_and_perform("RurURUUrURur"); // 8
			else if (side_fr[5] == rt && side_rt[3] == fr) write_string_and_perform("RUFRUrufr"); // 9
			else if (side_fr[1] == fr && side_up[7] == rt) write_string_and_perform("fUFufUF"); // 10
			else if (side_rt[1] == rt && side_up[5] == fr) write_string_and_perform("RUruRUr"); // 11
			else
				ERRORPRINT("Error: Fail to perform F2L (8-11).\n")
		}
		else if (side_rt[0] == fr && side_fr[2] == rt && side_up[8] == dn)
		{
			if (side_fr[5] == fr && side_rt[3] == rt) write_string_and_perform("RUruRUruRUr"); // 12
			else if (side_fr[5] == rt && side_rt[3] == fr) write_string_and_perform("RurfUUF"); // 13
			else if (side_fr[1] == fr && side_up[7] == rt) write_string_and_perform("fUUFUfuF"); // 14
			else if (side_lf[1] == fr && side_up[3] == rt) write_string_and_perform("ufUUFufUF"); // 15
			else if (side_bk[1] == fr && side_up[1] == rt) write_string_and_perform("fUFUUfuF"); // 16
			else if (side_rt[1] == fr && side_up[5] == rt) write_string_and_perform("FURurfRur"); // 17
			else if (side_fr[1] == rt && side_up[7] == fr) write_string_and_perform("RUrUURUruRUr"); // 18
			else if (side_lf[1] == rt && side_up[3] == fr) write_string_and_perform("RurUURUr"); // 19
			else if (side_bk[1] == rt && side_up[1] == fr) write_string_and_perform("URUUrURur"); // 20
			else if (side_rt[1] == rt && side_up[5] == fr) write_string_and_perform("RUUruRUr"); // 21
			else
				ERRORPRINT("Error: Fail to perform F2L (12-21).\n")
		}
		else if (side_rt[0] == rt && side_fr[2] == dn && side_up[8] == fr)
		{
			if (side_fr[5] == fr && side_rt[3] == rt) write_string_and_perform("uRurUURur"); // 22
			else if (side_fr[5] == rt && side_rt[3] == fr) write_string_and_perform("uRUrUfuF"); // 23
			else if (side_fr[1] == fr && side_up[7] == rt) write_string_and_perform("UfUFufuF"); // 24
			else if (side_lf[1] == fr && side_up[3] == rt) write_string_and_perform("fuF"); // 25
			else if (side_bk[1] == fr && side_up[1] == rt) write_string_and_perform("UfuFufuF"); // 26
			else if (side_rt[1] == fr && side_up[5] == rt) write_string_and_perform("uRUUrUfuF"); // 27
			else if (side_fr[1] == rt && side_up[7] == fr) write_string_and_perform("UrFRfURUr"); // 28
			else if (side_lf[1] == rt && side_up[3] == fr) write_string_and_perform("uRUUrUURur"); // 29
			else if (side_bk[1] == rt && side_up[1] == fr) write_string_and_perform("uRUruRUUr"); // 30
			else if (side_rt[1] == rt && side_up[5] == fr) write_string_and_perform("URur"); // 31
			else
				ERRORPRINT("Error: Fail to perform F2L (22-31).\n")
		}
		else if (side_rt[0] == dn && side_fr[2] == fr && side_up[8] == rt)
		{
			if (side_fr[5] == fr && side_rt[3] == rt) write_string_and_perform("uRUUrURUr"); // 32
			else if (side_fr[5] == rt && side_rt[3] == fr) write_string_and_perform("UfuFuRUr"); // 33
			else if (side_fr[1] == fr && side_up[7] == rt) write_string_and_perform("ufUF"); // 34
			else if (side_lf[1] == fr && side_up[3] == rt) write_string_and_perform("UfuFUUfUF"); // 35
			else if (side_bk[1] == fr && side_up[1] == rt) write_string_and_perform("UfUUFUUfUF"); // 36
			else if (side_rt[1] == fr && side_up[5] == rt) write_string_and_perform("RurUUfuF"); // 37
			else if (side_fr[1] == rt && side_up[7] == fr) write_string_and_perform("RurURurUURur"); // 38
			else if (side_lf[1] == rt && side_up[3] == fr) write_string_and_perform("uRUrURUr"); // 39
			else if (side_bk[1] == rt && side_up[1] == fr) write_string_and_perform("RUr"); // 40
			else if (side_rt[1] == rt && side_up[5] == fr) write_string_and_perform("uRurURUr"); // 41
			else
				ERRORPRINT("Error: Fail to perform F2L (32-41).\n")
		}
		else
			ERRORPRINT("Error: Fail to perform F2L.\n")
			write_string_and_perform("y");
	}
}

void OLL()
{
	write_string_and_perform("-");

	int i = 0;
	for (; i != 4; ++i)
	{
		COLOR up = side_up[4];

		if (side_up[0] == up && side_up[1] == up && side_up[2] == up && side_up[3] == up
			&& side_up[5] == up && side_up[6] == up && side_up[7] == up && side_up[8] == up)
			break; // 0
		else if (side_lf[0] == up && side_lf[1] == up && side_lf[2] == up && side_fr[1] == up
			&& side_rt[0] == up && side_rt[1] == up && side_rt[2] == up && side_bk[1] == up)
			write_string_and_perform("RUURRFRfUUrFRf"); // 1
		else if (side_lf[0] == up && side_lf[1] == up && side_lf[2] == up && side_fr[1] == up
			&& side_fr[2] == up && side_rt[1] == up && side_bk[0] == up && side_bk[1] == up)
			write_string_and_perform("FRUrufBULulb"); // 2
		else if (side_up[8] == up && side_lf[1] == up && side_lf[2] == up && side_fr[1] == up
			&& side_rt[1] == up && side_rt[2] == up && side_bk[1] == up && side_bk[2] == up)
			write_string_and_perform("BULulbuFRUruf"); // 3
		else if (side_up[2] == up && side_lf[0] == up && side_lf[1] == up && side_fr[0] == up
			&& side_fr[1] == up && side_rt[0] == up && side_rt[1] == up && side_bk[1] == up)
			write_string_and_perform("BULulbRBUbur"); // 4
		else if (side_up[5] == up && side_up[7] == up && side_up[8] == up && side_lf[1] == up
			&& side_lf[2] == up && side_rt[2] == up && side_bk[1] == up && side_bk[2] == up)
			write_string_and_perform("lBBRBrBL"); // 5
		else if (side_up[1] == up && side_up[2] == up && side_up[5] == up && side_lf[0] == up
			&& side_lf[1] == up && side_fr[0] == up && side_fr[1] == up && side_rt[0] == up)
			write_string_and_perform("LFFrfRfl"); // 6
		else if (side_up[1] == up && side_up[3] == up && side_up[6] == up && side_fr[1] == up
			&& side_fr[2] == up && side_rt[1] == up && side_rt[2] == up && side_bk[2] == up)
			write_string_and_perform("LFrFRFFl"); // 7
		else if (side_up[0] == up && side_up[3] == up && side_up[7] == up && side_fr[0] == up
			&& side_rt[0] == up && side_rt[1] == up && side_bk[0] == up && side_bk[1] == up)
			write_string_and_perform("lbRbrBBL"); // 8
		else if (side_up[1] == up && side_up[3] == up && side_up[8] == up && side_lf[0] == up
			&& side_fr[0] == up && side_fr[1] == up && side_rt[1] == up && side_bk[0] == up)
			write_string_and_perform("ruRFrfUFRf"); // 9
		else if (side_up[2] == up && side_up[3] == up && side_up[7] == up && side_lf[2] == up
			&& side_fr[2] == up && side_rt[1] == up && side_bk[1] == up && side_bk[2] == up)
			write_string_and_perform("RUrUrFRfRUUr"); // 10

		else if (side_up[5] == up && side_up[6] == up && side_up[7] == up && side_lf[1] == up
			&& side_fr[2] == up && side_rt[2] == up && side_bk[1] == up && side_bk[2] == up)
			write_string_and_perform("lRRBrBRBBrBLr"); // 11
		else if (side_up[0] == up && side_up[1] == up && side_up[5] == up && side_lf[1] == up
			&& side_fr[0] == up && side_fr[1] == up && side_rt[0] == up && side_bk[0] == up)
			write_string_and_perform("LRRfRfrFFRfRl"); // 12
		else if (side_up[3] == up && side_up[5] == up && side_up[6] == up && side_fr[1] == up
			&& side_fr[2] == up && side_rt[2] == up && side_bk[1] == up && side_bk[2] == up)
			write_string_and_perform("LfluLFlfUF"); // 13
		else if (side_up[3] == up && side_up[5] == up && side_up[8] == up && side_lf[0] == up
			&& side_fr[0] == up && side_fr[1] == up && side_bk[0] == up && side_bk[1] == up)
			write_string_and_perform("rFRUrfRFuf"); // 14
		else if (side_up[3] == up && side_up[5] == up && side_up[8] == up && side_lf[2] == up
			&& side_fr[1] == up && side_rt[2] == up && side_bk[1] == up && side_bk[2] == up)
			write_string_and_perform("lbLruRUlBL"); // 15
		else if (side_up[2] == up && side_up[3] == up && side_up[5] == up && side_lf[0] == up
			&& side_fr[0] == up && side_fr[1] == up && side_rt[0] == up && side_bk[1] == up)
			write_string_and_perform("LFlRUruLfl"); // 16
		else if (side_up[0] == up && side_up[8] == up && side_lf[1] == up && side_fr[0] == up
			&& side_fr[1] == up && side_rt[1] == up && side_rt[2] == up && side_bk[1] == up)
			write_string_and_perform("FUrufUFRRUruf"); // 17
		else if (side_up[6] == up && side_up[8] == up && side_lf[1] == up && side_fr[1] == up
			&& side_rt[1] == up && side_bk[0] == up && side_bk[1] == up && side_bk[2] == up)
			write_string_and_perform("FRUrUfUUfLFl"); // 18
		else if (side_up[0] == up && side_up[2] == up && side_lf[1] == up && side_lf[2] == up
			&& side_fr[1] == up && side_rt[0] == up && side_rt[1] == up && side_bk[1] == up)
			write_string_and_perform("lRBRBrbLRRFRf"); // 19
		else if (side_up[0] == up && side_up[2] == up && side_up[6] == up && side_up[8] == up
			&& side_lf[1] == up && side_fr[1] == up && side_rt[1] == up && side_bk[1] == up)
			write_string_and_perform("lRBRBrbLLRRFRfl"); // 20
		else if (side_up[1] == up && side_up[3] == up && side_up[5] == up && side_up[7] == up
			&& side_fr[0] == up && side_fr[2] == up && side_bk[0] == up && side_bk[2] == up)
			write_string_and_perform("RUUruRUruRur"); // 21
		else if (side_up[1] == up && side_up[3] == up && side_up[5] == up && side_up[7] == up
			&& side_lf[0] == up && side_lf[2] == up && side_fr[2] == up && side_bk[0] == up)
			write_string_and_perform("RUURRuRRuRRUUR"); // 22

		else if (side_up[1] == up && side_up[3] == up && side_up[5] == up && side_up[6] == up
			&& side_up[7] == up && side_up[8] == up && side_bk[0] == up && side_bk[2] == up)
			write_string_and_perform("RRdRUUrDRUUR"); // 23
		else if (side_up[1] == up && side_up[2] == up && side_up[3] == up && side_up[5] == up
			&& side_up[7] == up && side_up[8] == up && side_fr[0] == up && side_bk[2] == up)
			write_string_and_perform("LFrflFRf"); // 24
		else if (side_up[1] == up && side_up[2] == up && side_up[3] == up && side_up[5] == up
			&& side_up[6] == up && side_up[7] == up && side_lf[0] == up && side_fr[2] == up)
			write_string_and_perform("fLFrflFR"); // 25
		else if (side_up[1] == up && side_up[2] == up && side_up[3] == up && side_up[5] == up
			&& side_up[7] == up && side_lf[0] == up && side_fr[0] == up && side_rt[0] == up)
			write_string_and_perform("RUUruRur"); // 26
		else if (side_up[1] == up && side_up[3] == up && side_up[5] == up && side_up[7] == up
			&& side_up[8] == up && side_lf[2] == up && side_rt[2] == up && side_bk[2] == up)
			write_string_and_perform("rUURUrUR"); // 27
		else if (side_up[0] == up && side_up[1] == up && side_up[2] == up && side_up[3] == up
			&& side_up[6] == up && side_up[8] == up && side_fr[1] == up && side_rt[1] == up)
			write_string_and_perform("LFrflRURur"); // 28
		else if (side_up[1] == up && side_up[2] == up && side_up[3] == up && side_up[8] == up
			&& side_fr[0] == up && side_fr[1] == up && side_rt[1] == up && side_bk[2] == up)
			write_string_and_perform("LFrfRLLURuLr"); // 29
		else if (side_up[0] == up && side_up[2] == up && side_up[5] == up && side_up[7] == up
			&& side_lf[1] == up && side_lf[2] == up && side_rt[0] == up && side_bk[1] == up)
			write_string_and_perform("RRUrbRuRRURBr"); // 30
		else if (side_up[0] == up && side_up[3] == up && side_up[6] == up && side_up[7] == up
			&& side_fr[2] == up && side_rt[1] == up && side_bk[0] == up && side_bk[1] == up)
			write_string_and_perform("luBULulbL"); // 31
		else if (side_up[2] == up && side_up[5] == up && side_up[7] == up && side_up[8] == up
			&& side_lf[1] == up && side_fr[0] == up && side_bk[1] == up && side_bk[2] == up)
			write_string_and_perform("RUburURBr"); // 32
		else if (side_up[2] == up && side_up[3] == up && side_up[5] == up && side_up[8] == up
			&& side_fr[0] == up && side_fr[1] == up && side_bk[1] == up && side_bk[2] == up)
			write_string_and_perform("RUrurFRf"); // 33
		else if (side_up[0] == up && side_up[2] == up && side_up[3] == up && side_up[5] == up
			&& side_lf[2] == up && side_fr[1] == up && side_rt[0] == up && side_bk[1] == up)
			write_string_and_perform("ruRUFRbrfB"); // 34

		else if (side_up[0] == up && side_up[5] == up && side_up[7] == up && side_up[8] == up
			&& side_lf[1] == up && side_fr[0] == up && side_rt[2] == up && side_bk[1] == up)
			write_string_and_perform("RUURRFRfRUUr"); // 35
		else if (side_up[0] == up && side_up[3] == up && side_up[7] == up && side_up[8] == up
			&& side_fr[0] == up && side_rt[1] == up && side_rt[2] == up && side_bk[1] == up)
			write_string_and_perform("ruRurURURbrB"); // 36
		else if (side_up[0] == up && side_up[1] == up && side_up[3] == up && side_up[8] == up
			&& side_fr[0] == up && side_fr[1] == up && side_rt[1] == up && side_rt[2] == up)
			write_string_and_perform("FRuruRUrf"); // 37
		else if (side_up[1] == up && side_up[2] == up && side_up[3] == up && side_up[6] == up
			&& side_fr[1] == up && side_rt[0] == up && side_rt[1] == up && side_bk[2] == up)
			write_string_and_perform("RUrURururFRf"); // 38
		else if (side_up[2] == up && side_up[3] == up && side_up[5] == up && side_up[6] == up
			&& side_fr[1] == up && side_rt[0] == up && side_bk[1] == up && side_bk[2] == up)
			write_string_and_perform("LfluLUFul"); // 39
		else if (side_up[0] == up && side_up[3] == up && side_up[5] == up && side_up[8] == up
			&& side_lf[2] == up && side_fr[1] == up && side_bk[0] == up && side_bk[1] == up)
			write_string_and_perform("rFRUrufUR"); // 40
		else if (side_up[0] == up && side_up[2] == up && side_up[5] == up && side_up[7] == up
			&& side_lf[1] == up && side_fr[0] == up && side_fr[2] == up && side_bk[1] == up)
			write_string_and_perform("RurUURUBubur"); // 41
		else if (side_up[1] == up && side_up[5] == up && side_up[6] == up && side_up[8] == up
			&& side_lf[1] == up && side_fr[1] == up && side_bk[0] == up && side_bk[2] == up)
			write_string_and_perform("rURUUrufUFUR"); // 42
		else if (side_up[0] == up && side_up[3] == up && side_up[6] == up && side_up[7] == up
			&& side_rt[0] == up && side_rt[1] == up && side_rt[2] == up && side_bk[1] == up)
			write_string_and_perform("burURB"); // 43
		else if (side_up[2] == up && side_up[5] == up && side_up[7] == up && side_up[8] == up
			&& side_lf[0] == up && side_lf[1] == up && side_lf[2] == up && side_bk[1] == up)
			write_string_and_perform("BULulb"); // 44
		else if (side_up[2] == up && side_up[3] == up && side_up[5] == up && side_up[8] == up
			&& side_lf[0] == up && side_lf[2] == up && side_fr[1] == up && side_bk[1] == up)
			write_string_and_perform("FRUruf"); // 45
		else if (side_up[0] == up && side_up[1] == up && side_up[6] == up && side_up[7] == up
			&& side_lf[1] == up && side_rt[0] == up && side_rt[1] == up && side_rt[2] == up)
			write_string_and_perform("rurFRfUR"); // 46

		else if (side_up[3] == up && side_up[7] == up && side_lf[0] == up && side_lf[2] == up
			&& side_fr[2] == up && side_rt[1] == up && side_bk[0] == up && side_bk[1] == up)
			write_string_and_perform("bruRUruRUB"); // 47
		else if (side_up[1] == up && side_up[3] == up && side_lf[0] == up && side_lf[2] == up
			&& side_fr[1] == up && side_fr[2] == up && side_rt[1] == up && side_bk[0] == up)
			write_string_and_perform("FRUruRUruf"); // 48
		else if (side_up[3] == up && side_up[7] == up && side_fr[0] == up && side_rt[0] == up
			&& side_rt[1] == up && side_rt[2] == up && side_bk[1] == up && side_bk[2] == up)
			write_string_and_perform("RbRRFRRBRRfR"); // 49
		else if (side_up[5] == up && side_up[7] == up && side_lf[0] == up && side_lf[1] == up
			&& side_lf[2] == up && side_fr[2] == up && side_bk[0] == up && side_bk[1] == up)
			write_string_and_perform("lBLLfLLbLLFl"); // 50
		else if (side_up[3] == up && side_up[5] == up && side_lf[0] == up && side_lf[2] == up
			&& side_fr[1] == up && side_fr[2] == up && side_bk[0] == up && side_bk[1] == up)
			write_string_and_perform("BULulULulb"); // 51
		else if (side_up[1] == up && side_up[7] == up && side_lf[1] == up && side_fr[0] == up
			&& side_rt[0] == up && side_rt[1] == up && side_rt[2] == up && side_bk[2] == up)
			write_string_and_perform("ruRurUfUFR"); // 52
		else if (side_up[3] == up && side_up[7] == up && side_fr[0] == up && side_fr[2] == up
			&& side_rt[1] == up && side_bk[0] == up && side_bk[1] == up && side_bk[2] == up)
			write_string_and_perform("lBBRBrbRBrBL"); // 53
		else if (side_up[1] == up && side_up[3] == up && side_fr[0] == up && side_fr[1] == up
			&& side_fr[2] == up && side_rt[1] == up && side_bk[0] == up && side_bk[2] == up)
			write_string_and_perform("LFFrfRFrfRfl"); // 54
		else if (side_up[1] == up && side_up[7] == up && side_lf[0] == up && side_lf[1] == up
			&& side_lf[2] == up && side_rt[0] == up && side_rt[1] == up && side_rt[2] == up)
			write_string_and_perform("RUURRuRurUUFRf"); // 55
		else if (side_up[3] == up && side_up[5] == up && side_lf[0] == up && side_lf[2] == up
			&& side_fr[1] == up && side_rt[0] == up && side_rt[2] == up && side_bk[1] == up)
			write_string_and_perform("FRUruRfLFrfl"); // 56
		else if (side_up[0] == up && side_up[2] == up && side_up[3] == up && side_up[5] == up
			&& side_up[6] == up && side_up[8] == up && side_fr[1] == up && side_bk[1] == up)
			write_string_and_perform("RUruLrFRfl"); // 57
		else
		{
			write_string_and_perform("y");
			continue;
		}
		break;
	}
	if (i == 4) ERRORPRINT("Error: Fail to perform OLL.\n")
}

void PLL()
{
	write_string_and_perform("-");

	int i = 0;
	for (; i != 4; ++i)
	{
		int j = 0;
		for (; j != 4; ++j)
		{
			COLOR lf = side_lf[4];
			COLOR fr = side_fr[4];
			COLOR rt = side_rt[4];
			COLOR bk = side_bk[4];

			if (side_lf[0] == lf && side_lf[1] == lf && side_lf[2] == lf && side_fr[0] == fr && side_fr[1] == fr && side_fr[2] == fr
				&& side_rt[0] == rt && side_rt[1] == rt && side_rt[2] == rt && side_bk[0] == bk && side_bk[1] == bk && side_bk[2] == bk)
				break; // 0
			else if (side_lf[0] == lf && side_lf[1] == fr && side_lf[2] == lf && side_fr[0] == fr && side_fr[1] == rt && side_fr[2] == fr
				&& side_rt[0] == rt && side_rt[1] == lf && side_rt[2] == rt && side_bk[0] == bk && side_bk[1] == bk && side_bk[2] == bk)
				write_string_and_perform("RuRURURuruRR"); // 1
			else if (side_lf[0] == lf && side_lf[1] == rt && side_lf[2] == lf && side_fr[0] == fr && side_fr[1] == lf && side_fr[2] == fr
				&& side_rt[0] == rt && side_rt[1] == fr && side_rt[2] == rt && side_bk[0] == bk && side_bk[1] == bk && side_bk[2] == bk)
				write_string_and_perform("RRURUrururUr"); // 2
			else if (side_lf[0] == lf && side_lf[1] == rt && side_lf[2] == lf && side_fr[0] == fr && side_fr[1] == bk && side_fr[2] == fr
				&& side_rt[0] == rt && side_rt[1] == lf && side_rt[2] == rt && side_bk[0] == bk && side_bk[1] == fr && side_bk[2] == bk)
				write_string_and_perform("LLRRDLLRRUULLRRDLLRR"); // 3
			else if (side_lf[0] == lf && side_lf[1] == bk && side_lf[2] == lf && side_fr[0] == fr && side_fr[1] == rt && side_fr[2] == fr
				&& side_rt[0] == rt && side_rt[1] == fr && side_rt[2] == rt && side_bk[0] == bk && side_bk[1] == lf && side_bk[2] == bk)
				write_string_and_perform("UruRuRURurURURRurU"); // 4
			else if (side_lf[0] == lf && side_lf[1] == lf && side_lf[2] == rt && side_fr[0] == bk && side_fr[1] == fr && side_fr[2] == lf
				&& side_rt[0] == fr && side_rt[1] == rt && side_rt[2] == fr && side_bk[0] == rt && side_bk[1] == bk && side_bk[2] == bk)
				write_string_and_perform("RRFFrbRFFrBr"); // 5
			else if (side_lf[0] == lf && side_lf[1] == lf && side_lf[2] == fr && side_fr[0] == rt && side_fr[1] == fr && side_fr[2] == rt
				&& side_rt[0] == bk && side_rt[1] == rt && side_rt[2] == lf && side_bk[0] == fr && side_bk[1] == bk && side_bk[2] == bk)
				write_string_and_perform("RbRFFrBRFFRR"); // 6
			else if (side_lf[0] == fr && side_lf[1] == lf && side_lf[2] == bk && side_fr[0] == lf && side_fr[1] == fr && side_fr[2] == rt
				&& side_rt[0] == bk && side_rt[1] == rt && side_rt[2] == fr && side_bk[0] == rt && side_bk[1] == bk && side_bk[2] == lf)
				write_string_and_perform("RbrFRBrFFlBLFlbL"); // 7
			else if (side_lf[0] == lf && side_lf[1] == rt && side_lf[2] == lf && side_fr[0] == fr && side_fr[1] == fr && side_fr[2] == rt
				&& side_rt[0] == bk && side_rt[1] == lf && side_rt[2] == fr && side_bk[0] == rt && side_bk[1] == bk && side_bk[2] == bk)
				write_string_and_perform("RUrurFRRuruRUrf"); // 8
			else if (side_lf[0] == lf && side_lf[1] == lf && side_lf[2] == lf && side_fr[0] == fr && side_fr[1] == bk && side_fr[2] == rt
				&& side_rt[0] == bk && side_rt[1] == rt && side_rt[2] == fr && side_bk[0] == rt && side_bk[1] == fr && side_bk[2] == bk)
				write_string_and_perform("urURuRRfuFURFrfRR"); // 9
			else if (side_lf[0] == rt && side_lf[1] == lf && side_lf[2] == lf && side_fr[0] == fr && side_fr[1] == fr && side_fr[2] == bk
				&& side_rt[0] == lf && side_rt[1] == bk && side_rt[2] == rt && side_bk[0] == bk && side_bk[1] == rt && side_bk[2] == fr)
				write_string_and_perform("rUrubDbdBBrbRBR"); // 10
			else if (side_lf[0] == rt && side_lf[1] == bk && side_lf[2] == lf && side_fr[0] == fr && side_fr[1] == fr && side_fr[2] == bk
				&& side_rt[0] == lf && side_rt[1] == rt && side_rt[2] == rt && side_bk[0] == bk && side_bk[1] == lf && side_bk[2] == fr)
				write_string_and_perform("FRuruRUrfRUrurFRf"); // 11
			else if (side_lf[0] == lf && side_lf[1] == lf && side_lf[2] == fr && side_fr[0] == rt && side_fr[1] == rt && side_fr[2] == lf
				&& side_rt[0] == fr && side_rt[1] == fr && side_rt[2] == rt && side_bk[0] == bk && side_bk[1] == bk && side_bk[2] == bk)
				write_string_and_perform("lUrUULulUULRu"); // 12
			else if (side_lf[0] == lf && side_lf[1] == lf && side_lf[2] == lf && side_fr[0] == fr && side_fr[1] == rt && side_fr[2] == rt
				&& side_rt[0] == bk && side_rt[1] == fr && side_rt[2] == fr && side_bk[0] == rt && side_bk[1] == bk && side_bk[2] == bk)
				write_string_and_perform("RUrfRUrurFRRuru"); // 13
			else if (side_lf[0] == bk && side_lf[1] == lf && side_lf[2] == lf && side_fr[0] == fr && side_fr[1] == rt && side_fr[2] == fr
				&& side_rt[0] == rt && side_rt[1] == fr && side_rt[2] == bk && side_bk[0] == lf && side_bk[1] == bk && side_bk[2] == rt)
				write_string_and_perform("rUURUUrFRUrurfRRu"); // 14
			else if (side_lf[0] == lf && side_lf[1] == lf && side_lf[2] == fr && side_fr[0] == rt && side_fr[1] == fr && side_fr[2] == lf
				&& side_rt[0] == fr && side_rt[1] == bk && side_rt[2] == rt && side_bk[0] == bk && side_bk[1] == rt && side_bk[2] == bk)
				write_string_and_perform("RUUrUURbruRURBRRU"); // 15
			else if (side_lf[0] == fr && side_lf[1] == rt && side_lf[2] == fr && side_fr[0] == rt && side_fr[1] == lf && side_fr[2] == bk
				&& side_rt[0] == lf && side_rt[1] == fr && side_rt[2] == rt && side_bk[0] == bk && side_bk[1] == bk && side_bk[2] == lf)
				write_string_and_perform("RRdFuFUfDRRBub"); // 16
			else if (side_lf[0] == bk && side_lf[1] == fr && side_lf[2] == bk && side_fr[0] == lf && side_fr[1] == bk && side_fr[2] == fr
				&& side_rt[0] == rt && side_rt[1] == rt && side_rt[2] == lf && side_bk[0] == fr && side_bk[1] == lf && side_bk[2] == rt)
				write_string_and_perform("RUrFFdLulUlDFF"); // 17
			else if (side_lf[0] == bk && side_lf[1] == rt && side_lf[2] == bk && side_fr[0] == lf && side_fr[1] == fr && side_fr[2] == fr
				&& side_rt[0] == rt && side_rt[1] == bk && side_rt[2] == lf && side_bk[0] == fr && side_bk[1] == lf && side_bk[2] == rt)
				write_string_and_perform("RRDbUbuBdRRfUF"); // 18
			else if (side_lf[0] == fr && side_lf[1] == bk && side_lf[2] == fr && side_fr[0] == rt && side_fr[1] == lf && side_fr[2] == bk
				&& side_rt[0] == lf && side_rt[1] == rt && side_rt[2] == rt && side_bk[0] == bk && side_bk[1] == fr && side_bk[2] == lf)
				write_string_and_perform("ruRBBDlULuLdBB"); // 19
			else if (side_lf[0] == rt && side_lf[1] == lf && side_lf[2] == lf && side_fr[0] == fr && side_fr[1] == bk && side_fr[2] == bk
				&& side_rt[0] == lf && side_rt[1] == rt && side_rt[2] == rt && side_bk[0] == bk && side_bk[1] == fr && side_bk[2] == fr)
				write_string_and_perform("uLuRUUlUrLuRUUlUr"); // 20
			else if (side_lf[0] == lf && side_lf[1] == lf && side_lf[2] == rt && side_fr[0] == bk && side_fr[1] == bk && side_fr[2] == fr
				&& side_rt[0] == rt && side_rt[1] == rt && side_rt[2] == lf && side_bk[0] == fr && side_bk[1] == fr && side_bk[2] == bk)
				write_string_and_perform("lUrUULulRUrUULuRu"); // 21
			else
			{
				write_string_and_perform("y");
				continue;
			}
			break;
		}
		if (j == 4) write_string_and_perform("U");
		else break;
	}
	if (i == 4) ERRORPRINT("Error: Fail to perform PLL.\n")
}
