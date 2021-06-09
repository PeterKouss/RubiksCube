#ifndef DECLARATION_H
#define DECLARATION_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSTEPNUM 200
#define ERRORPRINT(ERRORINFO) { printf(ERRORINFO); printf("planA: %s\n\n", planA); cube_printf(); system("pause"); exit(1); }

typedef char COLOR;
#define CR_UP '6'
#define CR_DN '1'
#define CR_LF '4'
#define CR_RT '3'
#define CR_FR '2'
#define CR_BK '5'

// otherfunctions.c
extern COLOR side_up[9], side_dn[9], side_lf[9], side_rt[9], side_fr[9], side_bk[9];
void _addnewline_and_COMsend(char* str);
int mygetline(char* str, int len);
int addnewline(char* str, int len);

// operation.c
void operation_analysis(char* step);
void initialize_cube();
int initialized_cube_verify();

// cubeiostream.c
void cube_printf();
void cube_fprintf();
void cube_fread();

// cubesolve.c
extern char planA[MAXSTEPNUM];
extern char planB[MAXSTEPNUM];
int count_string(char* str);
void cube_solve();

// COMsend.c
void COMsend(char* str, int len);

#endif // !DECLARATION_H
