//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_和为S的连续正数序列_H
#define OFFER_和为S的连续正数序列_H

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
    //---每次递归的时候sum-i，而i++
    /*
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        vector<int> v;
        if(sum == 0)
            return res;
        for(int i=1;i<sum/2+1;i++){
            helper(res,sum,v,i);
        }
        return res;
    }
    void helper(vector<vector<int>> &res,int sum,vector<int> v,int i){
        if(sum == 0){
            res.push_back(v);
            return;
        }
        if(sum<0)
            return;
        v.push_back(i);
        helper(res,sum-i,v,++i);

    }
    */
    //=------暴力循环
    /*
     vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        vector<int> v;
        if(sum == 0)
            return res;

         for(int i=1;i<sum/2+1;i++){
             int count=sum;
             int j=i;
             while(count>0){
                 v.push_back(j);
                 count=count-j;
                 if(count==0){
                     res.push_back(v);
                     break;
                 }

                 j++;
             }
             v.clear();
         }
        return res;
     }
     */
    //----一种巧妙的办法---
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if(sum <= 0)
            return res;

        for(int i=1;i<sum/2+1;){//循环到一半即可
            int small=i,big=i,count=0;
            vector<int> v;
            while(count < sum){//小于目标值就加一个数，同时指向大数的指针也前移一个位置
                count+=big;
                if(count == sum){//移动过程中等于目标值时候，就从最小的指针加到最大的指针
                    for(int j=small;j<=big;j++)//big是等于号，因为每次相加后就判断，这时候big还没有更新
                        v.push_back(j);
                    res.push_back(v);
                    continue;
                }
                big++;//更新big
            }

            while(count>sum){//count小于目标值时候就从最前面减去一个最小的数
                count-=small;
                small++;//因为减去的已经不要了，所以要更新small，存储的时候也是从新的small开始存
                if(count == sum){
                    for(int j=small;j<big;j++)//因为上一次big已经加一了，所以这里不要等于号
                        v.push_back(j);
                    res.push_back(v);
                    continue;
                }
            }
            i=small+1;//因为small已经判断过了，所以下次从small加一开始

        }
        return res;
    }
};
#endif //OFFER_和为S的连续正数序列_H
