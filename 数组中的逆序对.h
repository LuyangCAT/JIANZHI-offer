//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_数组中的逆序对_H
#define OFFER_数组中的逆序对_H


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
    //-----1.暴力解法，每个数都跟后面的数比较一下
    /*
    int InversePairs(vector<int> data) {
        if(data.size() == 0)
            return 0;
        int count=0;
        for(int i=0;i<data.size()-1;i++){
            for(int j=i+1;j<data.size();j++){
                if(data[i]>data[j])
                    count++;
            }
        }
        return count;

    }
    */
    //----2.归并排序的类似解法
    int InversePairs(vector<int> data) {
        if(data.size() == 0)
            return 0;
        int count=helper(data,0,data.size()-1);
        return count%1000000007;

    }
    int helper(vector<int> &d,int l,int r){
        int count=0;
        if(l<r){
            int m=(l+r)/2;
            count+=helper(d,l,m);//归并改造
            count+=helper(d,m+1,r);
            count+=mergeArray(d,l,m,r);
        }
        return count%1000000007;
    }
    int mergeArray(vector<int> &d,int l,int m,int r){
        int i=l,j=m+1;
        int k=0;
        int count=0;
        int tmp[r-l+1];
        while(i<=m && j<=r){
            if(d[i]>d[j]){
                tmp[k++]=d[j++];
                count+=m-i+1;//核心，因为合并时两边肯定都是已经排好序了如：1789|2456，所以如果发生7>2，则789都>2即m-i+1;
                if(count>=1000000007)
                    count=count%1000000007;
            }
            else
                tmp[k++]=d[i++];
        }
        while(i<=m)
            tmp[k++]=d[i++];
        while(j<=r)
            tmp[k++]=d[j++];
        i=l,k=0;
        while(i<=r){
            d[i]=tmp[k];
            i++;
            k++;
        }

        return count%1000000007;
    }

};


#endif //OFFER_数组中的逆序对_H
