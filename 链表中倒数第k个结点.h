//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_链表中倒数第K个结点_H
#define OFFER_链表中倒数第K个结点_H


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
    //暴力解法
    /*
    ListNode* FindKthToTail(ListNode* p, unsigned int k) {
         int n=0;
         ListNode* tmp=p;
         while(tmp != NULL){ //注意这块不能写成while(!tmp),尽量写成不等于的形式
             n++;//求出链表的总长度
             tmp=tmp->next;
         }
         if(n<k)return NULL;//k大于n时，返回空
         for(int i=0;i<n-k;i++){
             p=p->next;
         }
         return p;
     }
     */
    //两个指针的解法
    ListNode* FindKthToTail(ListNode* p, unsigned int k) {
        ListNode* p1=p;//刚开始两个指针都指向链表头
        ListNode* p2=p;
        for(int i=0;i<k;i++){
            if(p2==NULL)//链表长度小于k则返回空
                return NULL;
            p2=p2->next;//将第二个指针向前移动k步
        }
        while(p2 != NULL){//然后再同时向前移动，直到结束
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};

#endif //OFFER_链表中倒数第K个结点_H
