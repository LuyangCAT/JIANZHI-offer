//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_按之字形顺序打印二叉树_H
#define OFFER_按之字形顺序打印二叉树_H

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

class Solution {//利用栈的后进先出特性对二叉树进行遍历
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if(pRoot==NULL)return res;

        stack<TreeNode*> s1,s2;
        s1.push(pRoot);
        while(!s1.empty() || !s2.empty()){
            vector<int> v;
            if(!s1.empty()){
                while(!s1.empty()){
                    TreeNode* tmp=s1.top();
                    v.push_back(tmp->val);
                    if(tmp->left)//先左后右
                        s2.push(tmp->left);
                    if(tmp->right)
                        s2.push(tmp->right);
                    s1.pop();
                }
                res.push_back(v);
            }
            else{
                while(!s2.empty()){
                    TreeNode* tmp=s2.top();
                    v.push_back(tmp->val);
                    if(tmp->right)//先右后左
                        s1.push(tmp->right);
                    if(tmp->left)
                        s1.push(tmp->left);
                    s2.pop();
                }
                res.push_back(v);
            }


        }
        return res;
    }

};
#endif //OFFER_按之字形顺序打印二叉树_H
