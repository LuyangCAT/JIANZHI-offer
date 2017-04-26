//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_栈的压入_弹出序列_H
#define OFFER_栈的压入_弹出序列_H

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
    bool IsPopOrder(vector<int> r,vector<int> c) {
        if(r.size()==0 || c.size()==0)
            return false;
        stack<int> s;
        s.push(r[0]);
        int i=0,j=0;
        while(!s.empty()){
            if(i<r.size() && c[i]==s.top()){//如果栈顶等于出栈序列的的值则出栈，指针移到下一个比较
                i++;
                s.pop();
            }
            else{//如果不相等就入栈
                j++;
                s.push(r[j]);
            }
            if(j>r.size())//当大于序列长度时说明不是对应的序列，则返回错
                return false;
        }
        return true;
    }
    //类似写法
    /*
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() || popV.empty())
            return false;
        stack<int> s;
        int index=0;
        int length=pushV.size();

        for(int i=0;i<length;i++){
            s.push(pushV[i]);
            while(!s.empty()  &&  popV[index]==s.top()){
                s.pop();
                index++;
            }
        }
        return s.empty();
    }


    */
};
#endif //OFFER_栈的压入_弹出序列_H
