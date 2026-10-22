#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "../Shape/Shape_modifier/node.h"
#include "string.h"
#include "../Shape/shape.h"

/** @brief open the svg file and write the shapes in it
 * @param listName List of form names
 * @param listValue List of form values
 * @param listStyle List of form styles
 * @return 1 if successful, 0 otherwise
 */
int viewFile(NodeName* listName, NodeValue* listValue, NodeStyle* listStyle)
{
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
        

    NodeValue* liveValue = listValue;
    NodeName* liveName = listName;
    NodeStyle* liveStyle = listStyle;
    int* index = liveValue->data;
    char* circ;
    char* elip;
    char* line;
    char* rect;
  
    while (index[0] != 0) {
    
        char* actualName = liveName->data;
        if (!strcmp(actualName, "Circle")) 
        {
            circ = addCircle(liveValue, liveStyle);   
            strcat(dataP, circ);   
            free(circ);
      
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
    liveStyle = liveStyle->next;
    index = liveValue->data;
    }
    char* endDataP = "</svg>";

    strcat(dataP, endDataP);
    fputs(dataP, fptr);
    fclose(fptr);
    free(dataP);
    return 1;
    }

}

/** @brief Opens a file for writing
 * @param None
 * @return 1 if successful, 0 otherwise
 */
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
