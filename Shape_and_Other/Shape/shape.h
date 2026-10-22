#ifndef SHAPE_H
#define SHAPE_H
#include "../Shape/Shape_modifier/node.h"

int circle(int nbForm, NodeName*** listName, NodeValue*** listValue, NodeStyle*** listStyle);

void viewCircle(NodeValue* liveValue, NodeName* liveName, NodeStyle* liveStyle);

char* addCircle(NodeValue* listValue, NodeStyle* listStyle);


int elipse(int nbForm, NodeName*** listName, NodeValue*** listValue, NodeStyle*** listStyle);

void viewElipse(NodeValue* liveValue, NodeName* liveName, NodeStyle* liveStyle);

char* addElipse(NodeValue* listValue, NodeStyle* listStyle);


int line(int nbForm, NodeName*** listName, NodeValue*** listValue, NodeStyle*** listStyle);

void viewLine(NodeValue* liveValue, NodeName* liveName, NodeStyle* liveStyle);

char* addLine(NodeValue* listValue, NodeStyle* listStyle);


int rectangle(int nbForm, NodeName*** listName, NodeValue*** listValue, NodeStyle*** listStyle);

void viewRectangle(NodeValue* liveValue, NodeName* liveName, NodeStyle* liveStyle);

char* addRectangle(NodeValue* listValue, NodeStyle* listStyle);


#endif