//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_字符流中第一个不重复的字符_H
#define OFFER_字符流中第一个不重复的字符_H

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

class Solution
{
private:
    string str;
    int count[256]={0};
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        str=str+ch;
        count[ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i=0;i<str.length();i++){
            if(count[str[i]]==1)
                return str[i];
        }
        return '#';
    }

};
#endif //OFFER_字符流中第一个不重复的字符_H
