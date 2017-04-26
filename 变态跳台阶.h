//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_变态跳台阶_H
#define OFFER_变态跳台阶_H

class Solution {
public:

    int jumpFloorII(int n) {
        if (n <= 2)return n;

        int sum = 3;//前两项的和
        int m;//下一项的值
        while (n >= 3) {
            m = sum + 1;//下一项等于前面所有项加上1
            sum = sum + m;//更新sum,为下下一项准备
            --n;
        }
        return m;
    }
};
#endif //OFFER_变态跳台阶_H
