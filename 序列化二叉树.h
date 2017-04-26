//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_序列化二叉树_H
#define OFFER_序列化二叉树_H

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
    char* Serialize(TreeNode *root) {  //序列化二叉树，将数编程字符串
        ostringstream out;
        se(root,out);
        const char* cpc=out.str().c_str();
        char* pc = new char[out.str().length()+1];//足够长
        strcpy(pc,cpc);
        return pc;
    }
    void se(TreeNode* root,ostringstream &out){
        if(root){
            out<<root->val<<" ";
            se(root->left,out);
            se(root->right,out);
        }
        else
            out<<"# ";
    }
    //-------反序列化，也就是按照字符串建树的过程
    TreeNode* Deserialize(char *str) {
        istringstream in(str);
        return de(in);
    }
    TreeNode* de(istringstream &in){
        string val;
        in>>val;
        if(val=="#")return nullptr;
        TreeNode* root=new TreeNode(stoi(val));
        root->left=de(in);
        root->right=de(in);
        return root;
    }
};
#endif //OFFER_序列化二叉树_H
