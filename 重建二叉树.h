//
// Created by CAO Luyang on 2017/4/26.
//

/*---4.重建二叉树
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 */
#ifndef OFFER_RECONSTRUCTBINARYTREE_H
#define OFFER_RECONSTRUCTBINARYTREE_H


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
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.size() == 0)return NULL;
        TreeNode *root = new TreeNode(pre[0]);//前序遍历的第一个数为根节点
        if (pre.size() == 1)return root;

        int count;
        for (int i = 0; i < vin.size(); i++) {//从中序遍历中找到根节点之前的数，作为左子树节点
            if (vin[i] == pre[0])
                count = i;
        }


        vector<int> prel, prer, vinl, vinr;//为递归构造前序遍历和后序遍历的左右子树
        for (int i = 0; i < vin.size(); i++) {
            if (i < count)//在中序遍历中根节点之前存入左子树
                vinl.push_back(vin[i]);
            if (i > count)
                vinr.push_back(vin[i]);
        }

        for (int i = 1; i < pre.size(); i++) {//前序遍历第一个为根节点，所以从第二个数开始
            if (i <= count)//数到count个数存入左子树，剩下的存到右自述
                prel.push_back(pre[i]);
            else
                prer.push_back(pre[i]);
        }

        root->left = reConstructBinaryTree(prel, vinl);//用之前分开的左右子树分别递归根节点的左右节点
        root->right = reConstructBinaryTree(prer, vinr);

        return root;//返回根节点


    }
};

#endif //OFFER_RECONSTRUCTBINARYTREE_H
