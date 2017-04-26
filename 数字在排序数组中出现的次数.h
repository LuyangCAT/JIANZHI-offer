//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_数字在排序数组中出现的次数_H
#define OFFER_数字在排序数组中出现的次数_H

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
    //---使用map的解法存一遍并统计次数
    /*
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0)
            return 0;
        map<int ,int> m;

        for(int i=0;i<data.size();i++){
            m[data[i]]++;
        }
        map<int,int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            if(it->first == k)
                return it->second;
        }
        return 0;
    }
    */
    //-----二分查找类似方法
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0)
            return 0;
        int a=getRightOfk(data,k);
        int b=getLeftOfk(data,k);
        if(a>-1 && b>-1)
            return a-b+1;//最前减去最后加上1
        else
            return 0;
    }
    int getLeftOfk(vector<int> data ,int k){//获得左边的第一个k的下标
        int l=0,r=data.size()-1;

        while(l<=r){//注意是等于号，相等时刚好是所求的点
            int m=(l+r)/2;
            if(data[m] == k ){
                if(data[m-1] == k)//关键，二分查找到这里要比较前一个是否跟当前的值相等
                    r=m-1;
                else
                    return m;
            }
            else{
                if(data[m]>k)
                    r=m-1;
                else
                    l=m+1;
            }

        }
        return -1;
    }
    int getRightOfk(vector<int> data ,int k){//类似的获取最后一个k的下标
        int l=0,r=data.size()-1;

        while(l<=r){
            int m=(l+r)/2;
            if(data[m] == k ){
                if(data[m+1] == k)
                    l=m+1;
                else
                    return m;
            }
            else{
                if(data[m]>k)
                    r=m-1;
                else
                    l=m+1;
            }

        }
        return -1;
    }
};

#endif //OFFER_数字在排序数组中出现的次数_H
