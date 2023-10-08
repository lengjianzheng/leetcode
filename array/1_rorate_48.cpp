/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
*/

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

/*
解题思路:
主要考察的就是1，找规律；2，对二维数组的理解
1, matrix[i][j] <- matrix[n - 1 - j][i]。 [i, j]的数据会被[n-1-j, i]点的数据替换。将二维数组划分成4个区域(注意区分奇偶数边长3或4)，遍历第一个区域的每个数据，依次交换。
2, 两次反转，左右翻转, 然后左下<->右上对角线 翻转。注意左右翻转的规律是翻转后两个点的左边之和是[n-1, n -1]
*/

class Solution {
public:
    // 注意点1： matrix[i][j] <- matrix[n - 1 - j][i]
    // 时间: O(N^2), 空间: O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) { // 注意点2：区分奇偶数，划分1/4的区域
                auto tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - i - 1][n - 1 - j];
                matrix[n - i - 1][n - 1 - j] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
            }
        }
    }

    // O(N^2), O(1)
    void rotate2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 左右翻转
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n/ 2; j++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
        // 延 左下<->右上对角线 翻转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
    }
};