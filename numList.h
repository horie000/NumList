#ifndef NUMLIST_H
#define NUMLIST_H

typedef struct NumListNode_t NumListNode;

extern int* getVal(NumListNode* node);
extern NumListNode* getNext(NumListNode* node);
extern NumListNode* getRoot(NumListNode* node);

extern NumListNode* createListNode(int* val); //malloc
extern void delListNode(NumListNode* node); //free
extern NumListNode* createRootNode(); //rootNodeの作成

extern void add2List(NumListNode* nodeList, NumListNode* tar);
extern NumListNode* delFromList(NumListNode* root, NumListNode* tar);

//util
extern void printNode(NumListNode* node);
extern void printAllNodeINList(NumListNode* node);


//extern void setNext(NumListNode* node, NumListNode* ); //nodeの次要素を変更
#endif