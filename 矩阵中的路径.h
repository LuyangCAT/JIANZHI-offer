//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_矩阵中的路径_H
#define OFFER_矩阵中的路径_H

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
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(str==NULL || rows<=0 || cols<=0)
            return false;
        bool *visited=new bool[rows*cols]();
        for(int i=0;i<rows*cols;i++)
            visited[i]=false;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(helper(matrix, rows,  cols,  str,i, j, visited))
                    return true;
                visited[i*cols+j]=false;//如果这个点开始的路径没找到和原始字符串匹配的就将该点的访问状态复原
            }
        }
        return false;
    }

    bool helper(char* matrix, int rows, int cols, char* str,int i,int j, bool *visited){
        if(*str=='\0')
            return true;//将字符完全遍历完成
        int index=i*cols+j;
        if(i>=0 && i<rows && j>=0 && j<cols && (matrix[index] == (*str)) && !visited[index])
        {
            visited[index]=true;
            return (//上下左右都寻找
                    helper(matrix, rows, cols, str+1,i+1, j, visited)
                    ||helper(matrix, rows, cols, str+1,i-1, j, visited)
                    ||helper(matrix, rows, cols, str+1,i, j+1, visited)
                    ||helper(matrix, rows, cols, str+1,i, j-1, visited)
            );//上
        }
        else{
            return false;
        }



    }

};
#endif //OFFER_矩阵中的路径_H
