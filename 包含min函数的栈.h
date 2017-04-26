//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_包含MIN函数的栈_H
#define OFFER_包含MIN函数的栈_H
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
    void push(int v) {
        s1.push(v);
        if(s2.empty())
            s2.push(v);
        else{
            if(v<s2.top())
                s2.push(v);
            else
                s2.push(s2.top());//如果当前的value大于最小栈中的最小的就反复存栈顶元素
        }
    }
    void pop() {
        s1.pop();
        s2.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
private:
    stack<int> s1,s2;
};
#endif //OFFER_包含MIN函数的栈_H
