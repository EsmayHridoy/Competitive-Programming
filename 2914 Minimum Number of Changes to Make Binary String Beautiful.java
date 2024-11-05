// 2914. Minimum Number of Changes to Make Binary String Beautiful
// Java Solution

class Solution {
    public int minChanges(String s) {
        int n=s.length();
        int ans=0;
        int i;
        for(i=0;i<n;i+=2){
            if(s.charAt(i) != s.charAt(i+1))ans++;
        }
        return ans;
    }
}