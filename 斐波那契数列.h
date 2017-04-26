//
// Created by CAO Luyang on 2017/4/26.
//
/*
 * 7.斐波那契数列
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
    n<=39
 */
#ifndef OFFER_FIBONACCI_H
#define OFFER_FIBONACCI_H

class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0)return 0;
        if (n <= 2)return 1;

        int n1 = 1, n2 = 1;
        for (int i = 3; i <= n; i++) {
            n2 = n1 + n2;
            n1 = n2 - n1;
        }
        return n2;
    }
};
#endif //OFFER_FIBONACCI_H
