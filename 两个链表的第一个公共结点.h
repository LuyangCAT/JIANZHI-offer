//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_两个链表的第一个公共结点_H
#define OFFER_两个链表的第一个公共结点_H

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
public://此题的解法就是先比较两个链表的长度，长的先走他们的差步，之后再一起走，直到两个相等就得到了公共节点
    //如果是暴力法就是第一个链表每走一步都和第二个链表比较是否相等
    ListNode* FindFirstCommonNode( ListNode* p1, ListNode* p2) {
        if(NULL == p1 || NULL == p2)
            return NULL;
        int a=getLengthOfList(p1);
        int b=getLengthOfList(p2);
        ListNode* L=p1;
        ListNode* S=p2;
        if(a>b){
            int c=a-b;
            while(c>0){
                L=L->next;
                c--;
            }
            while(L != NULL && S != NULL && L != S){
                L=L->next;
                S=S->next;
            }
            return S;
        }
        else{
            int c=b-a;
            L=p2,S=p1;
            while(c>0){
                L=L->next;
                c--;
            }
            while(L != NULL && S != NULL && L != S){
                L=L->next;
                S=S->next;
            }
            return S;
        }
    }

    int getLengthOfList(ListNode* p){//获取链表的长度
        int count=0;
        ListNode* l=p;
        while(NULL != l){
            count++;
            l=l->next;
        }
        return count;
    }
};

#endif //OFFER_两个链表的第一个公共结点_H
