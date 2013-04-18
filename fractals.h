#pragma once

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define JULIA   	1
#define MANDELBROT	0
#define NUM_COLORS	256


void readInput(char*);
void writeOutput(char*);
void computeDim();
void Julia();
void Mandelbrot();
void print_param();

//==== global variables ====//

//input
typedef struct parameters{
	int 	type;						// 0 == Mandelbrot, 1 == Julia
	double 	x_min, x_max, y_min, y_max; // x & y range
	double 	rez;						//resolution
	int 	NUM_STEPS;					//iterations
	double 	re, im;						//Julia complex definitions
	int n, m;							//matrix dimensions
	int init_n;
} parameters;

parameters param;

int backup_n;

//matrix 
int **img;

//dist
int rank;
int N;

// x_min, x_max, y_min, y_max, rezoluția și numărul de iterații
