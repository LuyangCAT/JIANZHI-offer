//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_树的子结构_H
#define OFFER_树的子结构_H

#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stack>
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    bool HasSubtree(TreeNode* p1, TreeNode* p2)
    {
        if(p1==NULL || p2==NULL) return false;//都为空返回错误

        if(p1->val == p2->val){//先判断根节点是否相等，不相等则直接分别判断左孩子和B以及右孩子和B，只要有一个是真就行
            if(helper(p1,p2))
                return true;
            else
                return helper(p1->left,p2)|| helper(p1->right,p2);
        }
        else{
            return helper(p1->left,p2)|| helper(p1->right,p2);
        }

    }
    bool helper(TreeNode* p1,TreeNode* p2){//在进入此函数之前已经判断过两个根植不相等的情况
        if(p2==NULL)return true;
        if(p1==NULL)return false;

        if(p1->val == p2->val){//如果根植相等就判断他们的左孩子和右孩子是否相等，全部相等才返回真，否则就返回假
            return helper(p1->left,p2->left) && helper(p1->right,p2->right);
        }
        else
            return false;
    }
};
#endif //OFFER_树的子结构_H
