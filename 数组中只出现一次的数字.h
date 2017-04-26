//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_数组中只出现一次的数字_H
#define OFFER_数组中只出现一次的数字_H

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
    //最基础的使用map 存储然后在一次遍历
    /*
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		if(data.size()<2)
            return;
        map<int,int> m;
        for(int i=0;i<data.size();i++){
            m[data[i]]++;
        }
        bool flag=false;
        map<int,int>::iterator it;
        for(it=m.begin();it != m.end();it++){
            if(it->second ==1 && !flag){
                *num1=it->first;
                flag=true;
            }
            if(it->second ==1 && flag)
                *num2=it->first;
        }
    }
    */
    //通过位操作实现相同的数异或是的他们都变成了0，最后剩下单独的数
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {

        int tmp=0;
        for(int i=0;i<data.size();i++){//全部异或，得到的结果是两个不同的数字的异或结果
            tmp^=data[i];//0异或任何数还是等于它本身
        }
        int index=indexOfFirst1(tmp);
        *num1=*num2=0;
        for(int i=0;i<data.size();i++){
            if(isBit(data[i],index))
                *num1^=data[i];
            else
                *num2^=data[i];
        }

    }
    int indexOfFirst1(int n){//获取异或结果中1出现的最低位
        int res=0;
        while((n&1) != 1 && res<32){//32是int型数的最大位数
            n=n>>1;
            res++;
        }
        return res;
    }
    bool isBit(int n,int index){//判断在index位是不是为1
        n=n>>index;
        return (n&1);
    }

};
#endif //OFFER_数组中只出现一次的数字_H
