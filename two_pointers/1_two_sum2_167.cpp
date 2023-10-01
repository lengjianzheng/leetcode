/*
给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。
以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。
你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
你所设计的解决方案必须只使用常量级的额外空间。

 
示例 1：
输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
*/
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
解题思路:
1, 有序的数组，通过双指针的移动过滤错误的选项，缩小范围。
难点: 证明过滤的选项都是不正确的。
*/
class Solution {
public:
    // 时间复杂度O(N)
    // 空间复杂度O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int index2 = numbers.size() - 1;
        while (index1 < index2) {
            if (numbers[index1] + numbers[index2] == target) {
                return {index1+1, index2+1};
            }
            if (numbers[index1] + numbers[index2] < target) {
                // (index1, [index1 + 1, ...index2])的选项都是不符合条件的，可以排除, index1 加 1.
                index1++;
            } else {
                index2--;
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> v({2,7,11,15});
    auto res = s.twoSum(v, 9);
    cout << "res:" << res.size() << endl;
    return 0;
}