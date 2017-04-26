//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_二进制中1的个数_H
#define OFFER_二进制中1的个数_H
class Solution {
public:
    /*//这是一种简单的解法
     int  NumberOf1(int n) {
         int count=0;
         while(n!=0){
             count++;
             n=n&(n-1);//每次n&n-1后会将n中最后一位去掉
         }
         return count;
     }
     */

    //这是一般解法
    int  NumberOf1(int n) {
        int count=0,flag=1;
        while(flag){
            if(n & flag)
                count++;
            flag=flag<<1;//通过每次把1向左移动，然后跟原数相与得到结果
        }
        return count;
    }
};
#endif //OFFER_二进制中1的个数_H
