//
// Created by CAO Luyang on 2017/4/26.
//

#ifndef OFFER_数组中重复的数字_H
#define OFFER_数组中重复的数字_H


class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false


    /*
    //------利用map完成次数统计
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length <=0)
            return false;
        for(int i=0;i<length;i++){
            if(numbers[i]>length-1 || numbers[i]<0)
                return false;
        }

        map<int,int> m;
        for(int i=0;i<length;i++){
            m[numbers[i]]++;
            if(m[numbers[i]] > 1){//如果有重复的直接就判断输出了
                *duplication=numbers[i];
                return true;
            }
        }

        return false;

    }
    */
    //-------奇妙的解法
    /*
    不需要额外的数组或者hash table来保存，题目里写了数组里数字的范围保证在0 ~ n-1 之间，
    所以可以利用现有数组设置标志，当一个数字被访问过后，可以设置对应位上的数 + n，之后再遇到相同的数时，
    会发现对应位上的数已经大于等于n了，那么直接返回这个数即可。
    */
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length <=0)
            return false;
        for(int i=0;i<length;i++){
            if(numbers[i]>length-1 || numbers[i]<0)
                return false;
        }

        for(int i=0;i<length;i++){
            int index=numbers[i];
            if(index >= length)
                index-=length;
            if(numbers[index] >= length){
                *duplication=index;
                return true;
            }
            numbers[index]+=length;
        }

        return false;
    }
};






#endif //OFFER_数组中重复的数字_H
