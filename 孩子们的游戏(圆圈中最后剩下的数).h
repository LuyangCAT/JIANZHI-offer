//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_孩子们的游戏_圆圈中最后剩下的数_H
#define OFFER_孩子们的游戏_圆圈中最后剩下的数_H


class Solution {
public:
    //------1.用队列模拟出圈的过程
    /*
    int LastRemaining_Solution(int n, int m)
    {
        if(n == 0)
            return -1;
        if(n == 1)
            return 0;
        queue<int > q;
        for(int i=0;i<n;i++)
            q.push(i);

        while(q.size() > 1){
            for(int j=0;j<m-1;j++){
                q.push(q.front());
                q.pop();
            }

            q.pop();
        }
        return q.front();
    }
    */
    //---数学方法，求出递推公式
    /*假设n个数，每隔m出圈一次，编号从零开始
    第一次出圈的索引:（m-1）%n,则下一个数的编号就是k=m%n;
     k--->0
 	 k+1--->1
 	 k+2--->2
  	 ---  ---
  	 k-2--->n-2
     此时剩下n-1个人 ，假如我们已经知道了n-1个人时，最后胜利者的编号为x，利用映射关系逆推，就可以得出n个人时，胜利者的编号为(x+k)%n（要注意的是这里是按照映射后的序号进行的）
	 其中k=m%n。
	 代入
	（x+k）%n<=>(x+(m%n))%n<=>(x%n + (m%n)%n)%n<=> (x%n+m%n)%n  <=> (x+m)%n
    	f(1)=0;
  		f(i)=(f[i-1]+m)%i;(i>1)
    */
    int LastRemaining_Solution(int n, int m){
        if(n == 0)
            return -1;
        if(n == 1)
            return 0;
        int res=0;//初始化的res为f(1)的值为0
        for(int i=2;i<=n;i++){//i在这里指的是总数，因为n得靠前面的数一个个去递归得到
            res=(res + m)%i;
        }
        return res;
    }
};
#endif //OFFER_孩子们的游戏_圆圈中最后剩下的数_H
