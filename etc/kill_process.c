#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
This script closes ONLY one program. 
It does not requere super user privalige to run. 
It requeres only the name of the program for it to close it 
*/

// Improvments to be made 
// Make it close multiple programs
// And print and error messige when the program name passed does not exist 


int close(char *proc) 
	{

	printf("%s\n",proc);

	char *buffer;
	char command[512];
	
	buffer = malloc(strlen(proc + 5));
	strcpy(buffer, proc);
	sprintf(command, "kill %s", buffer);

	system(command);

	return 0;
}

int main(int argc, char *argv[]) 
	{

	if(argv[1] == NULL)
	{
		printf("** No Process to Close\n");
		return 1;

	}

        FILE *proc;       
  	char *buffer;     
  	char command[512];
  	char proc_n[512];
  
	buffer = malloc(strlen(argv[1]) + 5);                 
        strcpy(buffer,argv[1]);                               
        sprintf(command,"pidof %s",buffer);
  
  	proc = popen(command, "r");
  	fgets(proc_n, sizeof(proc_n), proc);   

	close(proc_n);
    
  	free(buffer);                                         
 	pclose(proc);


	return 0; 
}
