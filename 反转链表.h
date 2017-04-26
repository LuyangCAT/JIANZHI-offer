//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_反转链表_H
#define OFFER_反转链表_H

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
    //栈的解法
    /*
    ListNode* ReverseList(ListNode* p) {
        if(p==NULL || p->next==NULL)return p;//为空则返回空

        stack<ListNode*> s;
        while(p != NULL){//将链表的所有节点入栈
            s.push(p);
            p=p->next;
        }

        ListNode* tmp=new ListNode(0);//新建一个临时节点
        ListNode* res=tmp;//先将其赋给最终结果
        while(!s.empty()){//依次将栈顶续接在新建的节点之后，直到所有节点出栈完成
            tmp->next=s.top();
            tmp=tmp->next;
            s.pop();
        }
        tmp->next=NULL;//切记，最后一定要将最后一个节点的下一个指针赋为空
		return res->next;//返回新建节点的下一个
    }
    */
    //普通交换节点的办法
    ListNode* ReverseList(ListNode* p) {
        if(p==NULL || p->next==NULL)
            return p;

        ListNode* pre=NULL,*next=NULL;
        ListNode* cur=p;
        while(cur != NULL){
            next=cur->next;//先将当前结点的下一个节点存起来
            cur->next=pre;//将当前结点的下一个指针指向前面的一个节点
            pre=cur;//将当前节点变成前一个结点//
            cur=next;//将之前存起来的下一个节点变成当前节点
        }
        return pre;//因为cur这时已经是下一个了，下一个已经是空了
    }
};

#endif //OFFER_反转链表_H
