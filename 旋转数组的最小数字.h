//
// Created by CAO Luyang on 2017/4/26.
//
/*--6.旋转数组的最小数字
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

 */

#ifndef OFFER_MINNUMBERINROTATEARRAY_H
#define OFFER_MINNUMBERINROTATEARRAY_H

#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stack>
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> r) {
        if (r.size() == 0)return 0;
        int l = 0, h = r.size() - 1;
        while (l < h) {//二分查找
            int m = (l + h) / 2;
            if (r[m] > r[h])//当中间值大于最右边的值时将，说明最小值在中间值位置的后方，则窗口的左边移动到中间值位置的下一个
                l = m + 1;
            else//小于等于时，说明中间值本身或者它前方存在最小值
                h = m;
        }
        return r[h];//
    }
};
#endif //OFFER_MINNUMBERINROTATEARRAY_H
