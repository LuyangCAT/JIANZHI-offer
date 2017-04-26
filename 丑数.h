//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_丑数_H
#define OFFER_丑数_H

#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<7)
            return index;
        vector<int> res(index);
        res[0]=1;
        int i2=0,i3=0,i5=0;
        for(int i=1;i<index;i++){
            res[i]=min(res[i2]*2,min(res[i3]*3,res[i5]*5));//每次把上一个数以及上上一个数乘以剩下两个的参数得到的数比较出最小的
            if(res[i] == res[i2]*2)i2++;//得到当前的数后就给该参数加一
            if(res[i] == res[i3]*3)i3++;
            if(res[i] == res[i5]*5)i5++;
        }
        return res[index-1];
    }
};
#endif //OFFER_丑数_H
