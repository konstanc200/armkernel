#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int close(char *proc) 
	{

	printf("%s\n",proc);

	char *buffer;
	char command[512];
	
	buffer = malloc(strlen(proc + 5));
	strcpy(buffer, proc);
	sprintf(command, "kill %s", buffer);

	system(command);

	printf("***Processed closed successfully***\n");

	return 0;
}

int main(int argc, char *argv[]) 
	{

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
