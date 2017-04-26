

#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;

//---使用说明----
/*
 * 每次讲要使用函数的头文件包含到主函数中即可调用使用目标函数
 */
#include "丑数.h"


int main()
{
    Solution s;
    cout<<s.GetUglyNumber_Solution(8)<<endl;
    return 0;
}