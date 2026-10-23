#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "../shape.h"
#include "string.h"


void clear_buffer(void)
{
    char c = 'a';
    while (c != '\n' && c != EOF)
    {
        c = getc(stdin);
    }
}

/** @brief Creates a new node for storing shape values
 * @param value Pointer to the value to store
 * @return Pointer to the new node
 */
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

/** @brief Creates a new node for storing shape names
 * @param name Pointer to the name to store
 * @return Pointer to the new node
 */
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

/** @brief Creates a new node for storing shape styles
 * @param style Pointer to the style to store
 * @return Pointer to the new node
 */
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

/** @brief Inserts a new value node at the head of the list
 * @param head Pointer to the head of the list
 * @param value Array of values to store in the new node
 * @return Pointer to the new head of the list
 */
NodeValue* insertHeadValue(NodeValue** head, int value[]) {
    NodeValue* new = createNodeValue(value);
    new->next = *head; 
    return new;       
}

/** @brief Inserts a new name node at the head of the list
 * @param head Pointer to the head of the list
 * @param name Array of characters representing the name to store in the new node
 * @return Pointer to the new head of the list
 */
NodeName* insertHeadName(NodeName** head, char name[]) {
    NodeName* new = createNodeName(name);
    new->next = *head; 
    return new;
}

/** @brief Inserts a new style node at the head of the list
 * @param head Pointer to the head of the list
 * @param style Array of characters representing the style to store in the new node
 * @return Pointer to the new head of the list
 */
NodeStyle* insertHeadStyle(NodeStyle** head, char** style) {
    NodeStyle* new = createNodeStyle(style);
    new->next = *head; 
    return new;
}

/** @brief Displays the list of shapes
 * @param headValue Pointer to the head of the value list
 * @param headName Pointer to the head of the name list
 * @param headStyle Pointer to the head of the style list
 * @return None
 */
void formList(NodeValue* headValue, NodeName* headName, NodeStyle* headStyle) {
    NodeValue* liveValue = headValue;
    NodeName* liveName = headName;
    NodeStyle* liveStyle = headStyle;
    
    int* index = liveValue->data;
    
    while (index[0] != 0) {

        char* actualName = liveName->data;
        if (!strcmp(actualName, "Circle")) 
            viewCircle(liveValue, liveName, liveStyle);

        else if (!strcmp(actualName, "Elipse")) 
            viewElipse(liveValue, liveName, liveStyle);

        else if (!strcmp(actualName, "Line")) 
            viewLine(liveValue, liveName, liveStyle);
        
        else if (!strcmp(actualName, "Rectangle")) 
            viewRectangle(liveValue, liveName, liveStyle);
        
        liveName = liveName->next;
        liveValue = liveValue->next;
        liveStyle = liveStyle->next;
        if (liveValue != NULL)    
            index = liveValue->data;
    }
}

/** @brief Updates the index of each shape in the list
 * @param head Pointer to the head of the value list
 * @return None
 */
void updateIndex(NodeValue* head)
{
    int actual = 1;
    NodeValue* temp = head;

    while(temp != NULL)
    {
        int* data = temp->data;

        if(data[0] == 0)
            break;

        data[0] = actual++;
        temp = temp->next;
    }
}

/** @brief Frees the memory allocated for the list of shapes
 * @param headValue Pointer to the head of the value list
 * @param headName Pointer to the head of the name list
 * @param headStyle Pointer to the head of the style list
 * @return None
 */
void freeList(NodeValue** headValue, NodeName** headName, NodeStyle** headStyle) {

    NodeValue* liveValue = *headValue;
    NodeName* liveName = *headName;
    NodeStyle* liveStyle = *headStyle;

    NodeValue* tempValue = NULL;
    NodeName* tempName = NULL;
    NodeStyle* tempStyle = NULL;

    int index;

    printf("Which shape do you want to delete (Index required)\n");
    scanf("%d", &index);

    int* actualindex = liveValue->data;
    
    while (liveValue != NULL && actualindex[0] != index) {
        tempValue = liveValue;
        tempName = liveName;
        tempStyle = liveStyle;

        liveValue = liveValue->next;
        liveName = liveName->next;
        liveStyle = liveStyle->next;

    actualindex = liveValue->data;
    }
    if (tempValue == NULL)
    {
    *headValue = liveValue->next;
    *headName = liveName->next;
    *headStyle = liveStyle->next;
    }
  else
    {
    tempName->next = liveName->next;
    tempValue->next = liveValue->next;
    tempStyle->next = liveStyle->next;
    }
    
    
    liveName->next = tempName;
    liveValue->next = tempValue;
    liveStyle->next = tempStyle;

    char* actualName = liveName->data;

    free(liveName->data);
    free(liveValue->data);

    free(liveStyle->data[0]);
    if (strcmp(actualName ,"Line"))
        free(liveStyle->data[1]);
    free(liveStyle->data);

    free(liveName);
    free(liveValue);
    free(liveStyle);

    updateIndex(*headValue);
}
/**
 * Modifies a shape in the list
 * @param headValue Pointer to the head of the value list
 * @param headName Pointer to the head of the name list
 * @param headStyle Pointer to the head of the style list
 */
void modifyShape(NodeValue** headValue, NodeName** headName, NodeStyle** headStyle)
{
    NodeValue* liveValue = *headValue;
    NodeValue* tempValue = NULL;
    NodeName* liveName = *headName;
    NodeName* tempName = NULL;
    NodeStyle* liveStyle = *headStyle;
    NodeStyle* tempStyle = NULL;

    int* newData = malloc(sizeof(int) * 5);
    char** newStyle = malloc(sizeof(char*) * 2);  
    newStyle[0] = malloc(20);
    newStyle[1] = malloc(20);  
    int index;

    printf("Which shape do you want to modify(Index required)\n");
    scanf("%d", &index);
    
    newData[0] = index;
    
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

    if (!strcmp(actualName,"Circle")) 
    {
        printf("Enter the coordinate x and y of the circle and the radius and both the stroke's color and fill color\n");
        for(int i = 1;i < 4; i++)
        {
            scanf("%d", &newData[i]);
            clear_buffer();
        }
        scanf("%19s", newStyle[0]);
        clear_buffer();
        scanf("%19s", newStyle[1]);
        clear_buffer();
    }

    else if (!strcmp(actualName, "Elipse")) 
    {
        printf("Enter the coordinate x and y of the elipse and the radius at x and y coordinate and both the stroke's color and fill color\n");
        for(int i = 1;i < 5; i++)
        {
            scanf("%d", &newData[i]);
            clear_buffer();
        }
        scanf("%19s", newStyle[0]);
        clear_buffer();
        scanf("%19s", newStyle[1]);
        clear_buffer();
    }
    
    else if (!strcmp(actualName, "Line")) 
    {
        printf("Enter the coordinate x and y of the first point and the coordinate x and y of the second point and the stroke's color\n");
        for(int i = 1;i < 5; i++)
        {
            scanf("%d", &newData[i]);
            clear_buffer();
        }
        scanf("%19s", newStyle[0]);
        clear_buffer();
    }
    
    else if (!strcmp(actualName, "Rectangle")) 
    {
        printf("Enter the coordinate x and y of the rectangle and the width and height of it and both the stroke's color and fill color\n");
        for(int i = 1;i < 5; i++)
        {
            scanf("%d", &newData[i]);
            clear_buffer();
        }
        scanf("%19s", newStyle[0]);
        clear_buffer();
        scanf("%19s", newStyle[1]);
        clear_buffer();
    }
    
    liveStyle->data = newStyle;
    liveValue->data = newData;
}
