//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_LISTNODE_H
#define OFFER_LISTNODE_H

#include <iostream>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):
            val(x),next(NULL){}
};
#endif //OFFER_LISTNODE_H
