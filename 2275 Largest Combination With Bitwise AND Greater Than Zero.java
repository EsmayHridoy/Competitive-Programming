// 2275. Largest Combination With Bitwise AND Greater Than Zero
// Java Solution

class Solution {
    public int largestCombination(int[] nums) {
        int ans = 1;
        for (int i = 0; i <= 24; i++) {
            int cnt = 0;
            for (int num : nums) {
                if ((num & (1 << i)) != 0) cnt++;
            }
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}
