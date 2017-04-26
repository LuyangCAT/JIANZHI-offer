//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_平衡二叉树_H
#define OFFER_平衡二叉树_H

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
private:
    bool isAVL=true;
public:
    bool IsBalanced_Solution(TreeNode* p) {
        if(NULL == p)//空树也是平衡二叉树，这是定义
            return true;
        getDepth(p);
        return isAVL;
    }

    int getDepth(TreeNode* p){//在求树的深度的过程中每一步都判断一次是否为平衡二叉树
        if(NULL == p)
            return 0;
        int left=1;
        int right=1;
        left+=getDepth(p->left);
        right+=getDepth(p->right);
        if(abs(left-right)>1)//当左右子树的深度超过1时将isAVL变成false
            isAVL=false;

        return left>right?left:right;
    }
};
#endif //OFFER_平衡二叉树_H
