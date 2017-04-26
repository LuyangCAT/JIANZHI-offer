//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_二叉树中和为某一值的路径_H
#define OFFER_二叉树中和为某一值的路径_H


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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        vector<int> v;
        if(root==NULL)
            return res;
        helper(root,res,v,expectNumber);
        return res;
    }
    void helper(TreeNode* r,vector<vector<int> > &res,vector<int> v,int e){
        if(NULL==r)
            return;

        if(NULL==r->right && NULL == r->left){//因为路径的定义是根到叶子节点形成的路径，所以半路符合情况的不算在内
            if(r->val == e){
                v.push_back(r->val);
                res.push_back(v);
            }
        }
        v.push_back(r->val);
        helper(r->left,res,v,e-r->val);
        helper(r->right,res,v,e-r->val);
    }
};
#endif //OFFER_二叉树中和为某一值的路径_H
