/*
你的面前有一堵矩形的、由 n 行砖块组成的砖墙。这些砖块高度相同（也就是一个单位高）但是宽度不同。每一行砖块的宽度之和相等。
你现在要画一条 自顶向下 的、穿过 最少 砖块的垂线。如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。
给你一个二维数组 wall ，该数组包含这堵墙的相关信息。其中，wall[i] 是一个代表从左至右每块砖的宽度的数组。你需要找出怎样画才能使这条线 穿过的砖块数量最少 ，并且返回 穿过的砖块数量 。
输入：wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
输出：2
*/
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
解题思路:
1, 对问题进行抽象，转换成求每一行累加值，相同累加值中，最多的数量。用hash存放累加值，方便快速查找。
*/
class Solution {
public:
    // 这是一开始自己做的
    int leastBricks2(vector<vector<int>>& wall) {
        int row = 0;
        int colum = wall.size();
        vector<unordered_set<int>> vh;
        for (auto &n1 : wall) {
            unordered_set<int> h;
            int sum = 0;
            for (auto &n2 : n1) {
                sum += n2;
                h.insert(sum);
            }
            row = sum;
            vh.push_back(h);
        }
        int res = colum;
        for (auto &hash : vh) {
            for (auto &n : hash) {
                if (n == row) continue;
                int tmpColum = 0;
                for (auto &h : vh) {
                    if (h.count(n) == 0) {
                        tmpColum++;
                    }
                }
                if (tmpColum < res) {
                    res = tmpColum;
                }
            }
        }
        return res;
    }
    // 空间，时间复杂度都是 O(N*M) 即高 * 宽
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> cnt;
        for (auto& widths : wall) {
            int n = widths.size();
            int sum = 0;
            for (int i = 0; i < n - 1; i++) {
                sum += widths[i];
                cnt[sum]++;
            }
        }
        int maxCnt = 0;
        for (auto& [_, c] : cnt) {
            maxCnt = max(maxCnt, c);
        }
        return wall.size() - maxCnt;
    }
};