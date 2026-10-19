#include <stdio.h>
#include <stdlib.h>
#include "../Shape/circle.h"
#include "../Shape/elipse.h"
#include "../Shape/line.h"
#include "../Shape/rectangle.h"
#include "../Shape/Shape_modifier/node.h"

extern NodeValue* listValue;
extern NodeName* listName;
extern int nbForm;

int circle(void)
{
    circle_t newCircle;
    newCircle.x;
    newCircle.y;
    newCircle.radius;

    printf("What are the coordinate x and y of the circle and the radius\n");
    printf("Press Enter between each values\n");
    scanf("%d", &newCircle.x);
    scanf("%d", &newCircle.y);
    scanf("%d", &newCircle.radius);
    nbForm++;

    char name[] = {"Circle"};
    int values[] = {nbForm, newCircle.x, newCircle.y, newCircle.radius};
    listName = insertHeadName(listName, name);
    listValue = insertHeadValue(listValue, values);
    
}

int viewCircle(NodeValue* liveValue, NodeName* liveName)
{
    printf("%d ", liveValue[0]);
    printf("%s ", liveName[0]);
    printf("at coordinate x:%d and y:%d and with a radius of %d\n", liveValue[1], liveValue[2], liveValue[3]);
}

int elipse(void)
{
    elipse_t newElipse;
    newElipse.cx;
    newElipse.cy;
    newElipse.rx;
    newElipse.ry;

    printf("What are the coordinate x and y of the elipse and the radius at x and y coordinate\n");
    printf("Press Enter between each values\n");
    scanf("%d", &newElipse.cx);
    scanf("%d", &newElipse.cy);
    scanf("%d", &newElipse.rx);
    scanf("%d", &newElipse.ry);
    nbForm++;
    
    char name[] = {"Elipse"};
    int values[] = {nbForm, newElipse.cx, newElipse.cy, newElipse.rx, newElipse.ry};
    listName = insertHeadName(listName, name);
    listValue = insertHeadValue(listValue, values);

}

int viewElipse(NodeValue* liveValue, NodeName* liveName)
{
    printf("%d ", liveValue[0]);
    printf("%s ", liveName[0]);
    printf("at coordinate x:%d and y:%d and with a radius of %d at x axis and %d at y axis\n", liveValue[1], liveValue[2], liveValue[3], liveValue[4]);
}

int line(void)
{
    line_t newLine;
    newLine.x1;
    newLine.x2;
    newLine.y1;
    newLine.y2;

    printf("What are the coordinate x and y of the first point and the coordinate x and y of the second point\n");
    printf("Press Enter between each values\n");
    scanf("%d", &newLine.x1);
    scanf("%d", &newLine.x2);
    scanf("%d", &newLine.y1);
    scanf("%d", &newLine.y2);
    nbForm++;
    
    char name[] = {"Line"};
    int values[] = {nbForm, newLine.x1, newLine.x2, newLine.y1, newLine.y2};
    listName = insertHeadName(listName, name);
    listValue = insertHeadValue(listValue, values);

}

int viewLine(NodeValue* liveValue, NodeName* liveName)
{
    printf("%d ", liveValue[0]);
    printf("%s ", liveName[0]);
    printf("with the first point being at coordinate x:%d and y:%d and the second point at coordinate x:%d and y:%d\n", liveValue[1], liveValue[2], liveValue[3], liveValue[4]);
}

int rectangle(void)
{
    rectangle_t newRectangle;
    newRectangle.x;
    newRectangle.y;
    newRectangle.width;
    newRectangle.height;

    printf("What are the coordinate x and y of the circle and the radius\n");
    printf("Press Enter between each values\n");
    scanf("%d", &newRectangle.x);
    scanf("%d", &newRectangle.y);
    scanf("%d", &newRectangle.width);
    scanf("%d", &newRectangle.height);
    nbForm++;
    
    int values[] = {nbForm, newRectangle.x, newRectangle.y, newRectangle.width, newRectangle.height};
    char name[] = {"Rectangle"};
    listName = insertHeadName(listName, name);
    listValue = insertHeadValue(listValue, values);

}

int viewRectangle(NodeValue* liveValue, NodeName* liveName)
{
    printf("%d ", liveValue[0]);
    printf("%s ", liveName[0]);
    printf("at coordinate x:%d and y:%d and with a width of %d and a height of %d\n", liveValue[1], liveValue[2], liveValue[3], liveValue[4]);
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