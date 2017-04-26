//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_表示数值的字符串_H
#define OFFER_表示数值的字符串_H
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
    bool isNumeric(char* string)
    {
        int sLen=strlen(string);
        int i=0;
        int numOfdot=0;
        int numOfe=0;
        bool haveNum=false;
        if(string[i]=='-' || string[i]=='+')
            i++;
        while(i<sLen){
            if(string[i]>='0' && string[i]<='9'){
                i++;
                haveNum=true;
            }
            else if(string[i]=='.'){
                if(numOfe>0 || numOfdot>0)
                    return false;
                numOfdot++;
                i++;
            }
            else if(string[i]=='e' || string[i]=='E'){
                if(haveNum==false || numOfe>0)
                    return false;
                numOfe++;
                i++;
                if(string[i]=='-' || string[i]=='+')
                    i++;
                if(string[i]=='\0')
                    return false;
            }else
                return false;

        }

        return true;
    }

};
#endif //OFFER_表示数值的字符串_H
