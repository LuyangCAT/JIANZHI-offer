//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_连续子数组的最大和_H
#define OFFER_连续子数组的最大和_H

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
    //--常用方法
    /*
    int FindGreatestSumOfSubArray(vector<int> a) {
        if(a.size() == 0)
            return 0;
    	int sum=0;
        int max=INT_MIN;
        for(int i=0;i<a.size();i++){
            sum=sum+a[i];
            if(sum<0){
                sum=0;
                continue;
            }
            if(sum>max)
                max=sum;
        }
        if(sum==0){
            for(int j=0;j<a.size();j++){
                if(a[j]>max)
                    max=a[j];
            }
        }
        return max;
    }
    */
    //动态规划法
    int FindGreatestSumOfSubArray(vector<int> a) {
        if(a.size() == 0)
            return 0;
        int sum=a[0],tmpSum=a[0];
        for(int i=1;i<a.size();i++){
            tmpSum=(tmpSum>0)?tmpSum+a[i]:a[i];
            sum=(tmpSum>sum)?tmpSum:sum;
        }
        return sum;
    }
};

#endif //OFFER_连续子数组的最大和_H
