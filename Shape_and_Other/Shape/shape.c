#include <stdio.h>
#include <stdlib.h>
#include "../Shape/circle.h"
#include "../Shape/elipse.h"
#include "../Shape/line.h"
#include "../Shape/rectangle.h"
#include "../Shape/Shape_modifier/node.h"


int circle(int nbForm, NodeName* listName, NodeValue* listValue, NodeStyle* listStyle)
{
    circle_t newCircle;

    printf("What are the coordinate x and y of the circle and the radius\n");
    printf("Then enter the color of the stroke and the color you want to fill the shape\n");
    printf("Press Enter between each values\n");
    scanf("%d", &newCircle.x);
    scanf("%d", &newCircle.y);
    scanf("%d", &newCircle.radius);
    scanf("%s", newCircle.fill);
    scanf("%s", newCircle.stroke);
    nbForm++;

    char* style[] = {newCircle.fill, newCircle.stroke};
    char name[] = {"Circle"};
    int values[] = {nbForm, newCircle.x, newCircle.y, newCircle.radius};
    listName = insertHeadName(listName, name);
    listValue = insertHeadValue(listValue, values);
    listStyle = insertHeadStyle(listStyle, style);
    
    return nbForm;
}

void viewCircle(NodeValue* liveValue, NodeName* liveName, NodeStyle* liveStyle)
{
    char* actualName = liveName->data;
    int* actualTab = liveValue->data;
    char** actualStyle = liveStyle->data;
    printf("%d ", actualTab[0]);
    printf("%s ", actualName);
    printf("at coordinate x:%d and y:%d and with a radius of %d with the stroke color of %s and fill color of %s\n", actualTab[1], actualTab[2], actualTab[3], actualStyle[0], actualStyle[1]);
}

int elipse(int nbForm, NodeName* listName, NodeValue* listValue, NodeStyle* listStyle)
{
    elipse_t newElipse;

    printf("What are the coordinate x and y of the elipse and the radius at x and y coordinate\n");
    printf("Then enter the color of the stroke and the color you want to fill the shape\n");
    printf("Press Enter between each values\n");
    scanf("%d", &newElipse.cx);
    scanf("%d", &newElipse.cy);
    scanf("%d", &newElipse.rx);
    scanf("%d", &newElipse.ry);
    scanf("%s", newElipse.fill);
    scanf("%s", newElipse.stroke);
    nbForm++;
    
    char* style[] = {newElipse.fill, newElipse.stroke};
    char name[] = {"Elipse"};
    int values[] = {nbForm, newElipse.cx, newElipse.cy, newElipse.rx, newElipse.ry};
    listName = insertHeadName(listName, name);
    listValue = insertHeadValue(listValue, values);
    listStyle = insertHeadStyle(listStyle, style);

    return nbForm;
}

void viewElipse(NodeValue* liveValue, NodeName* liveName, NodeStyle* liveStyle)
{
    char* actualName = liveName->data;
    int* actualTab = liveValue->data;
    char** actualStyle = liveStyle->data;
    printf("%d ", actualTab[0]);
    printf("%s ", actualName);
    printf("at coordinate x:%d and y:%d and with a radius of %d at x axis and %d at y axis with the stroke color of %s and fill color of %s\n", actualTab[1], actualTab[2], actualTab[3], actualTab[4], actualStyle[0], actualStyle[1]);
}

int line(int nbForm, NodeName* listName, NodeValue* listValue, NodeStyle* listStyle)
{
    line_t newLine;

    printf("What are the coordinate x and y of the first point and the coordinate x and y of the second point\n");
    printf("Then enter the color of the stroke\n");
    printf("Press Enter between each values\n");
    scanf("%d", &newLine.x1);
    scanf("%d", &newLine.x2);
    scanf("%d", &newLine.y1);
    scanf("%d", &newLine.y2);
    scanf("%s", newLine.stroke);
    nbForm++;
    
    char* style[] = {newLine.stroke};
    char name[] = {"Line"};
    int values[] = {nbForm, newLine.x1, newLine.x2, newLine.y1, newLine.y2};
    listName = insertHeadName(listName, name);
    listValue = insertHeadValue(listValue, values);
    listStyle = insertHeadStyle(listStyle, style);

    return nbForm;
}

void viewLine(NodeValue* liveValue, NodeName* liveName, NodeStyle* liveStyle)
{
    char* actualName = liveName->data;
    int* actualTab = liveValue->data;
    char** actualStyle = liveStyle->data;
    printf("%d ", actualTab[0]);
    printf("%s ", actualName);
    printf("with the first point being at coordinate x:%d and y:%d and the second point at coordinate x:%d and y:%d and with a stroke color of %s\n", actualTab[1], actualTab[2], actualTab[3], actualTab[4], actualStyle[0]);
}

int rectangle(int nbForm, NodeName* listName, NodeValue* listValue, NodeStyle* listStyle)
{
    rectangle_t newRectangle;

    printf("What are the coordinate x and y of the rectangle and the width and height of it\n");
    printf("Then enter the color of the stroke and the color you want to fill the shape\n");
    printf("Press Enter between each values\n");
    scanf("%d", &newRectangle.x);
    scanf("%d", &newRectangle.y);
    scanf("%d", &newRectangle.width);
    scanf("%d", &newRectangle.height);
    scanf("%s", newRectangle.fill);
    scanf("%s", newRectangle.stroke);
    nbForm++;
    
    char* style[] = {newRectangle.fill, newRectangle.stroke};
    int values[] = {nbForm, newRectangle.x, newRectangle.y, newRectangle.width, newRectangle.height};
    char name[] = {"Rectangle"};
    listName = insertHeadName(listName, name);
    listValue = insertHeadValue(listValue, values);
    listStyle = insertHeadStyle(listStyle, style);

    return nbForm;
}

void viewRectangle(NodeValue* liveValue, NodeName* liveName, NodeStyle* liveStyle)
{
    char* actualName = liveName->data;
    int* actualTab = liveValue->data;
    char** actualStyle = liveStyle->data;
    printf("%d ", actualTab[0]);
    printf("%s ", actualName);
    printf("at coordinate x:%d and y:%d and with a width of %d and a height of %d with the stroke color of %s and fill color of %s\n", actualTab[1], actualTab[2], actualTab[3], actualTab[4], actualStyle[0], actualStyle[1]);
}

/* à faire si le temps
int polygon(void)
{
    polygon_t newPolygon;
    newPolygon.x;
    newPolygon.y;
    newPolygon.radius;

    printf("What are the coordinate x and y of the circle and the radius\n");
    printf("Press Enter between each values\n");
    scanf("%d", &newCircle.x);
    scanf("%d", &newCircle.y);
    scanf("%d", &newCircle.radius);
}
*/