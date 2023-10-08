/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
*/

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

/*
解决思路:
1, 滑动窗口: 维护一个滑动窗口，通过左右指针，hash表保存滑动窗口里的字符。滑动窗口不断添加和删除字符，计算滑动窗口的大小。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left = 0;
        int res = 0;
        for (int right = 0; right < s.size(); right++) {
            while (set.count(s[right])) {
                set.erase(s[left]);
                left++;
            }
            res = max(res, right - left + 1);
            set.insert(s[right]);
        }
        return res;
    }
};