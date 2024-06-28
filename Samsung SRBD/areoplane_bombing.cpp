#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<unordered_map>
#include<set>



using namespace std;

#define all(x) x.begin(), x.end()
#define ll long long

int dp[20][5];
int Case = 1,i,n,mxlvl;
vector<vector<int>>sp,tmp;
vector<int>vc;
int solve(int lvl, int cur){
    
    if(cur<0 || cur>4)return 0;
    if(lvl > n)return 0;

    if(tmp[lvl][cur] == 2)return 0;


    if(dp[lvl][cur] != -1)return dp[lvl][cur];


    ll ret1 = 0, ret2 = 0, ret3 = 0;

    ret1 = solve(lvl+1,cur)+tmp[lvl][cur];
    if(cur - 1 >= 0 )ret2 = solve(lvl+1,cur-1)+tmp[lvl][cur];
    if(cur + 1 <= 4 )ret3 = solve(lvl+1,cur+1)+tmp[lvl][cur];

    dp[lvl][cur]=max({ret1,ret2,ret3});


    return dp[lvl][cur];


}





int main()
{
#ifndef ONLINE_JUDGE
     freopen("input.cpp", "r", stdin);
     //freopen("output.cpp" , "w" , stdout);
#endif
    int T;
    cin>>T;
    
    for(Case = 1;Case<=T;Case++){
        cin>>n;
        sp.clear();
        vc.clear();
        for(i=0;i<n;i++){
            vc.clear();

            for(int j = 0; j < 5; j++){
                int x;
                cin>>x;
                vc.push_back(x);
            }
            sp.push_back(vc);
        }
        vc.clear();
        for(i=0;i<5;i++){
            vc.push_back(0);
        }
        sp.push_back(vc);
        vc.clear();
        mxlvl = n;
        reverse(all(sp));
        
        int ans = 0;
        for(i=1;i<=n;i++){
            tmp=sp;
            for(int j=i;j<min(i+5,n+1);j++){
                for(int k=0;k<5;k++){
                    if(tmp[j][k] == 2)tmp[j][k]=0;
                }
            }

            
            memset(dp,-1,sizeof(dp));

            ans = max(ans,solve(0,2));
        }


        cout<<"#"<<Case<<" : "<<ans<<endl;

        
    }
}