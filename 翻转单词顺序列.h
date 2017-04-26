//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_翻转单词顺序列_H
#define OFFER_翻转单词顺序列_H

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
    //-----------栈的进出法
    /*
    string ReverseSentence(string str) {
        if(str.size() == 0)
            return str;
        stack<vector<char>> s;//利用栈后进先出的特性保存字符串并翻转
        vector<char> v;
        for(int i=0;i<str.size();i++){
            if(str[i]==' '){//每到空格就向栈中存一次单词
                s.push(v);
                v.clear();//存完向量清零，不然影响下一次存储
                continue;
            }
            v.push_back(str[i]);
        }
        s.push(v);//因为最后一次没有存，所以要单独入栈
        string a="";

        while(s.size()>1){//注意是大于1，因为最后一个后面不要空格
            v=s.top();
            for(int i=0;i<v.size();i++){
                a+=v[i]; //字符串相加构成一个单词
            }
             a+=' ';//每次构成一个单词后要加上一个空格
            s.pop();
        }

        v=s.top();//单独出栈，所有没有空格
        for(int i=0;i<v.size();i++){
                a+=v[i];
            }

        //----------这里也可不用单独列出，只需将最后一个空格赋值为空，如下：
        //res[res.size()-1]='\0';

        return a;
    }
    */
    //--------直接一个一个字符串处理
    /*
    string ReverseSentence(string str) {
        if(str.size() == 0)
            return str;
        string a="";
        string res="";
        for(int i=0;i<str.size();i++){
            if(str[i]==' '){
                res=" "+a+res;//核心，将每次得到的单词放到结果前面，然后在多加一个空格
                a="";//村单词的a每次要置空
            }
            else
           	 	a=a+str[i];//以空格为界村单词
        }
        res=a+res;//最后一个因为没有空格了，所以单独加一次

        return res;
    }
    */
    //利用翻转，先整体翻转，然后局部以空格为界翻转
    string ReverseSentence(string str) {
        if(str.size() == 0)
            return str;
        int i=0,l,r;
        reverse(str.begin(),str.end());//整体翻转
        while(i<str.size()){
            while(i<str.size() && str[i] == ' ')//空格跳过
                i++;
            l=r=i;//单词的左右下标
            while(i<str.size() && str[i] != ' '){//通过空格区分单词
                i++;
                r++;
            }
            reverse(str.begin()+l,str.begin()+r);//局部翻转

        }
        return str;
    }


};

#endif //OFFER_翻转单词顺序列_H
