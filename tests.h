//
// Created by Dmytro Kuzmyk on 4/15/2019.
//

#ifndef SRC_TESTS_H
#define SRC_TESTS_H

#include "bst.h"

struct bst_node {
    int val;
    int nodeHeight; // to store height of subtree rooted at node
    bst_node *left;
    bst_node *right;
};
void storeNodeHeights(bst_node *t) {
    int h;
    if(t == nullptr)
        return;

    if(t->left != nullptr){
        storeNodeHeights(t->left);
        h = t->left->nodeHeight;
    }
    if(t->right != nullptr){
        storeNodeHeights(t->left);
        if(t->left->nodeHeight > h){
            h = t->left->nodeHeight;
        }}
        t->nodeHeight = h + 1;

}

int cca(bst_node *t, int x, int y){
    if(t->val == x)
        return x;
    if(t->val == y)
        return y;
    if(x > t->val && y > t->val)
        cca(t->right, x, y);
    if(x < t->val && y < t->val)
        cca(t->left, x, y);
    return t->val;
}

bool is_heap(int a[], int n){
    int i = n/2;
    while(i>1){
        if(a[i] < a[i/2])
            return false;
        i--;
    }
    return true;
}





#endif //SRC_TESTS_H
