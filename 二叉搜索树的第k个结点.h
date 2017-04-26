//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_二叉搜索树的第K个结点_H
#define OFFER_二叉搜索树的第K个结点_H


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
    int count=1;//因为从第一个节点开始，所以下一个就是2了
    TreeNode* res=NULL;
public:

    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL || k<=0)
            return NULL;
        KthNodeHelper(pRoot,k);
        return res;
    }

    void KthNodeHelper(TreeNode* p,int k){
        if(p!=NULL){
            KthNodeHelper(p->left,k);//一直遍历到最左边的，也就是最小的值
            if(count==k){//如果已经加到k就返回当前的p
                res=p;
            }
            count++;//没有就加一
            KthNodeHelper(p->right,k);//接着遍历右边的孩子
        }
    }

};
#endif //OFFER_二叉搜索树的第K个结点_H
