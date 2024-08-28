int dirA[] = {1,-1,0,0};
int dirB[] = {0,0,1,-1};

class Solution {
public:
    int n,m;

    bool check(int i,int j){
        if(i>=n || i<0 || j>=m || j<0)return false;
        return true;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid1.size();
        m=grid1[0].size();
        int i,j;
        bool vis[n+1][m+1];
        memset(vis,false,sizeof(vis));


        int ans=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid2[i][j] == 0||vis[i][j])continue;
                int flag=1;
                queue<pair<int,int>>q;
                q.push({i,j});
                while(!q.empty()){
                    pair<int,int>u;
                    int a,b;
                    u = q.front();
                    q.pop();
                    vis[u.first][u.second]=true;
                    flag&=grid1[u.first][u.second];
                    for(int k = 0;k<4;k++){
                        a=u.first+dirA[k];
                        b=u.second+dirB[k];
                        
                        if(!check(a,b) || !grid2[a][b])continue;
                        if(vis[a][b])continue;

                        vis[a][b]=true;
                        q.push({a,b});
                        
                    }
                }

                if(flag)ans++;
            }
        }
        return ans;
    }
};