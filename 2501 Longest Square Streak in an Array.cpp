// 2501. Longest Square Streak in an Array
// cpp solution

class Solution {
private:
    int vis[100001];
    int solve(int num) {
        if (vis[num] == 0 || vis[num] > 1) return vis[num];
        long long square = (long long)num * num;
        if (square > 100000) return vis[num];
        return vis[num] += solve((int)square);
    }

public:
    int longestSquareStreak(vector<int>& nums) {
        memset(vis, 0, sizeof(vis));
        for (auto num : nums) vis[num] = 1;
        int ans = -1;
        for (auto num : nums) {
            int cnt = solve(num);
            if (cnt > 1) ans = max(ans, cnt);
        }
        return ans;
    }
};
