#include "fractals.h"

void Julia(){

  
	int 	i, j;
	double 	re_z, im_z; //z= re_z + im_z;
	int 	step;

	int partition = (int)floor(param.init_n/N);

	for(i = rank*partition; i < rank*partition + param.n; i++){
		for(j = 0; j<param.m; j++){

				re_z = param.x_min + j*param.rez;
				im_z = param.y_min + i*param.rez;
				step = 0;
			
			while(sqrt(re_z*re_z + im_z*im_z) < 2){

					if(step >= param.NUM_STEPS){
						break;
					}

					step ++;

					double prevRe_z = re_z; 
					re_z = (re_z * re_z - im_z*im_z) + param.re;
					im_z = (2 * prevRe_z * im_z) + param.im;

			}

			img[i-rank*partition][j] = step % NUM_COLORS;


		}
	}


}
