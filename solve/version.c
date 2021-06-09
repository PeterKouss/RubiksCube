/*
* Rubik's Cube Solving Program
* version 1.04b
* 
* 1.00b update on 2020/03/03:
* (i) Renamed some operations;
* (ii) Used Linux C function gettimeofday() to get more accurate time;
* 
* 1.01a update on 2020/03/13:
* (i) Introduced CFOP method to the program;
* (ii) Improved debugging strategy with ERRORPRINT;
* (iii) Separated cubesolve module to three parts;
* (iv) Fixed several bugs;
* 
* 1.02a update on 2020/04/17:
* (i) Changed the data type of the cube color;
* (ii) Changed and deleted some modules to make the code more efficient;
* (iii) Added a serial port sending module;
* 
* 1.03a update on 2020/04/27:
* (i) Used console style to control and display;
* 
* 1.04a update on 2020/05/16:
* (i) Rewrote the function main() to simulate the whole process from scrambling to solving;
* 
* 1.04b update on 2020/05/22:
* (i) Deleted the command 'z' in RubiksCubeSolve module;
* (ii) Renamed RubiksCubeImgproc module;
* 
* Copyright (c) 2020 Marina Akitsuki. All rights reserved.
* Date modified: 2020/05/22
* 
*/
