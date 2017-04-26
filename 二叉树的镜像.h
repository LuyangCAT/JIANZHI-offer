//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_二叉树的镜像_H
#define OFFER_二叉树的镜像_H

#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stack>
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;

class Solution {
public://递归解法
    /*
    void Mirror(TreeNode *p) {
		if(  p==NULL   )//根节点为空或者根节点没有孩子，则返回
            return;
        TreeNode* tmp=p->right;//交换左右节点
        p->right=p->left;
        p->left=tmp;
        Mirror(p->right);//递归右孩子
        Mirror(p->left); // 递归左孩子
    }
    */
    //将递归转换成栈的形式
    void Mirror(TreeNode *p) {
        if(p==NULL)//为空则返回
            return;

        stack<TreeNode*> s;//将根节点先入栈
        s.push(p);
        while(!s.empty()){//每次出栈一个后检查是否存在根节点，存在在继续入栈，知道遍历完所有节点
            TreeNode* tmp=s.top();
            s.pop();
            if(tmp->left !=NULL || tmp->right !=NULL){//交换左右节点
                TreeNode* tem=tmp->right;
                tmp->right=tmp->left;
                tmp->left=tem;
            }
            if(tmp->right!=NULL)
                s.push(tmp->right);
            if(tmp->left!=NULL)
                s.push(tmp->left);
        }
    }

};

#endif //OFFER_二叉树的镜像_H
