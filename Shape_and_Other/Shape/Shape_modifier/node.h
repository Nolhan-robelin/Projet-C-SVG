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

NodeName* createNodeName(char* name);

NodeValue* createNodeValue(int* value);

NodeValue* insertHeadValue(NodeValue* head, int value[]);

NodeName* insertHeadName(NodeName* head, char name[]);

void formList(NodeValue* headValue, NodeName* headName);

void freeList(int index, NodeValue* headValue, NodeName* headName);

void modifyShape(NodeValue* headValue, NodeName* headName);

#endif