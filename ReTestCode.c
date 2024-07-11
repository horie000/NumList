#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "numList.h" // Assuming this header file is provided

void test_numList_functions()
{
    // Test createListNode function
    int value1 = 10;
    NumListNode *node1 = createListNode(&value1);
    assert(node1 != NULL);
    assert(*(node1->val) == value1);
    assert(node1->next == NULL);
    assert(node1->root == NULL);
    delListNode(node1);

    // Test createRootNode function
    NumListNode *root = createRootNode();
    assert(root != NULL);
    assert(root->val == NULL);
    assert(root->next == NULL);
    assert(root->root == root);

    // Test add2List function
    int value2 = 20;
    NumListNode *node2 = createListNode(&value2);
    add2List(root, node2);
    assert(root->next == node2);
    assert(node2->root == root);
    delListNode(node2);

    // Test delFromList function
    NumListNode *node3 = createListNode(&value1); // Reusing value1
    add2List(root, node3);
    NumListNode *deletedNode = delFromList(root, node3);
    assert(deletedNode == node3);
    assert(root->next == NULL);
    delListNode(node3);

    // Test printNode and printAllNodeINList functions (manual inspection required)
    // You may redirect stdout to capture print output for detailed verification
    int value4 = 30;
    NumListNode *node4 = createListNode(&value4);
    add2List(root, node4);
    printf("Printing node 4:\n");
    printNode(node4);
    printf("Printing all nodes:\n");
    printAllNodeINList(root);

    // Clean up memory
    delListNode(root);
}

int main()
{
    test_numList_functions();
    printf("All tests passed successfully!\n");
    return 0;
}
