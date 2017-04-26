//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_把字符串转换成整数_H
#define OFFER_把字符串转换成整数_H

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
    int StrToInt(string str) {

        if(str.length()==0)
            return 0;
        long res=0;
        int i=0;
        while( str[i]=='0' || str[i]==' ')//防止前面是空格或者0
            i++;

        bool minus=false;
        if(str[i]=='+'){
            i++;
        }else if(str[i]=='-'){
            i++;
            minus=true;
        }

        for(;i<str.length();i++){
            if(str[i]<'0' || str[i]>'9')
                return 0;
            res=res*10+(str[i]-'0');
            if(res>INT_MAX){//超限了就返回最大值
                if(minus)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
        }

        if(minus)
            res=-res;
        return res;

    }


};
#endif //OFFER_把字符串转换成整数_H
