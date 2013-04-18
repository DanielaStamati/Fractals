  #include "fractals.h"

    void print_param(){
        printf("===== rank %d =====\n",rank);

        printf("x_min %lf x_max %lf y_min %lf y_max %lf\n",param.x_min,param.x_max,param.y_min,param.y_max);
        printf("tip: %d\n", param.type); 
        printf("rez %e\n",param.rez);
        printf("nr steps: %d\n",param.NUM_STEPS);
        printf("n: %d\n",param.n);
    }
	
    void readInput(char* inputFile){

    	FILE *f = fopen(inputFile,"r");

    	fscanf(f,"%d", &param.type); 
    	fscanf(f,"%lf%lf%lf%lf",&param.x_min,&param.x_max,&param.y_min,&param.y_max);
    	fscanf(f,"%lf",&param.rez);
    	fscanf(f,"%d",&param.NUM_STEPS);

        param.init_n = param.n;

    	if(param.type == JULIA){
    		fscanf(f,"%lf%lf",&param.re,&param.im);
    	}

    	fclose(f);

    }

    void writeOutput(char* outputFile){

    	FILE *f = fopen(outputFile, "w");
    	int i, j;

    	fprintf(f,"P2\n");
    	fprintf(f,"%d %d\n", param.m, param.n);
    	fprintf(f,"255\n");

    	for(i = param.n-1; i>=0; i--){
    		for(j = 0; j<param.m; j++){
    			fprintf(f,"%d ",img[i][j]);
    		}

    		fprintf(f,"\n");
    	}


    	fclose(f);
    }

