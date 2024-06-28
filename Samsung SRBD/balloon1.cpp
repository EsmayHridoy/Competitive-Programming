/*
There are n balloons and n bullets and each balloon is assigned with a particular number (point).
Whenever a particular balloon is shot the no of points increases by
1.the multiplication of point assigned to balloon on left and that of right side.
2.point assigned to left if no right exists
3.point assigned to right if no left exists.
4.the point assigned to itself if no other balloon exists.
 
You have to output the maximum no of points possible.
 
Input
1 2 3 4
 
Output
20
*/


#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<vector>



using namespace std;


int n,i,j,x;
int dp[2000006][30];
vector<int>vc;


int solve(int cnt, int mask)
{
    if(cnt == n){
        return 0;
    }
    if(dp[mask][cnt] != -1) return dp[mask][cnt];


    
    int tmp;
    int ret = 0;
    for(int i=0; i<n; i++){
        tmp = mask;
        int ck = 1;
        ck = ck<<i;

        

        if(tmp & ck)continue;
        tmp = mask;
        int mul = 1;
        for(int j=i-1; j>=0; j--){
            
            ck = 1<<j;
            tmp=mask;
            if(tmp&ck)continue;
            else{
                mul*=vc[j];
                break;
            }
        }
        for(int j=i+1; j<n; j++){
            ck=1;
            ck = ck<<j;
            tmp=mask;
            if(tmp&ck)continue;
            else{
                //cout<<vc[j]<<endl;
                mul*=vc[j];
                break;
            }
        }

        if(mul == 1)mul*=vc[i];
        tmp=mask;
        tmp |= 1<<i;
        ret = max(ret,solve(cnt+1,tmp)+mul);
    }

    return dp[mask][cnt]=ret;
}


int main()
{
    vc.clear();
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(i=0;i<n;i++){
        cin>>x;
        vc.push_back(x);
    }

    int ans = solve(0,0);

    cout<<ans<<endl;
}