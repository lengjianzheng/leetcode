/*
描述:
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。
子数组是数组中元素的连续非空序列。

示例 1：
输入：nums = [1,1,1], k = 2
输出：2

示例 2：
输入：nums = [1,2,3], k = 3
输出：2
*/
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
解题思路:
1, 暴力解法: 遍历所有的子数组的和。通过遍历下标为i结尾的子数组，依次遍历所有的子数组。
2, 问题转化: 计算以i结尾的[0,1..i]的数组的和。求为i结尾的子数组的和为k，转成小于i的下标j中，[0, 1,..j]的和为sum[0,1..i] - k的下标个数。
可以定义一个哈希表，key为和(sum[0,1..j], j < i)，value次数.
*/
class Solution {
public:
    // 时间复杂度O(N ^ 2), 超时
    // 空间复杂度O(1)
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j >= 0; j--) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }

    // 时间复杂度O(N)
    // 空间复杂度O(N)
    int subarraySum2(vector<int>& nums, int k) {
        int count = 0;
        // hash， key是[0,1.. j]的和, j小于i。value是和的次数
        unordered_map<int, int> hash;
        // 累加和, 不断添加hash表中
        int sum = 0;
        // 查找以i结尾的子数组和为k的数量
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            // 分为两种情况，1: sum[0, 1, 2 .. i] = k
            if (sum == k) {
                count++;
            }
            // 2: sum[j + 1, j + 2 .. i] = k, 即 sum[0, 1 ... j] = sum - k
            if (hash.find(sum - k) != hash.end()) {
                count += hash[sum - k];
            }
            hash[sum] += 1;
        }
        return count;
    }
};

int main() {
    Solution s;
    return 0;
}