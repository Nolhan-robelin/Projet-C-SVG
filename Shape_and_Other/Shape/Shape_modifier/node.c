#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "../shape.h"
#include "string.h"

NodeValue* createNodeValue(int* value) {
    NodeValue* new = malloc(sizeof(NodeValue));
    if (new == NULL) {
        printf("Error : Couldn't allocate memory\n");
        exit(1);
    }
    new->data = value;
    new->next = NULL; 
    return new;
}

NodeName* createNodeName(char* name) {
    NodeName* new = malloc(sizeof(NodeName));
    if (new == NULL) {
        printf("Error : Couldn't allocate memory\n");
        exit(1);
    }
    new->data = name;
    new->next = NULL; 
    return new;
}

NodeStyle* createNodeStyle(char** style) {
    NodeStyle* new = malloc(sizeof(NodeStyle));
    if (new == NULL) {
        printf("Error : Couldn't allocate memory\n");
        exit(1);
    }
    new->data = style;
    new->next = NULL; 
    return new;
}

NodeValue* insertHeadValue(NodeValue** head, int value[]) {
    NodeValue* new = createNodeValue(value);
    new->next = *head; 
    return new;       
}

NodeName* insertHeadName(NodeName** head, char name[]) {
    NodeName* new = createNodeName(name);
    new->next = *head; 
    return new;
}

NodeStyle* insertHeadStyle(NodeStyle** head, char* style[]) {
    NodeStyle* new = createNodeStyle(style);
    new->next = *head; 
    return new;
}

void formList(int nbForm, NodeValue* headValue, NodeName* headName, NodeStyle* headStyle) {
    NodeValue* liveValue = headValue;
    NodeName* liveName = headName;
    NodeStyle* liveStyle = headStyle;
    
    int* index = liveValue->data;
    printf("Test entreé fonction index : %d valeur de nbForm: %d \n", index[0], nbForm);
    
    while (index[0] != 0) {
        printf("Test2 entreé fonction");
        char* actualName = liveName->data;
        if (strcmp(actualName, "Circle")) 
        {
            viewCircle(liveValue, liveName, liveStyle);
            printf("Test3 entreé fonction");
        }
        else if (strcmp(actualName, "Elipse")) 
            viewElipse(liveValue, liveName, liveStyle);

        else if (strcmp(actualName, "Line")) 
            viewLine(liveValue, liveName, liveStyle);
        
        else if (strcmp(actualName, "Rectangle")) 
            viewRectangle(liveValue, liveName, liveStyle);
        
        liveName = liveName->next;
        liveValue = liveValue->next;
        liveStyle = liveStyle->next;
        index = liveValue->data;
    }
}

void freeList(NodeValue** headValue, NodeName** headName, NodeStyle** headStyle) {
    
    NodeValue* delValue;
    NodeName* delName;
    NodeStyle* delStyle;

    NodeValue* liveValue = headValue;
    NodeName* liveName = headName;
    NodeStyle* liveStyle = headStyle;

    NodeValue* tempValue = NULL;
    NodeName* tempName = NULL;
    NodeStyle* tempStyle = NULL;

    int index;

    printf("Which shape do you want to modify(Index)\n");
    scanf("%d", &index);

    int* actualindex = liveValue->data;
    
    while (actualindex[0] != index - 1) {
        tempValue = liveValue->next;
        tempName = liveName->next;
        tempStyle = liveStyle->next;

        liveValue = tempValue;
        liveName = tempName;
        liveStyle = tempStyle;

        actualindex = liveValue->data;
    }
    
    delValue = liveValue->next;
    delName = liveName->next;
    delStyle = liveStyle->next;

    tempName = delName->next;
    tempValue = delValue->next;
    tempStyle = delStyle->next;
    
    liveName->next = tempName;
    liveValue->next = tempValue;
    liveStyle->next = tempStyle;

    free(delName);
    free(delValue);
    free(delStyle);
}

void modifyShape(NodeValue** headValue, NodeName** headName, NodeStyle** headStyle)
{
    NodeValue* liveValue = headValue;
    NodeValue* tempValue = NULL;
    NodeName* liveName = headName;
    NodeName* tempName = NULL;
    NodeStyle* liveStyle = headStyle;
    NodeStyle* tempStyle = NULL;

    int* newData = malloc(sizeof(int) * 5);
    char* newStyle = malloc(sizeof(char)* 50);
    int index;

    printf("Which shape do you want to modify(Index)\n");
    scanf("%d", &index);
    
    int* actualindex = liveValue->data;
    
    while (actualindex[0] != index) {
        tempValue = liveValue->next;
        liveValue = tempValue;

        tempName = liveName->next;
        liveName = tempName;

        tempStyle = liveStyle->next;
        liveStyle = tempStyle;

        actualindex = liveValue->data;
    }
    
    char* actualName = liveName->data;

    if (strcmp(actualName,"Circle")) 
    {
        printf("Enter the coordinate x and y of the circle and the radius and both the stroke's color and fill color\n");
        for(int i = 0;i < 3; i++)
            scanf("%d", newData);
        scanf("%s", newStyle);
        scanf("%s", newStyle);
    }

    else if (strcmp(actualName, "Elipse")) 
    {
        printf("Enter the coordinate x and y of the elipse and the radius at x and y coordinate and both the stroke's color and fill color\n");
        for(int i = 0;i < 4; i++)
            scanf("%d", newData);
        scanf("%s", newStyle);
        scanf("%s", newStyle);
    }
    
    else if (strcmp(actualName, "Line")) 
    {
        printf("Enter the coordinate x and y of the first point and the coordinate x and y of the second point and the stroke's color\n");
        for(int i = 0;i < 4; i++)
            scanf("%d", newData);
        scanf("%s", newStyle);
    }
    
    else if (strcmp(actualName, "Rectangle")) 
    {
        printf("Enter the coordinate x and y of the rectangle and the width and height of it and both the stroke's color and fill color\n");
        for(int i = 0;i < 4; i++)
            scanf("%d", newData);
        scanf("%s", newStyle);
        scanf("%s", newStyle);
    }
    
    liveStyle->data = &newStyle;
    liveValue->data = newData;
    free(newData);
    free(newStyle);
}
