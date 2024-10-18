// 2044. Count Number of Maximum Bitwise-OR Subsets
// Cpp Solution


bool CheckBit(int mask,int bit){return mask & (1<<bit);}

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int limit = (1<<n)-1;
        int mxBitOr=0;
        for(auto& num: nums){
            mxBitOr |= num;
        }
        int ans=0;
        for(int i=1;i<=limit;i++){
            int val=0;
            for(int j=0;j<n;j++){
                if(CheckBit(i,j))val|=nums[j];
                if(val == mxBitOr)break;
            }
            if(val == mxBitOr)ans++;
        }

        return ans;
    }
};