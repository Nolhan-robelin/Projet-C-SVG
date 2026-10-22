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
    fptr = fopen("svgVisual.svg", "w");
                                
    if(fptr == NULL) {
        printf("The file did not opened.\n");
        printf("You may retry\n");
        return 0;
    }

    else  
    {  
        printf("The file got created successfully\n");
        char* dataP = malloc(sizeof(char) * 1000);
        strcpy(dataP, "<svg xmlns='http://www.w3.org/2000/svg' width='150' height='100' viewBox='-400 400 200 -200'>");
        
    printf("Test export svg");
    NodeValue* liveValue = listValue;
    NodeName* liveName = listName;
    NodeStyle* liveStyle = listStyle;
    int* index = liveValue->data;
    char* circ;
    char* elip;
    char* line;
    char* rect;
    printf("Test2 export svg");
    while (index[0] != 0) {
        printf("Test3 export svg");
        char* actualName = liveName->data;
        if (!strcmp(actualName, "Circle")) 
        {
            circ = addCircle(liveValue, liveStyle);
            printf("Test4 export svg");
            strcat(dataP, circ);
            printf("Test5 export svg");
            free(circ);
            printf("Test6 export svg");
        }
        else if (!strcmp(actualName, "Elipse")) 
        {
            elip = addElipse(liveValue, liveStyle);
            strcat(dataP, elip); 
            free(elip);
        }
        else if (!strcmp(actualName, "Line"))
        { 
            line = addLine(liveValue, liveStyle);
            strcat(dataP, line); 
            free(line);
        }
        else if (!strcmp(actualName, "Rectangle"))
        { 
            rect = addRectangle(liveValue, liveStyle);
            strcat(dataP, rect);
            free(rect);
        }
        
    liveName = liveName->next;
    liveValue = liveValue->next;
    }
    char* endDataP = "</svg>";

    strcat(dataP, endDataP);
    fputs(dataP, fptr);
    fclose(fptr);
    free(dataP);
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
        fclose(fptr); 
        return 0;
    }
    else
    {
        printf("File successfully opened\n");
        fclose(fptr); 
        return 1;
    }
    fclose(fptr);         
}
