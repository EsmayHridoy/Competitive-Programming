// 2530. Maximal Score After Applying K Operations
// C++ Solution

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);

        priority_queue<int> maxHeap;
        long long totalSum = 0;

        // Push all elements of nums into the max-heap
        for (auto& num : nums) {
            maxHeap.push(num);
        }

        // Repeat the process k times
        while (k--) {
            int maxElement = maxHeap.top();
            maxHeap.pop();

            // Add the maximum element to the sum
            totalSum += maxElement;

            // Update the maximum element, then push it back into the heap
            maxElement += 2;
            maxElement /= 3;
            maxHeap.push(maxElement);
        }

        return totalSum;
    }
};
