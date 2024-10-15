// 2938. Separate Black and White Balls
// C++ Solution
// Runtime beats 98.95%
// Memory beats 76.42%

class Solution {
public:
    long long minimumSteps(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        long long steps = 0;
        int lastIndex = s.size() - 1;
        
        for(int i = lastIndex; i >= 0; i--) {
            if(s[i] == '1') {
                steps += (lastIndex - i);
                lastIndex--;
            }
        }

        return steps;
    }
};
