//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_求1_2_3_N_H
#define OFFER_求1_2_3_N_H

class Solution {
public:
    int Sum_Solution(int n) {//一个递归搞定
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        return n+Sum_Solution(n-1);
    }
};
#endif //OFFER_求1_2_3_N_H
