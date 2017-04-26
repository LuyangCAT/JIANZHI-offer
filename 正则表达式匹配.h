//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_正则表达式匹配_H
#define OFFER_正则表达式匹配_H


class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str==nullptr || pattern==nullptr)
            return false;

        return matchCore(str,pattern);

    }

    bool matchCore(char* str, char* pattern){
        if(*str=='\0' && *pattern=='\0')
            return true;
        if(*str!='\0' && *pattern == '\0')
            return false;

        if(*(pattern+1)=='*'){
            if(*str==*pattern || (*pattern=='.' && *str!='\0'))
                return matchCore(str,pattern+2) || matchCore(str+1,pattern+2)|| matchCore(str+1,pattern);
            else
                return matchCore(str,pattern+2);
        }

        if(*str==*pattern || (*pattern=='.' && *str!='\0'))
            return matchCore(str+1,pattern+1);

        return false;
    }
};

#endif //OFFER_正则表达式匹配_H
