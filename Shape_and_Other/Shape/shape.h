#ifndef SHAPE_H
#define SHAPE_H
#include "../Shape/Shape_modifier/node.h"

int circle(void);

int viewCircle(NodeValue* liveValue, NodeName* liveName);


int elipse(void);

int viewElipse(NodeValue* liveValue, NodeName* liveName);


int line(void);

int viewLine(NodeValue* liveValue, NodeName* liveName);


int rectangle(void);

int viewRectangle(NodeValue* liveValue, NodeName* liveName);


#endif