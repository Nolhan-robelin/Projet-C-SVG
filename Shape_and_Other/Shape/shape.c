#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Shape/circle.h"
#include "../Shape/elipse.h"
#include "../Shape/line.h"
#include "../Shape/rectangle.h"
#include "../Shape/Shape_modifier/node.h"


int circle(int nbForm, NodeName** listName, NodeValue** listValue, NodeStyle** listStyle)
{
    circle_t newCircle;

    newCircle.fill = malloc(sizeof(char)*20);
    newCircle.stroke = malloc(sizeof(char)*20);
    printf("What are the coordinate x and y of the circle and the radius\n");
    printf("Then enter the color of the stroke and the color you want to fill the shape\n");
    printf("Press Enter between each values\n");
    scanf("%d", &newCircle.x);
    scanf("%d", &newCircle.y);
    scanf("%d", &newCircle.radius);
    scanf("%19s", newCircle.fill);
    scanf("%19s", newCircle.stroke);

    nbForm++;

    char** style = malloc(sizeof(char*) * 2);
    style[0] = newCircle.fill;
    style[1] = newCircle.stroke;

    char* name = malloc(strlen("Circle")+1);
    strcpy(name, "Circle");

    int* values = malloc(sizeof(int) * 4);
    values[0] = nbForm;
    values[1] = newCircle.x;
    values[2] = newCircle.y;
    values[3] = newCircle.radius;

    *listName = insertHeadName(listName, name);
    *listValue = insertHeadValue(listValue, values);
    *listStyle = insertHeadStyle(listStyle, style);

    return nbForm;
}

void viewCircle(NodeValue* liveValue, NodeName* liveName, NodeStyle* liveStyle)
{
    char* actualName = liveName->data;
    int* actualTab = liveValue->data;
    char** actualStyle = liveStyle->data;
    printf("%d. ", actualTab[0]);
    printf("%s ", actualName);
    printf("at coordinate x:%d and y:%d and with a radius of %d with the stroke color of %s and fill color of %s\n", actualTab[1], actualTab[2], actualTab[3], actualStyle[0], actualStyle[1]);
}

char* addCircle(NodeValue* liveValue, NodeStyle* liveStyle)
{
    int* actualTab = liveValue->data;
    char** actualStyle = liveStyle->data;
   
    char* result = malloc(150 * sizeof(char));
    
    snprintf(result, 150, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" style=\"fill:%s; stroke:%s;\" />",actualTab[1], actualTab[2], actualTab[3], actualStyle[0], actualStyle[1]);
    return result;
}



int elipse(int nbForm, NodeName** listName, NodeValue** listValue, NodeStyle** listStyle)
{
    elipse_t newElipse;

    newElipse.fill = malloc(sizeof(char)*20);
    newElipse.stroke = malloc(sizeof(char)*20);

    printf("What are the coordinate x and y of the elipse and the radius at x and y coordinate\n");
    printf("Then enter the color of the stroke and the color you want to fill the shape\n");
    printf("Press Enter between each values\n");
    scanf("%d", &newElipse.cx);
    scanf("%d", &newElipse.cy);
    scanf("%d", &newElipse.rx);
    scanf("%d", &newElipse.ry);
    scanf("%19s", newElipse.fill);
    scanf("%19s", newElipse.stroke);
    nbForm++;
    
    char** style = malloc(sizeof(char*) * 2);
    style[0] = newElipse.fill;
    style[1] = newElipse.stroke;

    int* values = malloc(sizeof(int) * 5);
    values[0] = nbForm;
    values[1] = newElipse.cx;
    values[2] = newElipse.cy;
    values[3] = newElipse.rx;
    values[4] = newElipse.ry;  

    char* name = malloc(strlen("Elipse") + 1);
    strcpy(name, "Elipse");
    *listName = insertHeadName(listName, name);
    *listValue = insertHeadValue(listValue, values);
    *listStyle = insertHeadStyle(listStyle, style);

    return nbForm;
}

void viewElipse(NodeValue* liveValue, NodeName* liveName, NodeStyle* liveStyle)
{
    char* actualName = liveName->data;
    int* actualTab = liveValue->data;
    char** actualStyle = liveStyle->data;
    printf("%d. ", actualTab[0]);
    printf("%s ", actualName);
    printf("at coordinate x:%d and y:%d and with a radius of %d at x axis and %d at y axis with the stroke color of %s and fill color of %s\n", actualTab[1], actualTab[2], actualTab[3], actualTab[4], actualStyle[0], actualStyle[1]);
}

char* addElipse(NodeValue* liveValue, NodeStyle* liveStyle)
{
    int* actualTab = liveValue->data;
    char** actualStyle = liveStyle->data;
   
    char* result = malloc(150 * sizeof(char));
    
    snprintf(result, 150, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" style=\"fill:%s; stroke:%s;\" />",actualTab[1], actualTab[2], actualTab[3], actualTab[4], actualStyle[0], actualStyle[1]);
    return result;
}




int line(int nbForm, NodeName** listName, NodeValue** listValue, NodeStyle** listStyle)
{
    line_t newLine;

    newLine.stroke = malloc(sizeof(char)*20);

    printf("What are the coordinate x and y of the first point and the coordinate x and y of the second point\n");
    printf("Then enter the color of the stroke\n");
    printf("Press Enter between each values\n");
    scanf("%d", &newLine.x1);
    scanf("%d", &newLine.x2);
    scanf("%d", &newLine.y1);
    scanf("%d", &newLine.y2);
    scanf("%19s", newLine.stroke);
    nbForm++;
    
    char** style = malloc(sizeof(char*) * 1);
    style[0] = newLine.stroke;

    int* values = malloc(sizeof(int) * 5);
    values[0] = nbForm;
    values[1] = newLine.x1;
    values[2] = newLine.x2;
    values[3] = newLine.y1;
    values[4] = newLine.y2;  

    char* name = malloc(strlen("Line") + 1);
    strcpy(name, "Line");
    *listName = insertHeadName(listName, name);
    *listValue = insertHeadValue(listValue, values);
    *listStyle = insertHeadStyle(listStyle, style);

    return nbForm;
}

void viewLine(NodeValue* liveValue, NodeName* liveName, NodeStyle* liveStyle)
{
    char* actualName = liveName->data;
    int* actualTab = liveValue->data;
    char** actualStyle = liveStyle->data;
    printf("%d. ", actualTab[0]);
    printf("%s ", actualName);
    printf("with the first point being at coordinate x:%d and y:%d and the second point at coordinate x:%d and y:%d and with a stroke color of %s\n", actualTab[1], actualTab[2], actualTab[3], actualTab[4], actualStyle[0]);
}

char* addLine(NodeValue* liveValue, NodeStyle* liveStyle)
{
    int* actualTab = liveValue->data;
    char** actualStyle = liveStyle->data;
   
    char* result = malloc(150 * sizeof(char));
    
    snprintf(result, 150, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:%s;\" />",actualTab[1], actualTab[2], actualTab[3], actualTab[4], actualStyle[0]);
    return result;
}




int rectangle(int nbForm, NodeName** listName, NodeValue** listValue, NodeStyle** listStyle)
{
    rectangle_t newRectangle;

    newRectangle.fill = malloc(sizeof(char)*20);
    newRectangle.stroke = malloc(sizeof(char)*20);

    printf("What are the coordinate x and y of the rectangle and the width and height of it\n");
    printf("Then enter the color of the stroke and the color you want to fill the shape\n");
    printf("Press Enter between each values\n");
    scanf("%d", &newRectangle.x);
    scanf("%d", &newRectangle.y);
    scanf("%d", &newRectangle.width);
    scanf("%d", &newRectangle.height);
    scanf("%19s", newRectangle.fill);
    scanf("%19s", newRectangle.stroke);
    nbForm++;
    
    char** style = malloc(sizeof(char*) * 2);
    style[0] = newRectangle.fill;
    style[1] = newRectangle.stroke;

    int* values = malloc(sizeof(int) * 5);
    values[0] = nbForm;
    values[1] = newRectangle.x;
    values[2] = newRectangle.y;
    values[3] = newRectangle.width;
    values[4] = newRectangle.height; 

    char* name = malloc(strlen("Rectangle") + 1);
    strcpy(name, "Rectangle");
    *listName = insertHeadName(listName, name);
    *listValue = insertHeadValue(listValue, values);
    *listStyle = insertHeadStyle(listStyle, style);

    return nbForm;
}

void viewRectangle(NodeValue* liveValue, NodeName* liveName, NodeStyle* liveStyle)
{
    char* actualName = liveName->data;
    int* actualTab = liveValue->data;
    char** actualStyle = liveStyle->data;
    printf("%d. ", actualTab[0]);
    printf("%s ", actualName);
    printf("at coordinate x:%d and y:%d and with a width of %d and a height of %d with the stroke color of %s and fill color of %s\n", actualTab[1], actualTab[2], actualTab[3], actualTab[4], actualStyle[0], actualStyle[1]);
}

char* addRectangle(NodeValue* liveValue, NodeStyle* liveStyle)
{
    int* actualTab = liveValue->data;
    char** actualStyle = liveStyle->data;
   
    char* result = malloc(150 * sizeof(char));
    
    snprintf(result, 150, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:%s; stroke:%s;\" />",actualTab[1], actualTab[2], actualTab[3], actualTab[4], actualStyle[0], actualStyle[1]);
    return result;
}
