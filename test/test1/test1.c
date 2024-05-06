#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])                                                              
 {                      
    FILE *proc;                                                                       
    char *buffer;                                                                              
    char command[512];  
    char proc_n[512];                                                                                                                                  

    buffer = malloc(strlen(argv[1]) + 5);                                                    
    strcpy(buffer,argv[1]);                                                                                                                          
    sprintf(command,"pidof %s",buffer);
 
    printf("%s\n",command);
    proc = popen(command, "r");
    fgets(proc_n, sizeof(proc_n), proc); 

    printf("%s\n", proc_n);                                                   
             
    free(buffer);                                                                            
                                                                                              
   return 0;                                                                                   
 } 
