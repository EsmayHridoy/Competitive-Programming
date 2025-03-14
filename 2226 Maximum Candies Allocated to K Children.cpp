class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int maxCandiesPerChild = 0;  // Stores the final answer
            int left = 1, right = 1e8, mid;  
            int n = candies.size();
            long long childrenServed;
    
            while (left <= right) {
                mid = (left + right) / 2;
                childrenServed = 0;
    
                // Calculate how many children can receive `mid` candies each
                for (int i = 0; i < n; i++) {
                    childrenServed += (candies[i] / mid);
                }
    
                // If we can serve at least `k` children, increase `mid`
                if (childrenServed >= k) {
                    left = mid + 1;
                    maxCandiesPerChild = mid;
                } 
                // Otherwise, decrease `mid`
                else {
                    right = mid - 1;
                }
            }
    
            return maxCandiesPerChild;
        }
    };
    