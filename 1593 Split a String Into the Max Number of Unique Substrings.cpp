// 1593. Split a String Into the Max Number of Unique Substrings
// cpp solution
// Great problem involving Strings, HashMap, and Backtracking
int n;
string s;
class Solution {
private:
    int solve(int pos, unordered_map<string, bool>& mp, string str) {
        if (pos == n){
            return 0;
        }
        str.push_back(s[pos]);
        int ret1=0;
        if(!mp[str]){
            mp[str]=true;
            ret1=solve(pos+1,mp,"")+1;
            mp[str]=false;
        }
        int ret2=solve(pos+1,mp,str);
        return max(ret1, ret2);
    }

public:
    int maxUniqueSplit(string str) {
        int ans = 1;
        s = str;
        n = s.size();
        unordered_map<string, bool> mp;
        ans = max(solve(0, mp, ""), ans);
        return ans;
    }
};
