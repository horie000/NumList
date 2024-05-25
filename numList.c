#include <stdio.h>
#include <stdlib.h>
#include "numList.h"

struct NumListNode_t{
    int* val;
    struct NumListNode_t* next;
    struct NumListNode_t* root;
};

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

void delListNode(NumListNode* node){
    free(node);
}

NumListNode* createRootNode(){
    NumListNode* root = malloc(sizeof(NumListNode));
    if(root != NULL){
        root->val = NULL;
        root->next = NULL;
        root->root = root;
    }
    return root;
}

void add2List(NumListNode* nodeList, NumListNode* tar){
    NumListNode* current = nodeList->root;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = tar;
    tar->root = nodeList->root;
}

NumListNode* delFromList(NumListNode* root, NumListNode* tar){
    NumListNode* prev = root;
    NumListNode* current = root->next;
    
    while(current != NULL){
        if(*(current->val) == *(tar->val)){

            printf("prev: ");
            printNode(prev);
            printf("current: ");
            printNode(current);

            prev->next = current->next;
            return current;
        }
        current = current->next;
        prev = prev->next;
    }
    printf("can't find target\n");
    return NULL;
}

void printNode(NumListNode* node){
    int* temp = node->val;
    if(temp == NULL){
        printf("node don't have value\n");
        return;
    }
    printf("val: %d, current: %p, next: %p, root:%p\n", *(node->val), node, node->next, node->root);
}

void printAllNodeINList(NumListNode* node){
    NumListNode* current = node->root->next;
    int counter = 1;
    while(current != NULL){
        printf("---%d--- ", counter);
        printNode(current);
        if(current->next != NULL){
            current = current->next;
        }else{
            break;
        }
        counter++;
    }
    
}

int main(){
    int val = 100;
    int* valPtr = &val;
    // printf("val: %d, valPtr: %p\n", val, valPtr);
    // printf("*valPtr: %d\n", *valPtr);
    NumListNode* root = createRootNode();
    NumListNode* testNode = createListNode(valPtr);

    int val2 = 2;
    int val3 = 3;
    int* val2Ptr = &val2;
    int* val3Ptr = &val3;
    NumListNode* node2 = createListNode(val2Ptr);
    NumListNode* node3 = createListNode(val3Ptr);

    printNode(node2);
    printNode(node3);

    add2List(root, testNode);
    add2List(root, node2);
    add2List(root, node3);
    printAllNodeINList(root);

    printf("del node2\n");
    delFromList(root, node2);
    printAllNodeINList(root);
    
    return 1;

}