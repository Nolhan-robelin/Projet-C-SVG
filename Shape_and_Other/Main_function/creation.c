#include <stdio.h>
#include <stdlib.h>
#include "creation.h"

int createFile(void)
{
    // Function which will create a file 
    FILE* fptr;
    fptr = fopen("projet.html", "w");
                                
    if(fptr = NULL) {
        printf("The file did not opened.\n");
        printf("You may retry\n");
        return 0;
    }

    else  
    {  
        printf("The file got created successfully\n");
        char* dateP = malloc(sizeof(char) * 250);
        char dataP[250] = "<html>"
                            "<head>"
                                "<meta charset='UTF-8' />"
                                "<title>Exemple mêlant HTML & SVG</title>"
                            "</head>"
                            "<body>"
                                "<svg width='150' height='100' viewBox='-400 400 200 -200'>";
        fputs(dataP, fptr);
        
        return 1;
    }

}

int openFile(void)
{
    FILE* fptr;
    fptr = fopen("projet.html", 'w');
                            
    if(fptr = NULL) {
        printf("The file did not opened.\n");
        printf("You may retry");
        return 0;
    }
    else
    {
        printf("File successfully opened\n");
        return 1;
    }         
}

int save(void)
{
    // Function which save what the user made
    return 0;
}


void visualize(void)
{
    system("xdg-open projet.html");
}