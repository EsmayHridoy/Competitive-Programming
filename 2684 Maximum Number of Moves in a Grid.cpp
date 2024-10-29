class Solution {
private:
    int n,m;
    int dx[3]={-1,0,1};
    int dy[3]={1,1,1};
    bool check(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(dp[i][j] != -1)return dp[i][j];
        int cnt=0;
        for(int k=0;k<3;k++){
            if(check(i+dx[k],j+dy[k]) && grid[i][j]<grid[i+dx[k]][j+dy[k]]){
                cnt=max(cnt,dfs(i+dx[k],j+dy[k],grid,dp));
            }
        }
        cnt++;

        return dp[i][j]=cnt;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            ans=max(ans,dfs(i,0,grid,dp)-1);
        }
        return ans;
    }
};