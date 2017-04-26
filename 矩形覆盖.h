//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_矩形覆盖_H
#define OFFER_矩形覆盖_H


class Solution {//通向公式是f(n)=f(n-1)+f(n-2)，而且当横着放一块的时候另一块横着的也是定了的
public:
    int rectCover(int n) {
        if(n<=2)return n;

        int n1=1,n2=2;
        while(n>2){
            n2=n1+n2;
            n1=n2-n1;
            --n;
        }
        return n2;
    }
};

#endif //OFFER_矩形覆盖_H
