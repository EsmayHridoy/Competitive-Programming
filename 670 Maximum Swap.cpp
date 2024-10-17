// 670. Maximum Swap
// C++ Solution
// runtime beats 100%

class Solution {
public:
    int maximumSwap(int num) {
        // If the number is a single digit, no swap is needed.
        if (num < 10) return num;
        
        // Convert the number to a string representation for easy digit swapping.
        string numStr;
        numStr.clear();
        
        // Extract each digit and build the string representation of the number.
        while (num) {
            char digit = (num % 10) + '0';
            numStr.push_back(digit);
            num /= 10;
        }

        // Reverse the string to get the correct order of digits.
        reverse(numStr.begin(), numStr.end());
        
        // Reinitialize num to store the maximum possible number.
        num = 0;
        int length = numStr.size();
        
        // Try swapping each pair of digits and find the maximum number.
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                // Swap digits at positions i and j.
                swap(numStr[i], numStr[j]);

                // Convert the modified string back to an integer.
                int swappedNum = stoi(numStr);
                
                // Swap the digits back to their original positions.
                swap(numStr[i], numStr[j]);

                // Update num to hold the maximum number found so far.
                num = max(swappedNum, num);
            }
        }

        // Return the maximum number after trying all possible swaps.
        return num;
    }
};
