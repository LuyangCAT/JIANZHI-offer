//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_数据流中的中位数_H
#define OFFER_数据流中的中位数_H


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
private:
    vector<int> min;//最小堆存储后面比较大的一半
    vector<int> max;//最大堆存储前面比较小的一半
public:
    void Insert(int num)
    {
        if((max.size()+min.size())%2 == 0){//总数是偶数插入最小堆
            if(max.size()>0 && num<max[0]){
                max.push_back(num);
                push_heap(max.begin(),max.end(),less<int>());
                num=max[0];
                pop_heap(max.begin(),max.end(),less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(),min.end(),greater<int>());
        }
        else{//总数是奇数插入最大堆
            if(min.size()>0 && num>min[0]){
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<int>());
                num=min[0];
                pop_heap(min.begin(),min.end(),greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(),max.end(),less<int>());
        }
    }

    double GetMedian()
    {

        if((max.size()+min.size())==0)return -1;
        //double res=0;
        return max.size()==min.size() ? (double)(max[0]+min[0])/2 : (double)min[0];
    }

};
#endif //OFFER_数据流中的中位数_H
