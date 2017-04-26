//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_合并两个排序的链表_H
#define OFFER_合并两个排序的链表_H


#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stack>
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;

class Solution {
public://这个最要注意的就是各种边界条件
    ListNode* Merge(ListNode* p1, ListNode* p2)
    {
        if(p1==NULL)return p2;
        if(p2==NULL)return p1;

        ListNode* l=new ListNode(0);//新建一个节点免得判断，最后直接返回新建节点的next即可
        ListNode* res = l;//一定得有这一步不然最后返回l时发现l已经指向了后面而不是原先的头部了
        while(p1 != NULL && p2 != NULL){
            if(p1->val > p2->val){
                l->next=p2;
                p2=p2->next;
                l=l->next;
            }
            else{
                l->next=p1;
                p1=p1->next;
                l=l->next;
            }
        }
        if(p1==NULL)//p2没了但p1还有
            l->next=p2;
        if(p2==NULL)
            l->next=p1;

        return res->next;
    }
};
#endif //OFFER_合并两个排序的链表_H
