//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_复杂链表的复制_H
#define OFFER_复杂链表的复制_H

#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* p)
    {
        if(p==NULL)
            return  NULL;

        RandomListNode* tmp=p;
        while(tmp!=NULL){//先复制一遍每一个结点，跟在每个结点的后面
            RandomListNode* s=new RandomListNode(tmp->label);
            s->next=tmp->next;
            tmp->next=s;
            tmp=s->next;
        }

        tmp=p;
        while(tmp!=NULL){//将random指针找到并赋给复制的结点
            RandomListNode* s=tmp->next;
            if(tmp->random != NULL){
                s->random=tmp->random->next;
            }
            tmp=s->next;
        }

        RandomListNode* res=p->next;
        while(p->next != NULL){//分离原始的和复制的
            tmp=p->next;
            p->next=tmp->next;
            p=tmp;
        }

        return res;
    }
};

#endif //OFFER_复杂链表的复制_H
