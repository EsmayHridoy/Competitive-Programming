// 1277. Count Square Submatrices with All Ones
// cpp solution
// O(n^3) solution

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxSquareSize = min(rows, cols);

        vector<vector<int>> prefixSum(rows + 1, vector<int>(cols + 1, 0));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                prefixSum[row + 1][col + 1] = matrix[row][col];
            }
        }

        for (int row = 1; row <= rows; row++) {
            for (int col = 1; col <= cols; col++) {
                prefixSum[row][col] += prefixSum[row - 1][col] + prefixSum[row][col - 1] - prefixSum[row - 1][col - 1];
            }
        }

        int squareCount = 0;
        for (int row = 1; row <= rows; row++) {
            for (int col = 1; col <= cols; col++) {
                for (int size = 1; size <= maxSquareSize; size++) {
                    if (row + size - 1 > rows || col + size - 1 > cols) break;

                    int totalSum = prefixSum[row + size - 1][col + size - 1];
                    totalSum -= prefixSum[row - 1][col + size - 1];
                    totalSum -= prefixSum[row + size - 1][col - 1];
                    totalSum += prefixSum[row - 1][col - 1];

                    if (totalSum == size * size) squareCount++;
                }
            }
        }

        return squareCount;
    }
};
