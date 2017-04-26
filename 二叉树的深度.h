//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_二叉树的深度_H
#define OFFER_二叉树的深度_H

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
    //这是计算二叉树的最大深度
    int TreeDepth(TreeNode* p)
    {
        if(NULL == p)
            return 0;
        //根节点不为空则说明至少深度为1，则左右都为1
        int left=1;
        int right=1;
        left=left+TreeDepth(p->left);//递归计算左边的深度直到左边没有了子节点
        right=right+TreeDepth(p->right);
        return left>right?left:right;//每次返回最大的那个数
    }
    //下面使计算二叉树的最小深度
    int minDepth(TreeNode* p){
        if(NULL == p)
            return 0;
        int left=1;
        int right=1;
        if(p->left == NULL)
            return left;
        if(p->right == 0)
            return right;
        left+=minDepth(p->left);
        right+=minDepth(p->right);
        return left<right?left:right;
    }
};
#endif //OFFER_二叉树的深度_H
