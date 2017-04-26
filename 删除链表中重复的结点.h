//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_删除链表中重复的结点_H
#define OFFER_删除链表中重复的结点_H

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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        //cout<<"-----";
        ListNode* head=new ListNode(0);
        head->next=pHead;
        //cout<<"-----";
        ListNode* pre=head;
        ListNode* cur=head->next;
        //cout<<"-----";
        while(cur){

            if(cur->next && (cur->val == cur->next->val)){//前后的值相等
                while(cur->next && cur->val == cur->next->val){//一直循环到最后一个相等值
                    cur=cur->next;
                }
                cur=cur->next;//让指针指向下一个，因为要删除这些相等的值
                pre->next=cur;
            }
            else{
                pre=cur;
                cur=cur->next;
                // pre->next=cur;
            }
        }
        return head->next;
    }
};

#endif //OFFER_删除链表中重复的结点_H
