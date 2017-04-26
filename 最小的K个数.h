//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_最小的K个数_H
#define OFFER_最小的K个数_H

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
    //----1.排序然后输出前k个
    /*
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>  res;
        if(input.size() == 0 || k==0 || k>input.size())//特别注意当k>输入数组的大小时出现的错误
            return res;
        sort(input.begin(),input.end());//排序，从小到大
        for(int i=0;i<k;i++){
            res.push_back(input[i]);//将前k个小的值存入结果数组
        }
        return res;
    }
    */
    //---2.最小堆法
    /*
     vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
         vector<int>  res;
        if(input.size() == 0 || k==0 || k>input.size())//特别注意当k>输入数组的大小时出现的错误
            return res;

         for(int i=0;i<k;i++){//先将前k个元素存入结果用来建最大堆
             res.push_back(input[i]);
         }

         make_heap(res.begin(),res.end(),less<int>());//建堆，greater为最小堆顶less为最大堆

         for(int i=k;i<input.size();i++){//然后从k以后的数依次与最大堆顶比较
             if(input[i]<res.front()){//小于堆顶的话就去电堆顶，然后替换后再次调整为最大堆
                 pop_heap(res.begin(),res.end(),less<int>());//删去堆顶并存在了vector的末尾
                 res.pop_back();//因为堆底层是vector，还要删掉末尾刚刚替换掉的那个
                 res.push_back(input[i]);//将新来的最小值存进向量
                 push_heap(res.begin(),res.end(),less<int>());//进入对并调整
             }
         }
         sort_heap(res.begin(),res.end(),greater<int>());//当所有数遍历完以后，对最大堆排序，也就是失去了堆的属性，成为排序的vector
         return res;
     }
    */
    //---3.快排类似的二分查找
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>  res;
        if(input.size() == 0 || k==0 || k>input.size())//特别注意当k>输入数组的大小时出现的错误
            return res;

        int begin=0,end=input.size()-1;
        int index=partition(input,begin,end);
        while(index != k-1){//类似的二分查找
            if(index > k-1){
                end=index-1;
                index=partition(input,begin,end);
            }
            else{
                begin=index+1;
                index=partition(input,begin,end);
            }
        }

        for(int i=0;i<k;i++){//存入结果中
            res.push_back(input[i]);
        }
        return res;

    }

    int partition(vector<int> &a,int begin,int end){//快排最经典的分开函数
        int key=a[begin];
        int i=begin,j=end;
        while(i<j){
            while(i<j && a[j]>=key)
                j--;
            a[i]=a[j];
            while(i<j && a[i]<=key)
                i++;
            a[j]=a[i];
        }
        a[i]=key;
        return i;
    }
};

#endif //OFFER_最小的K个数_H
