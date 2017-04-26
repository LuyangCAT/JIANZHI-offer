//
// Created by CAO Luyang on 2017/4/26.
//

/*----2.替换空格
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */

#ifndef OFFER_REPLACESPACE_H
#define OFFER_REPLACESPACE_H

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
    void replaceSpace(char *str, int length) {

        int spaceNum = 0;
        for (int i = 0; i != length; i++) {//找出空格的数量
            if (str[i] == ' ')
                ++spaceNum;
        }
        //cout<<spaceNum<<endl;

        int newLength = length + 2 * spaceNum;//构造替换后字符串的新长度，从后往前复制和替换
        int end = newLength - 1;//设置两个指针，第一个从新长度字符创的末尾开始向前
        int pos = length - 1;//第二个从原始字符串的末尾向前
        while (pos != end) {//循环出口是两个指针相遇
            if (str[pos] != ' ')//非空格的时候就执行复制并移动指针
                str[end--] = str[pos--];
            else {//由于是从后往前复制，所以替换的时候也是先后面的在前面的
                str[end--] = '0';
                str[end--] = '2';
                str[end--] = '%';
                pos--;//注意添加好替换内容后要移动原始的指针
            }
        }
        //int l=0;
        //while (*str++)
        //cout<<str;

    }
};

#endif //OFFER_REPLACESPACE_H
