//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_左旋转字符串_H
#define OFFER_左旋转字符串_H

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
    //----使用队列完成循环左移
    /*
    string LeftRotateString(string str, int n) {

        if(str.size() == 0 || n==0)
            return str;

        queue<char> q;
        for(int i=0;i<str.size();i++){
            q.push(str[i]);
        }
        while(n>0){
            q.push(q.front());
            q.pop();
            --n;
        }
        int j=0;
        while(!q.empty()){//将队列的内容又重新赋给原始的str
            str[j]=q.front();
            q.pop();
            j++;
        }
        return str;
    }
    */
    //----这是一个小trick通过三次翻转完成   abcdefg,3->cba|defg->cba|gfed->defg|abc
    /*
    string LeftRotateString(string str, int n) {
        if(str.size() == 0 || n<=0)
            return str;
        reverse(str.begin(),str.begin()+n);
        reverse(str.begin()+n,str.end());
        reverse(str.begin(),str.end());
        return str;
    }
    */
    //------还有一种更简洁的方法，通过截取两个字符串合并后的长度得到期望结果
    string LeftRotateString(string str,int n){
        if(str.size() == 0 || n<=0)
            return str;
        int length=str.size();
        n=n%length;//之所以这样的目的是因为当字符串长度小于给定的n的时候，通过取余得到偏移位置，可以只需要两次字符串的加和
        str+=str;
        return str.substr(n,length); //abcdef,2-> 2%6=2 ->abcdefabcdef-> ab|cdefab|cdef

    }
};

#endif //OFFER_左旋转字符串_H
