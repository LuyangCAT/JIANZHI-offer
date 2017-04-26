//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_跳台阶_H
#define OFFER_跳台阶_H

class Solution {
public:
    int jumpFloor(int n) {
        if (n == 0)return 0;
        if (n <= 2)return n;

        else {
            int n1 = 1, n2 = 2;//跟斐波那契数列唯一的区别在于第二项是2而不是1
            while (n >= 3) {
                n2 = n1 + n2;
                n1 = n2 - n1;
                --n;
            }
            return n2;
        }
    }
};
#endif //OFFER_跳台阶_H
