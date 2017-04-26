//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_顺时针打印矩阵_H
#define OFFER_顺时针打印矩阵_H


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
    vector<int> printMatrix(vector<vector<int> > m) {
        vector<int> res;
        if(m.size()==0)
            return res;

        int row=m.size();//行数
        int col=m[0].size();//列数
        int circle=((row>col?col:row) -1)/2+1;//圈数

        for(int i=0;i<circle;i++){//圈数递增
            for(int j=i;j<col-i;j++)//从左向右打印
                res.push_back(m[i][j]);

            for(int k=i+1;k<row-i;k++)//从上往下打印
                res.push_back(m[k][col-1-i]);

            for(int p=col-1-i-1;(p>=i)&&(row-1-i !=i);p--)//特别注意：不管是横向还是纵向都不能超过中心线打到另一半，那样就重复了
                res.push_back(m[row-1-i][p]);

            for(int q=row-1-i-1;(q>i)&&(i != col-1-i);q--)//q>i即可，不用等于，因为等于i的那一行被从左向右的打过了
                res.push_back(m[q][i]);
        }
        return res;
    }
};
#endif //OFFER_顺时针打印矩阵_H
