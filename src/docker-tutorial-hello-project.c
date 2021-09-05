#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main(int argc, char **argv) {
  
  char* directory;
  char* filename_in; 
  char*	filename_out;
  if (argc >= 2){
      FILE* demo_read;
      FILE* demo_write;
      directory = argv[1];
      printf("Directory is : %s \n", directory);
      char directory_help[40];
      strcpy(directory_help,directory);
      filename_in = strcat(directory_help,"/read.txt");
      demo_read = fopen(filename_in,"r+");
      if(!demo_read){
         printf("You forgot the read.txt file in the bindmount directory, quitting. \n");
         exit(1);
      }
      char directory_help2[40];
      strcpy(directory_help2,directory);
      filename_out = strcat(directory_help2,"/write.txt");
      demo_write = fopen(filename_out,"w+");
      char c;
      while ((c = getc(demo_read)) != EOF){
           putchar(c);
           fprintf(demo_write, "%c ",c);
      }
      fprintf(demo_write, "\n %s  ","Hello world");
      printf("Hello world from the final program!  Here were the arguments! \n");
    
      for (int i = 2; i < argc; i++){
		  	printf("Argument %d %s \n",i,argv[i]);
        		fprintf(demo_write, "%s %d %s \n", "Arguments ",i,argv[i]);
	  	}
    fclose(demo_write);
    fclose(demo_read);
    
  } 
  return 0;
}
