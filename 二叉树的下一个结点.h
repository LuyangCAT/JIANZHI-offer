//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_二叉树的下一个结点_H
#define OFFER_二叉树的下一个结点_H
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL)
            return NULL;

        if(pNode->right != NULL){//先判断右孩子
            pNode=pNode->right;//有的话就一直找到它的最左边的孩子返回
            while(pNode->left != NULL){
                pNode=pNode->left;
            }
            return pNode;
        }

        if(pNode->next ==NULL)//如果父节点为空，则返回空
            return NULL;
        if(pNode->next->left==pNode)//如果是父节点的左孩子就返回父节点
            return pNode->next;

        while(pNode->next !=NULL){//向上寻找一直找到那个父节点的左孩子是它本身的点
            if(pNode->next->left==pNode)
                return pNode->next;
            pNode=pNode->next;
        }
        return NULL;
    }
};
#endif //OFFER_二叉树的下一个结点_H
