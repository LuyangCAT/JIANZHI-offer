//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_字符串的排列_H
#define OFFER_字符串的排列_H


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
    //此为非递归解法
    /*
string  next_permutation(string str){//这是求当前字符串下一个排列的函数
    int m,n;
    int l=str.length();

    for(m=l-2;m>=0;--m){//从倒数第二个开始找起
        if(str[m+1] > str[m]){//如果发现前一个数比后一个数小，则进入置换
            for(n=l-1;n>=m;--n){//在找到的这个比后一个数小的数的后面所有序列中，找出第一个大于这个小数的数
                if(str[n]>str[m])break;
            }
            swap(str[m],str[n]);//置换他们俩的位置
            reverse(str.begin()+m+1,str.end());//将此数位置后面的所有数倒序
            return str;
        }

    }
    reverse(str.begin(),str.end());
    return str;
}


vector<string> Permutation(string str) {
    vector<string> res;
    if(str.size()==0)
        return res;
    res.push_back(str);
    string a=str;
    while(next_permutation(str) != a){//循环找出每一个排列，直到和原始序列相等
        str=next_permutation(str);
        res.push_back(str);
    }
    return res;
}
*/
    //--------------------递归解法--------------------
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.size() == 0)
            return res;
        helper(str,res,0);
        return res;
    }
    void helper(string s,vector<string> &res,int begin){
        if(begin == s.size()-1){
            res.push_back(s);//当开始比较的index和字符串长度相等时，说明已经比较完成，可以存入结果向量了
            return;
        }

        for(int i=begin;i<s.size();i++){//从当前index一直兑换到字符串结束
            if(s[i]==s[begin] && i!=begin)//如果当前字符与开始字符相等则跳过
                continue;
            swap(s[i],s[begin]);  //交换开始字符与当前位置的字符
            helper(s,res,begin+1);//递归依次交换从当前字符开始的后面所有字符
        }
    }

};

/*

123 ---123------123
   |      ------132
   |---213------213
   |      ------231
   |---321------321
          ------312

*/


#endif //OFFER_字符串的排列_H
