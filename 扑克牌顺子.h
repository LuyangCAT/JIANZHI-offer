//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_扑克牌顺子_H
#define OFFER_扑克牌顺子_H

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
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()==0)
            return false;
        sort(numbers.begin(),numbers.end());//先排序，这样就直接能计算每两个数之间的gap了
        int numOf0=0,gap=0;
        for(int i=0;i<numbers.size();i++){
            if(numbers[i]==0){//0的个数
                numOf0++;
                continue;
            }
            if(numbers[i+1] == numbers[i])//前后相等肯定不行，返回错误
                return false;
            if(numbers[i+1]-numbers[i]>1)//间隔的个数
                gap+=numbers[i+1]-numbers[i]-1;
        }
        if(gap>numOf0)
            return false;
        else
            return true;
    }
};
#endif //OFFER_扑克牌顺子_H
