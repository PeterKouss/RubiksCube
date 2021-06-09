/* declaration from cubesolve.c */

#include "declaration.h"

void write_string_and_perform(char* str);

/* declaration end */

void solve_down_edge()
{
	for (int i = 0; i != 4; ++i)
	{
		COLOR dn = side_dn[4];
		COLOR fr = side_fr[4];

		if (side_dn[1] == dn && side_fr[7] == fr);
		else if (side_dn[1] == fr && side_fr[7] == dn) write_string_and_perform("fDrd");
		else if (side_dn[3] == dn && side_lf[7] == fr) write_string_and_perform("LLuFF");
		else if (side_dn[3] == fr && side_lf[7] == dn) write_string_and_perform("lf");
		else if (side_dn[5] == dn && side_rt[7] == fr) write_string_and_perform("rrUFF");
		else if (side_dn[5] == fr && side_rt[7] == dn) write_string_and_perform("RF");
		else if (side_dn[7] == dn && side_bk[7] == fr) write_string_and_perform("BBUUFF");
		else if (side_dn[7] == fr && side_bk[7] == dn) write_string_and_perform("BBUrFR");

		else if (side_up[1] == dn && side_bk[1] == fr) write_string_and_perform("UUFF");
		else if (side_up[1] == fr && side_bk[1] == dn) write_string_and_perform("UrFR");
		else if (side_up[3] == dn && side_lf[1] == fr) write_string_and_perform("uFF");
		else if (side_up[3] == fr && side_lf[1] == dn) write_string_and_perform("Lfl");
		else if (side_up[5] == dn && side_rt[1] == fr) write_string_and_perform("UFF");
		else if (side_up[5] == fr && side_rt[1] == dn) write_string_and_perform("rFR");
		else if (side_up[7] == dn && side_fr[1] == fr) write_string_and_perform("FF");
		else if (side_up[7] == fr && side_fr[1] == dn) write_string_and_perform("urFR");

		else if (side_fr[5] == dn && side_rt[3] == fr) write_string_and_perform("Drd");
		else if (side_fr[5] == fr && side_rt[3] == dn) write_string_and_perform("F");
		else if (side_rt[5] == dn && side_bk[3] == fr) write_string_and_perform("DDbDD");
		else if (side_rt[5] == fr && side_bk[3] == dn) write_string_and_perform("DRd");
		else if (side_bk[5] == dn && side_lf[3] == fr) write_string_and_perform("dlD");
		else if (side_bk[5] == fr && side_lf[3] == dn) write_string_and_perform("DDBDD");
		else if (side_lf[5] == dn && side_fr[3] == fr) write_string_and_perform("f");
		else if (side_lf[5] == fr && side_fr[3] == dn) write_string_and_perform("dLD");

		else
			ERRORPRINT("Error: Fail to perform solve_down_edge().\n")
			write_string_and_perform("y");
	}
}
