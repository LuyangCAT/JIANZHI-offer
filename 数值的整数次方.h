//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_数值的整数次方_H
#define OFFER_数值的整数次方_H


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
    //暴力解法，注意考虑边界条件
    double Power(double base, int exponent) {
        if(exponent==0)return 1;
        double res=base;
        int e=abs(exponent);
        for(int i=1;i<e;i++){
            res=res*base;
        }
        if(exponent<0)
            res=1/res;

    return res;
    }
    //巧妙解法
    double PowerII(double base, int exponent) {
        if(base==0){//底数为零的情况返回领
            cout<<"底数不能为零！";
            return 0;
        }
        else{
            if(exponent==0)//指数为零则返回一
                return 1;
            else{
                int e=abs(exponent);//先对指数取绝对值，最后在判断是不是要给结果取倒数
                double res=1,tmp=base;
                while(e!=0){
                    if((e&1) == 1)//说明e的二进制数在此位置是1
                        res*=tmp;//每次是1的时候就累计乘在结果中
                    tmp*=tmp;//如果当前位是0则表示基数自身做的是平方的运算
                    e=e>>1;//每次右移一位
                }
                return exponent>0?res:(1/res);
            }

        }
    }
};

#endif //OFFER_数值的整数次方_H
