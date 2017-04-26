//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_链表中环的入口结点_H
#define OFFER_链表中环的入口结点_H

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
    //---利用set的存储唯一性
    /*
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		if(pHead==NULL || pHead->next==NULL)
            return NULL;
        set<ListNode*> s;//利用set的唯一性，如果再次插入的时候发现已经存在了就返回该节点
        while(pHead != NULL){
            if(s.find(pHead)== s.end()){
                s.insert(pHead);
                pHead=pHead->next;
        	}
            else
                return pHead;
    	}
        return NULL;
    }
    */
    //------双指针法，一个快一个慢，当两个相遇的时候说明有环，这时候在设置指针一个位于头结点，一个位于相遇节点，再次相遇就是入口
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        ListNode* fast, *slow;
        slow = fast = pHead;

        while (slow != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (slow == NULL || fast->next == NULL)
            return NULL; //没有环，返回NULL值

        ListNode *ptr1 = pHead; //链表开始点
        ListNode *ptr2 = slow; //相遇点
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1; //找到入口点

    }

};
#endif //OFFER_链表中环的入口结点_H
