//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_把数组排成最小的数_H
#define OFFER_把数组排成最小的数_H



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
    string PrintMinNumber(vector<int> n) {
        string res;
        if(n.size() == 0)
            return res;

        vector<string>  v;
        for(int i=0;i<n.size();i++){//存入数组
            string s=to_string(n[i]);//将数字转成string
            v.push_back(s);
        }

        sort(v.begin(),v.end(),campare);//给数组排序，但这个排序规则很奇特

        for(int i=0;i<v.size();i++){
            res.append(v[i]);//最后依次组合这些字符串
        }
        return res;
    }
    static  bool campare(const string &s1,const string &s2){//排序规则是两个字符串分别前后组合，哪个小就排在前面
        string a=s1+s2;
        string b=s2+s1;
        return a<b;
    }
};
#endif //OFFER_把数组排成最小的数_H
