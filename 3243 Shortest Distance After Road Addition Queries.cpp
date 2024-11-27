// 3243. Shortest Distance After Road Addition Queries I
// Runtime Beats 84.05%
// Memory Beats 99.02%


class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int dis[n];
        int i;
        vector<int>graph[n-1];
        for(i=0;i<n;i++){
            dis[i]=n-i-1;
            if(i<n-1){
                graph[i].push_back(i+1);
            }
        }
        vector<int>ans;
        for(auto& q:queries){
            graph[q[0]].push_back(q[1]);
            for(i=n-2;i>=0;i--){
                for(auto& v:graph[i]){
                    dis[i]=min(dis[i],dis[v]+1);
                }
            }
            ans.push_back(dis[0]);
        }
        return ans;
    }
};