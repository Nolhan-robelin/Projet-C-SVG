#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "../Shape/Shape_modifier/node.h"
#include "string.h"
#include "../Shape/shape.h"


int viewFile(NodeName* listName, NodeValue* listValue, NodeStyle* listStyle)
{
    // Function which will create a file 
    FILE* fptr;
    fptr = fopen("projet.html", "w");
                                
    if(fptr == NULL) {
        printf("The file did not opened.\n");
        printf("You may retry\n");
        return 0;
    }

    else  
    {  
        printf("The file got created successfully\n");
        char* dataP = malloc(sizeof(char) * 1000);
        dataP = "<svg xmlns='http://www.w3.org/2000/svg' width='150' height='100' viewBox='-400 400 200 -200";
        
    NodeValue* liveValue = listValue;
    NodeName* liveName = listName;
    NodeStyle* liveStyle = listStyle;
    
    while (liveValue != NULL) {
        
        char* actualName = liveName->data;
        if (strcmp(actualName, "Circle")) 
            return 0;

        else if (strcmp(actualName, "Elipse")) 
            return 0;

        else if (strcmp(actualName, "Line")) 
            return 0;
        
        else if (strcmp(actualName, "Rectangle")) 
            return 0;
        
    liveName = liveName->next;
    liveValue = liveValue->next;
    }
    fputs(dataP, fptr);
        
    return 1;
    }

}

int openFile(void)
{
    FILE* fptr;
    fptr = fopen("projet.html", "w");
                            
    if(fptr == NULL) {
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
