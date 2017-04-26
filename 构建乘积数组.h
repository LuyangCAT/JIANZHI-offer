//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_构建乘积数组_H
#define OFFER_构建乘积数组_H

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
    //---一个用于存前一部分的值，另一个用预存后一部分的值
    /*
    vector<int> multiply(const vector<int>& A) {
    	int size=A.size();
        vector<int> B;
        long long  temp=1;
        long long  res;
        for(int i=0;i<size;i++){

            long long res1 =1;
            if(i !=0)
                res1=temp*A[i-1];
            temp=res1;//temp 存着上次的乘积结果
            long long res2 =1;
            for(int j=i+1;j<size;j++){
                res2*=A[j];
            }
            res=res1*res2;
            B.push_back(res);

        }
        return B;
    }
    */

    //------另一种巧妙的解法
    /*
    解释下代码，设有数组大小为5。
对于第一个for循环
第一步：b[0] = 1;
第二步：b[1] = b[0] * a[0] = a[0]
第三步：b[2] = b[1] * a[1] = a[0] * a[1];
第四步：b[3] = b[2] * a[2] = a[0] * a[1] * a[2];
第五步：b[4] = b[3] * a[3] = a[0] * a[1] * a[2] * a[3];
然后对于第二个for循环
第一步
temp *= a[4] = a[4];
b[3] = b[3] * temp = a[0] * a[1] * a[2] * a[4];
第二步
temp *= a[3] = a[4] * a[3];
b[2] = b[2] * temp = a[0] * a[1] * a[4] * a[3];
第三步
temp *= a[2] = a[4] * a[3] * a[2];
b[1] = b[1] * temp = a[0] * a[4] * a[3] * a[2];
第四步
temp *= a[1] = a[4] * a[3] * a[2] * a[1];
b[0] = b[0] * temp = a[4] * a[3] * a[2] * a[1];
由此可以看出从b[4]到b[0]均已经得到正确计算。
*/


    vector<int> multiply(const vector<int>& A) {
        vector<int> vec;
        int sz=A.size();
        if(sz==0)
            return vec;
        vec.push_back(1);
        for(int i=0;i<sz-1;i++)
            vec.push_back(vec.back()*A[i]);
        int tmp=1;
        for(int i=sz-1;i>=0;i--)
        {
            vec[i]=vec[i]*tmp;
            tmp=tmp*A[i];
        }
        return vec;
    }


};
#endif //OFFER_构建乘积数组_H
