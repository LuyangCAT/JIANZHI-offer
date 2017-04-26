//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_调整数组顺序使奇数位于偶数前面_H
#define OFFER_调整数组顺序使奇数位于偶数前面_H

#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stack>
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    //新建数组解法
     void reOrderArray(vector<int> &array) {
         vector<int> res;//新开辟一个数组
         for(auto i=array.begin();i!= array.end();i++){
             if(*i%2 != 0)
                 res.push_back(*i);//先将奇数存在开辟的数组中
         }
         for(auto j=array.begin();j!= array.end();j++){
             if(*j%2 == 0)
                 res.push_back(*j);//再遍历一遍将偶数存入数组中
         }
         array.clear();//将原始数组清空
         array=res;//将新建的数组赋值给原数组
     }
     //冒泡类似解法
    void reOrderArrayII(vector<int> &a) {
        for(int i=0;i<a.size();i++){
            for(int j=a.size()-1;j>i;--j){
                if(a[j]%2==1  && a[j-1]%2==0)//前偶后奇交换
                    swap(a[j],a[j-1]);
            }

        }
    }
};
#endif //OFFER_调整数组顺序使奇数位于偶数前面_H
