// 1671. Minimum Number of Removals to Make Mountain Array
// cpp solution
// runtime beats 66.67%
// memory beats 99.49%


class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        int dp1[n],dp2[n];
        int i,j;
        dp1[0]=1;
        for(i=1;i<n;i++){
            dp1[i]=1;
            for(j=0;j<i;j++){
                if(nums[i]<=nums[j])continue;
                dp1[i]=max(dp1[i],dp1[j]+1);
            }
        }
        int ans=0;
        dp2[n-1]=1;
        for(i=n-2;i>=0;i--){
            dp2[i]=1;
            for(j=n-1;j>i;j--){
                if(nums[i]<=nums[j])continue;
                dp2[i]=max(dp2[i],dp2[j]+1);
            }
            if(dp2[i]>1&&dp1[i]>1)ans=max(ans,dp1[i]+dp2[i]-1);
        }
        return n-ans;
    }
};