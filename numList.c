#include <stdio.h>
#include <stdlib.h>
#include "numList.h"

int* getVal(NumListNode* node){return node->val;}
NumListNode* getNext(NumListNode* node){return node->next;}
NumListNode* getRoot(NumListNode* node){return node->root;}

NumListNode* createListNode(int* val){
    NumListNode* node = malloc(sizeof(NumListNode));
    if(node != NULL){
        node->val = val;
        node->next = NULL;
        node->root = NULL;
    }
    return node;
}

NumListNode* createRootNode(){
    NumListNode* root = malloc(sizeof(NumListNode));
    if(root != NULL){
        root->val = NULL;
        root->next = NULL;
        root->root = NULL;
    }
    return root;
}

void print(NumListNode* node){
    int* temp = node->val;
    if(temp == NULL){
        printf("node don't have value\n");
        return;
    }
    printf("val: %p, next: %p, root:%p\n", *temp, node->next, node->root);
}

int main(){
    int val = 100;
    int* valPtr = &val;
    printf("val: %d, valPtr: %p\n", val, valPtr);
    printf("*valPtr: %d\n", *valPtr);
    NumListNode* root = createRootNode();
    NumListNode* testNode = createListNode(valPtr);

    if(root != NULL){
        print(root);
    }else{
        printf("root is NULL");
    }
    if(testNode != NULL){
        print(testNode);
    }else{
        printf("testNode is NULL");
    }
}