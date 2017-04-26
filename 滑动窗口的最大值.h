//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_滑动窗口的最大值_H
#define OFFER_滑动窗口的最大值_H
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
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {

        vector<int> res;
        if(size<=0)
            return res;
        int winStart=0;//初始化窗口位置
        int winEnd=size-1;
        int i=0;
        while(i<(num.size()-size+1)){
            int m=0;
            while(i<=winEnd){//在窗口内找最大值
                if(num[i]>m)
                    m=num[i];
                i++;
            }
            res.push_back(m);//将此窗口的最大值存起来
            winStart++;//更新窗口位置
            winEnd++;
            i=winStart;//下一次的i从窗口的起始开始遍历
        }
        return res;
    }
};
#endif //OFFER_滑动窗口的最大值_H
