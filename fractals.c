#include "fractals.h"

void computeDim(){

  param.n = (int)floor((param.y_max-param.y_min)/param.rez);
	param.m = (int)floor((param.x_max-param.x_min)/param.rez);

	//printf("%d %d\n",param.n,param.m);

	param.init_n = param.n;

	int i;

    int *array = (int *)malloc(param.n*param.m*sizeof(int));
    img = (int **)malloc(param.n*sizeof(int*));
    
    for (i=0; i<param.n; i++)
       	img[i] = &(array[param.m*i]);
}


int main(int argc, char* argv[]){

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &N);

	if(rank == 0){
		
		readInput(argv[1]);

		int i;
		computeDim();
		
		int partition = (int)floor(param.n/N);

		for(i = 1; i<N; i++){
			
			parameters p = param;

			if(i<N-1){
				p.n 	= partition;
			}else{
				p.n 	= param.n - (N-1)*partition;
			}

			MPI_Send(&p, sizeof(param), MPI_INT, i, 0, MPI_COMM_WORLD);	
		}

		//updates		
		backup_n	= param.n;
		param.n 	= partition;

		if(param.type == JULIA){
			Julia();
		}else{
			Mandelbrot();
		}

		param.n = backup_n;
		int last_n = param.n-(N-1)*partition;  
        int it;

        for(it = 1; it<N; it++){

        	if(it!=N-1){
				MPI_Recv(&(img[it*partition][0]), partition*param.m, MPI_INT, it, MPI_ANY_TAG, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			}else{
				MPI_Recv(&(img[it*partition][0]), last_n*param.m, MPI_INT, it, MPI_ANY_TAG, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			}

		}
		writeOutput(argv[2]);

	}else{
		MPI_Recv(&param, sizeof(param), MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		int i;

    	int *array = (int *)malloc(param.n*param.m*sizeof(int));
    	img = (int **)malloc(param.n*sizeof(int*));
    	
    	for (i=0; i<param.n; i++)
        	img[i] = &(array[param.m*i]);


		if(param.type == JULIA){
			Julia();
		}else{
			Mandelbrot();
		}

		 MPI_Send(&(img[0][0]), param.n*param.m, MPI_INT, 0, 0, MPI_COMM_WORLD);	
	}


	MPI_Finalize();
	return 0;

}
