/*
描述:
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
*/
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
解题思路:
1, 暴力解法: 两次遍历，找到目标的两个数
2, hash: 通过hash表，存放每个数需要的另一个目标数，以及当前的下标。
*/
class Solution {
public:
    // 时间复杂度O(N)
    // 空间复杂度O(N)
    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                return {i, m[nums[i]]};
            }
            m[target - nums[i]] = i;
        }
        return {};
    }

    // 时间复杂度O(N ^ 2)
    // 空间复杂度O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
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