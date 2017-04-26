//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_二叉搜索树与双向链表_H
#define OFFER_二叉搜索树与双向链表_H


#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;

class Solution {
public:

    TreeNode* head=NULL;
    TreeNode* res=NULL;
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        convertSub(pRootOfTree);
        return res;
    }
    void convertSub(TreeNode* root){//就是一个中序遍历
        if(root== NULL)return;
        convertSub(root->left);//先找到最左边的节点
        if(head==NULL){//这时候如果头结点还没有就将该点当做头结点
            head=root;//这个指针作为遍历是一直移动的
            res=root;//这个是为了返回结果的指针
        }
        else{
            head->right=root;//上次的已经有的节点的右边追加当前结点
            root->left=head;//当前结点的前一个结点指向上次已经存在的结点
            head=root;//将当前结点变成上次结点
        }
        convertSub(root->right);//找完左边找右边的结点
    }
};

#endif //OFFER_二叉搜索树与双向链表_H
