#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  FILE *IMAGE;
  IMAGE = fopen("image.ppm", "w");

  int i, r, g, b;


  fprintf(IMAGE, "P3\n500 500\n255\n");
  for(i=0; i<pow(500,2); i++){
	  if(i<pow(500,2)/3){
		r = i;
		g = pow(i % 255,2);
		b = pow(i % 255,3);
	  }
	   else if(i<(pow(500,2)/3)*2){
		g = i;
		r = pow(i % 255,3);
		b = pow(i % 255,5);
	  }
	   else{
		b = i;
		r = pow(i % 255,5);
		g = pow(i % 255,7);
	  }
    fprintf(IMAGE, "%d %d %d\n", r % 255, g % 255, b % 255);
  }

  fclose(IMAGE);

  return 0;
}