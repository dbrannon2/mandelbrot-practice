#include <stdio.h>

double Min_re, Max_re, Min_im, Max_im;
int height, width, max_iterations;

int main(void){

	
	height = 800;
	width = 800;
	max_iterations = 50;
	int r,g,b;

printf("P6\n");
printf("# comments\n");
printf("%d %d\n", width, height);
printf("255\n");

	Min_re = -.010979991; //scale to -2.0 for full set
	Max_re = -.009;		  //scale to 1.0
	Min_im = -.74900005;  //scale to -2.0
	Max_im = Min_im + (Max_re - Min_re) * height / width ;
		
	double re_factor = (Max_re - Min_re)/(width-1);
	double im_factor = (Max_im - Min_im)/(height-1);

			double x;
			double y;
		/*
			Starting from the top of the picture (0,0) , 
			calculates c_im at each pixel, row by row. 
		*/
			for( y = 0; y < height; y++){
			
				double c_im = Max_im - y* im_factor;


				for( x = 0; x < width; x++){
			
					double c_re = Min_re + x * re_factor;
			
					double Z_re = c_re;
			
					double Z_im = c_im;

					int isInside = 1;	
			
			

					int i;

					for(i = 0; i < max_iterations; i++){

						double Z_re2 = Z_re * Z_re, Z_im2 = Z_im*Z_im;	

						if(Z_re2 + Z_im2 > 4){
				//is Divergent
							isInside = 0;
							break;
						}

				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;

			}
			if(isInside==1){
				r = 0;
				fputc((char) r, stdout);
				fputc((char) r, stdout);
				fputc((char) r, stdout);
			}
			else{
				r=255;
				fputc((char) r, stdout);
				fputc((char) r, stdout);
				fputc((char) r, stdout);
			}


		}

	}

}	
