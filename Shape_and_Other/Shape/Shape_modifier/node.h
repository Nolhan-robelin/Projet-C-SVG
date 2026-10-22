#ifndef NODE_H
#define NODE_H

typedef struct NodeValue {
    int* data;           
    struct NodeValue* next; 
} NodeValue;

typedef struct NodeName {
    char* data;           
    struct NodeName* next; 
} NodeName;

typedef struct NodeStyle {
    char** data;           
    struct NodeStyle* next; 
} NodeStyle;

NodeName* createNodeName(char* name);

NodeStyle* createNodeStyle(char** style);

NodeValue* createNodeValue(int* value);

NodeValue* insertHeadValue(NodeValue** head, int value[]);

NodeName* insertHeadName(NodeName** head, char name[]);

NodeStyle* insertHeadStyle(NodeStyle** head, char* name[]);

void formList(int nbForm, NodeValue* headValue, NodeName* headName, NodeStyle* headStyle);

void freeList(NodeValue** headValue, NodeName** headName, NodeStyle** headStyle);

void modifyShape(NodeValue** headValue, NodeName** headName, NodeStyle** headStyle);

#endif