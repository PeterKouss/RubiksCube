#include "declaration.h"

COLOR _snapshot_side_up[9];
COLOR _snapshot_side_dn[9];
COLOR _snapshot_side_lf[9];
COLOR _snapshot_side_rt[9];
COLOR _snapshot_side_fr[9];
COLOR _snapshot_side_bk[9];

void cube_create_snapshot()
{
	for (int i = 0; i != 9; ++i)
	{
		_snapshot_side_up[i] = side_up[i];
		_snapshot_side_dn[i] = side_dn[i];
		_snapshot_side_lf[i] = side_lf[i];
		_snapshot_side_rt[i] = side_rt[i];
		_snapshot_side_fr[i] = side_fr[i];
		_snapshot_side_bk[i] = side_bk[i];
	}
}

void cube_recover_from_snapshot()
{
	for (int i = 0; i != 9; ++i)
	{
		side_up[i] = _snapshot_side_up[i];
		side_dn[i] = _snapshot_side_dn[i];
		side_lf[i] = _snapshot_side_lf[i];
		side_rt[i] = _snapshot_side_rt[i];
		side_fr[i] = _snapshot_side_fr[i];
		side_bk[i] = _snapshot_side_bk[i];
	}
}
