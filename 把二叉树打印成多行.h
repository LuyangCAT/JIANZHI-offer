//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_把二叉树打印成多行_H
#define OFFER_把二叉树打印成多行_H
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
    //---------普通
    /*
        vector<vector<int> > Print(TreeNode* pRoot) {
        	vector<vector<int> > res;
            if(pRoot==NULL)
                return res;

            queue<TreeNode*> q;
            q.push(pRoot);
            vector<int> v;
            int curL=1;
            int nextL=0;
            TreeNode* tmp;
            while(!q.empty()){
                tmp=q.front();
                v.push_back(tmp->val);
                q.pop();
                curL--;


                if(tmp->left){
                    q.push(tmp->left);
                    nextL++;
                }

                if(tmp->right){
                    q.push(tmp->right);
                    nextL++;
                }

                //q.pop();
                //curL--;
                if(curL==0){
                    res.push_back(v);
                    v.clear();
                    curL=nextL;
                    nextL=0;
                }
            }

            return res;
        }

    */
    //----------两个queue
    vector<vector<int> > Print(TreeNode* root) {
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
            //r.clear();
            q1.swap(q2);
        }
        return res;
    }

};

#endif //OFFER_把二叉树打印成多行_H
