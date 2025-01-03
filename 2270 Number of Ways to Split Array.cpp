/**
 * Problem Statement:
 * You are given a 0-indexed integer array `nums` of length `n`.
 * 
 * A valid split at index `i` satisfies the following conditions:
 * 1. The sum of the first `i + 1` elements (left sum) is greater than or equal 
 *    to the sum of the remaining elements (right sum).
 *    i.e., leftSum >= rightSum, where:
 *      - leftSum = sum(nums[0] to nums[i])
 *      - rightSum = sum(nums[i+1] to nums[n-1])
 * 
 * 2. There is at least one element to the right of index `i`. 
 *    This implies 0 <= i < n - 1.
 * 
 * Your task is to return the number of valid splits in `nums`.
 * 
 * Example:
 * Input: nums = [10, 4, -8, 7]
 * Output: 2
 * 
 * Explanation:
 * - Split at index 0: leftSum = 10, rightSum = 3 → Valid (10 >= 3)
 * - Split at index 1: leftSum = 14, rightSum = -1 → Valid (14 >= -1)
 * - Split at index 2: leftSum = 6, rightSum = 7 → Invalid (6 < 7)
 * 
 * Constraints:
 * - 2 <= n <= 10^5
 * - -10^5 <= nums[i] <= 10^5
 * 
 * Runtime Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int startIndex = 0, nextIndex = 1;
        long leftSum = 0, rightSum = 0, resultCount = 0;
        int arraySize = nums.size();
        
        while (nextIndex < arraySize) {
            rightSum += nums[nextIndex++];
        }
        
        leftSum = nums[0];
        startIndex = 0;
        nextIndex = 1;

        while (nextIndex < arraySize) {
            if (leftSum >= rightSum) {
                resultCount++;
            }
            leftSum += nums[startIndex + 1];
            rightSum -= nums[nextIndex];
            startIndex++;
            nextIndex++;
        }

        return resultCount;
    }
};
