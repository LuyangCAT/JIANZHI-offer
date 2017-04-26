//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_对称的二叉树_H
#define OFFER_对称的二叉树_H
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

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {

        if(pRoot==NULL)
            return true;
        return helper(pRoot->left,pRoot->right);

    }
    bool helper(TreeNode* left,TreeNode* right){
        if(left==NULL && right==NULL)return true;//都为空说明遍历完了都相等返回真
        if(left==NULL || right==NULL)return false;//有一个为空另一个不为空说明不是对称二叉树
        if(left->val == right->val)
            return helper(left->right,right->left) && helper(right->right,left->left);//递归遍历其他的
        return false;
    }

};
#endif //OFFER_对称的二叉树_H
