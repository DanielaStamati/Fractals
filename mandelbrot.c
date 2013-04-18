#include "fractals.h"

void Mandelbrot(){

  int 	i, j;
	double 	re_z, im_z; //z= re_z + im_z;
	double 	re_c, im_c;
	int 	step;
	int partition = (int)floor(param.init_n/N);

	for(i = rank*partition; i < rank*partition + param.n; i++){
		for(j = 0; j<param.m; j++){

				re_z = 0;
				im_z = 0;
				step = 0;
			
			while(sqrt(re_z*re_z + im_z*im_z) < 2){

					if(step >= param.NUM_STEPS){
						break;
					}

					step ++;

					re_c = param.x_min + j*param.rez;
					im_c = param.y_min + i*param.rez;

					double prevRe_z = re_z; 
					re_z = (re_z * re_z - im_z*im_z) + re_c;
					im_z = (2 * prevRe_z * im_z) + im_c;

			}

			img[i-rank*partition][j] = step %NUM_COLORS;


		}
	}

}
