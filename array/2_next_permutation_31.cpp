/*
整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。

例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。

例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
给你一个整数数组 nums ，找出 nums 的下一个排列。

必须 原地 修改，只允许使用额外常数空间。
*/

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

/*
解题思路:
将数组前面的一个"小数"，与后面的一个"大数"替换，然后把"小数"后面的数组降序。
1. 找"小数"：从后往前找，找到第一个变小的数
2. 找"大数"：重新从后往前找，找第一个比小数大的数字。
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 找到要替换的下标，replace之后的数组是降序(包括相等)的。
        int replace = nums.size() - 2;
        while (i >= 0 && nums[replace] >= nums[replace + 1]) {
            replace--;
        }
        // 注意全部为降序时, replace = -1
        if (replace < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // 找replace下标之后，比replace大的最小的一个数，就是要与replace替换的数字. 然后替换
        int j = nums.size() - 1;
        while (j >= 0 && nums[j] <= nums[replace]) {
            j--;
        }
        swap(nums[replace], nums[j]);
        // 将replace之后的数组反转，改为升序.
        reverse(nums.begin() + replace + 1, nums.end());
    }
};