/*
https://www.youtube.com/watch?v=IFNibRVgFBo - Tushar Roy

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.
Input: [3,1,5,8]
Output: 167 
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

        mul*=vc[i];
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