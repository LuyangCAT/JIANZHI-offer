//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_二叉搜索树的后序遍历序列_H
#define OFFER_二叉搜索树的后序遍历序列_H

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
    bool VerifySquenceOfBST(vector<int> s) {
        if(s.size()==0)
            return false;
        return helper(s,0,s.size()-1);
    }
    bool helper(vector<int> s,int l,int r){
        if(l>=r)//左边大于右边说明已经找完一遍，没找到不去符合的
            return true;
        int i;
        for(i=0;i<r;i++){//先找到比根节点大的位置，说明是右子树的开始位置
            if(s[i]>s[r])
                break;
        }
        for(int j=i;j<r;j++){//检查一下右子树中有没有不符合二叉搜索树定义的点
            if(s[j]<s[r])
                return false;//不符合返回错误
        }

        return helper(s,l,i-1) && helper(s,i,r-1);//递归查找更小的范围
    }
};
#endif //OFFER_二叉搜索树的后序遍历序列_H
