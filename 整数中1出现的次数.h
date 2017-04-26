//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_整数中1出现的次数_H
#define OFFER_整数中1出现的次数_H


class Solution {
public:
    //---1.常规先求一个数中1的个数
    /*
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<=1)
            return n;
    	int sum=0;
        for(int i=1;i<=n;i++){
            sum=sum+numOfn(i);
        }
        return sum;
    }
    int numOfn(int n){
        int count =0;
        while(n>0){
            if(n%10 == 1)
                count++;
            n=n/10;
        }
        return count;
    }
    */
    //------2.先把数转成string然后统计1的个数
    /*
    int NumberOf1Between1AndN_Solution(int n){
        if(n<=1)
            return n;
        int count=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i);
            for(int j=0;j<s.length();j++){
                if(s[j] == '1')
                    count++;
            }
        }
        return count;
    }
    */
    //3.--前面的方法效率度太低，下面这个是技巧性的方法，找规律
    int NumberOf1Between1AndN_Solution(int n){
        if(n<=1)
            return n;
        int count=0;
        int base=1;
        int round=n;
        while(round>0){
            int weight=round%10;
            round=round/10;
            count=count+round*base;
            if(weight == 1)
                count+=(n%base)+1;//(n%base)是为了求当当前的为是1时，出现的1的次数取决于前面的数，这个式子就是求这个数
            else if(weight>1)
                count+=base;
            base=base*10;
        }
        return count;
    }
};
#endif //OFFER_整数中1出现的次数_H
