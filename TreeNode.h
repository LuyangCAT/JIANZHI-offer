//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_TREENODE_H
#define OFFER_TREENODE_H

#include <iostream>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):
            val(x),left(NULL),right(NULL){}
};

#endif //OFFER_TREENODE_H
