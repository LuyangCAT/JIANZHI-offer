//
// Created by CAO Luyang on 2017/4/26.
//
/*---5.用两个栈来实现一个队列
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 */

#ifndef OFFER_IMPLEMENTQUEUEWITHSTACK_H
#define OFFER_IMPLEMENTQUEUEWITHSTACK_H

#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stack>
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);//直接存入栈1
    }

    int pop() {
        if(!stack2.empty()){//如果栈2里面有数值，则直接出栈栈2的栈顶
            int temp=stack2.top();
            stack2.pop();
            return temp;
        }
        else//否则先将栈1的内容全部倒入栈2里面，然后在出栈
        {
            while(!stack1.empty()){//
                stack2.push(stack1.top());
                stack1.pop();
            }
            int temp=stack2.top();
            stack2.pop();
            return temp;
        }

    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

#endif //OFFER_IMPLEMENTQUEUEWITHSTACK_H
