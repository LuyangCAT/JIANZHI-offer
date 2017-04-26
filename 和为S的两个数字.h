//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_和为S的两个数字_H
#define OFFER_和为S的两个数字_H

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
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if(array.size() == 0 || sum == 0)
            return res;
        int i=0,j=array.size()-1;
        while(i<j){//从两边向中间靠近的时候，乘积是越来越大了，所以第一对就是乘积最小的
            if(array[i]+array[j] == sum){
                res.push_back(array[i]);
                res.push_back(array[j]);
                break;
            }
            else if(array[i]+array[j] > sum)
                j--;
            else
                i++;
        }
        return res;
    }
};
#endif //OFFER_和为S的两个数字_H
