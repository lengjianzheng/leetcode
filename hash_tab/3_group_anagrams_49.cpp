/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
解题思路:
1, 通过排序的方法找到字母异位词。用到sort方法
2, 通过统计每个单词的次数找到字母异位词。1, 用到to_string(n)方法. 2, 都是小写字母，使用int array[26]; char-'a'为下标。

*/
class Solution {
public:
    // 时间复杂度O(nklogk), n=strs.size(), k=strs数组中最长的字符串的长度
    // 空间复杂度O(nk)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto &s : strs) {
            string tmp = s;
            sort(s.begin(), s.end());
            hash[s].push_back(tmp);
        }
        vector<vector<string>> res;
        for (auto &h: hash) {
            res.push_back(h.second);
        }
        return res;
    }

    // 时间复杂度O(n(k + 26)), n=strs.size(), k=strs数组中最长的字符串的长度
    // 空间复杂度O(nk)
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto &s : strs) {
            int array[26] = {0};
            for (auto c : s) {
                array[c - 'a']++;
            }
            string tmp;
            for (auto n : array) {
                tmp += to_string(n);
                tmp += string(",");
            }
            hash[tmp].push_back(s);
        }
        vector<vector<string>> res;
        for (auto &h: hash) {
            res.push_back(h.second);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}