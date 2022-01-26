#include<stdio.h>
#include<stdlib.h>
#include "stack_link.h"

typedef struct Node
{
    int id;
    struct Node * LeftChild;
    struct Node * Rightsibling;
}Node;
Node * root;