//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_第一个只出现一次的字符_H
#define OFFER_第一个只出现一次的字符_H



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
    int FirstNotRepeatingChar(string str) {//利用map遍历一遍字符串并统计每个字符串出现的次数
        if(str.length() == 0)
            return -1;
        map<char,int> numOfchar;
        for(int i=0;i<str.length();i++){
            numOfchar[str[i]]++;
        }
        for(int j=0;j<str.length();j++){//第二次遍历找出第一个出现一次的数组
            if(numOfchar[str[j]] == 1)
                return j;
        }
        return -1;
    }
};
#endif //OFFER_第一个只出现一次的字符_H
