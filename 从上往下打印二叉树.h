//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_从上往下打印二叉树_H
#define OFFER_从上往下打印二叉树_H


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
    //二叉树的层序打印(仅仅只是按照层顺序打印，但是没有分层打印)

    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp=q.front();
            res.push_back(tmp->val);
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
            q.pop();
        }
        return res;
    }

    //此方法是按照每一层输出的
    /*
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<vector<int> > res;

        if(root==NULL)
            return res;
        queue<TreeNode*> q1,q2;
        q1.push(root);
        while(!q1.empty()){
        	vector<int> r;
            while(!q1.empty()){
                TreeNode* tmp=q1.front();
                q1.pop();
                r.push_back(tmp->val);
                if(tmp->left)
                    q2.push(tmp->left);
                if(tmp->right)
                    q2.push(tmp->right);
            }
            res.push_back(r);//保存每一层的结果
            q1.swap(q2);
        }
        return res;
    }
    */
};

#endif //OFFER_从上往下打印二叉树_H
