//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_机器人的运动范围_H
#define OFFER_机器人的运动范围_H




class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool *visited=new bool[rows*cols];
        for(int i=0;i<rows*cols;i++){
            visited[i]=false;
        }
        return helper(threshold,rows,cols,visited,0,0);
    }

    int helper(int threshold, int rows, int cols,bool *visited,int i,int j){
        int res=0;
        if(i<0 || i>=rows || j<0 || j>= cols
           || visited[i*cols+j] || (getNum(i)+getNum(j))>threshold){
            return res;
        }
        visited[i*cols+j]=true;
        res=1+helper(threshold,rows,cols,visited,i+1,j)
            +helper(threshold,rows,cols,visited,i-1,j)
            +helper(threshold,rows,cols,visited,i,j+1)
            +helper(threshold,rows,cols,visited,i,j-1);
        return res;

    }
    int getNum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
};
#endif //OFFER_机器人的运动范围_H
