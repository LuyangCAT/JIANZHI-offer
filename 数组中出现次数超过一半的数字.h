//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_数组中出现次数超过一半的数字_H
#define OFFER_数组中出现次数超过一半的数字_H


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
    //--------1.先排序，再取中位数即为目标数
    /*
    int MoreThanHalfNum_Solution(vector<int> n) {
        if(n.size()== 0)
            return 0;
        if(n.size() == 1)//只有一个直接返回
            return n[0];

    	sort(n.begin(),n.end());//排序
        int mid=n.size()/2;//中间位置
        int x=n[mid];//中间位置的值
        int time=0;//该位置上的值出现的次数
        for(int i=0;i<n.size();i++){//统计这个数出现的次数
            if(n[i] == x)
                time++;
        }
        if(time>mid) //大于一半说明输入的数组有效，返回中间值，否则返回0
        	return n[mid];
        else
            return 0;
    }
    */
    //-------2.使用map统计每个数出现的次数
    /*
    int MoreThanHalfNum_Solution(vector<int> n){
        if(n.size() == 0)
            return 0;
        if(n.size() == 1)
            return n[0];

        map<int,int> m;
        for(int i=0;i<n.size();i++){//依次将数组中的数存入map中，并保存每个数的次数
            m[n[i]]++;
        }
        map<int,int>::iterator it;
        int target=n.size()/2;//中间数
        for(it=m.begin();it!=m.end();it++){
            if(it->second > target)//map中的第二个数存放的是次数
                return it->first;
        }
        return 0;
    }
    */
    //----------3.改进的快排法
    int MoreThanHalfNum_Solution(vector<int> n){
        if(n.size() == 0)
            return 0;
        if(n.size() == 1)
            return n[0];

        int mid=n.size()/2;
        int begin=0,end=n.size()-1;
        int index=partition(n,begin,end);//找到一个位置，可能大于中间位置也可能小于，那就循环来找那个中间位置
        while(index != mid){				//因为使用partition 函数时返回的位置已经是排好序的位置，所以无需排序，直接找到中间位置即为所求
            if(index>mid){
                index=partition(n,begin,index-1);
            }
            else{
                index=partition(n,index+1,end);
            }
        }
        //--------这一步很重要，一定要验证输入的是否为有效数组-----
        int x=n[index];//中间位置的值
        int time=0;//该位置上的值出现的次数
        for(int i=0;i<n.size();i++){//统计这个数出现的次数
            if(n[i] == x)
                time++;
        }
        if(time>mid) //大于一半说明输入的数组有效，返回中间值，否则返回0
            return n[index];
        else
            return 0;
        //-----------------------------	------------------------
    }
    int partition(vector<int> &v,int begin,int end ){//这是快排的分开函数，无需解释
        int key=v[begin];
        int i=begin,j=end;
        while(i<j){
            while(i<j && v[j]>=key)
                j--;
            v[i]=v[j];
            while(i<j && v[i]<=key)
                i++;
            v[j]=v[i];
        }
        v[i]=key;
        return i;
    }
};

#endif //OFFER_数组中出现次数超过一半的数字_H
