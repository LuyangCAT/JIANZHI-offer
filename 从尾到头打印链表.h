//
// Created by CAO Luyang on 2017/4/26.
//

/*---3.从尾到头打印链表
 *输入一个链表，从尾到头打印链表每个节点的值。
 */
#ifndef OFFER_PRINTLISTFROMTAILTOHEAD_H
#define OFFER_PRINTLISTFROMTAILTOHEAD_H


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
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> result;
        stack<int> temp;//利用栈的特性后进先出完成从尾到头的打印

        while (head != NULL) {//入栈链表的节点值
            temp.push(head->val);
            head = head->next;
        }
        //ListNode* pNode;
        while (!temp.empty()) {//依次出栈并存入结果
            //pNode=temp.top();
            result.push_back(temp.top());
            temp.pop();

        }
        return result;
    }
};
#endif //OFFER_PRINTLISTFROMTAILTOHEAD_H
