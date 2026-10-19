#include <stdio.h>
#include <stdlib.h>
#include "node.h"

NodeValue* createNodeValue(int* value) {
    NodeValue* new = (NodeValue*) malloc(sizeof(NodeValue));
    if (new == NULL) {
        printf("Error : Couldn't allocate memory\n");
        exit(1);
    }
    new->data = value;
    new->next = NULL; 
    return new;
}

NodeName* createNodeName(char* name) {
    NodeName* new = (NodeName*) malloc(sizeof(NodeName));
    if (new == NULL) {
        printf("Error : Couldn't allocate memory\n");
        exit(1);
    }
    new->data = name;
    new->next = NULL; 
    return new;
}

NodeValue* insertHeadValue(NodeValue* head, int value[]) {
    NodeValue* new = createNodeValue(value);
    new->next = head; 
    return new;       
}

NodeName* insertHeadName(NodeName* head, char name[]) {
    NodeName* new = createNodeName(name);
    new->next = head; 
    return new;
}

void formList(NodeValue* headValue, NodeName* headName) {
    NodeValue* liveValue = headValue;
    NodeName* liveName = headName;
    while (liveValue != NULL) {
        char actualName = liveName->data;
        if (actualName == "Circle") 
            viewCircle(liveValue, liveName);

        else if (actualName == "Elipse") 
            viewElipse(liveValue, liveName);

        else if (actualName == "Line") 
            viewLine(liveValue, liveName);
        
        else if (actualName == "Rectangle") 
            viewRectangle(liveValue, liveName);
        
        liveName = liveName->next;
        liveValue = liveValue->next;
    }
}

void freeList(int index, NodeValue* headValue, NodeName* headName) {
    
    NodeValue* delValue;
    NodeName* delName;
    NodeValue* liveValue = headValue;
    NodeName* liveName = headName;
    NodeValue* tempValue = NULL;
    NodeName* tempName = NULL;
    int actualindex = liveValue->data;
    
    while (actualindex != index - 1) {
        tempValue = liveValue->next;
        tempName = liveName->next;
        liveValue = tempValue;
        liveName = tempName;
    }
    delName = liveName->data;
    delValue = liveValue->data;
    tempName = delName->data;
    tempValue = delValue->data;

    liveName->next = tempName;
    liveValue->next = tempValue;

    free(delName);
    free(delValue);
}

void modifyShape(NodeValue* headValue, NodeName* headName)
{
    NodeValue* liveValue = headValue;
    NodeValue* tempValue = NULL;
    NodeName* liveName = headName;
    NodeName* tempName = NULL;

    int newData[4];
    int index;

    printf("Which shape do you want to modify(Index)");
    scanf("%d", &index);
    
    int actualindex = liveValue->data;
    
    while (actualindex != index) {
        tempValue = liveValue->next;
        liveValue = tempValue;
        tempName = liveName;
        liveName = tempName;
    }
    
    char actualName = liveName->data;

    if (actualName == "Circle") 
    {
        for(int i = 0;i < 3; i++)
            scanf("%d", newData[i]);
    }

    else if (actualName == "Elipse") 
    {
        for(int i = 0;i < 4; i++)
            scanf("%d", newData[i]);
    }
    
    if (actualName == "Line") 
    {
        for(int i = 0;i < 4; i++)
            scanf("%d", newData[i]);
    }
    
    else if (actualName == "Rectangle") 
    {
        for(int i = 0;i < 4; i++)
            scanf("%d", newData[i]);
    }

    liveValue->data = newData;
}
