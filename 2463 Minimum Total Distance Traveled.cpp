// 2463. Minimum Total Distance Traveled
// cpp solution
// runtime beats 72.41%
// memory beats 53.75%

#define ll long long
ll dp[101][101][101];
ll findMinimumDistance(int robotIndex, int factoryIndex, int currentCount, vector<int>& robots, vector<vector<int>>& factories) {
    if (robotIndex < 0) return 0;
    if (factoryIndex < 0) return 2e15;
    if (dp[robotIndex][factoryIndex][currentCount] != -1) return dp[robotIndex][factoryIndex][currentCount];
    ll result = findMinimumDistance(robotIndex, factoryIndex - 1, 0, robots, factories);
    if (currentCount < factories[factoryIndex][1]) {
        result = min(result, abs(robots[robotIndex] - factories[factoryIndex][0]) + findMinimumDistance(robotIndex - 1, factoryIndex, currentCount + 1, robots, factories));
    }
    return dp[robotIndex][factoryIndex][currentCount] = result;
}
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        sort(robots.begin(), robots.end());
        sort(factories.begin(), factories.end());
        int numRobots = robots.size();
        int numFactories = factories.size();
        memset(dp, -1, sizeof(dp));
        ll minimumDistance = findMinimumDistance(numRobots - 1, numFactories - 1, 0, robots, factories);
        return minimumDistance;
    }
};
