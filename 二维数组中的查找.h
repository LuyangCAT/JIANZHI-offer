//
// Created by CAO Luyang on 2017/4/26.
//
/*
 * --------1.二维数组中的查找
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，
 * 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */

#ifndef OFFER_FIND_H
#define OFFER_FIND_H


#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;

class Solution {
public:

    bool Find(int t, vector<vector<int> > a) {
        if (a.size() == 0)return false;
        int i = 0, j = a[0].size() - 1;//从矩阵的右上角开始搜寻

        while (i <= a.size() - 1 && j >= 0) {
            if (a[i][j] == t)//等于目标直接返回
                return true;
            if (a[i][j] > t)//大于目标向左移动减小
                j--;
            else//小于目标向右移动增加
                i++;
        }
        return false;//找不到返回错
    }

};













#endif //OFFER_FIND_H
