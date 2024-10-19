class Solution {
public:
    char findKthBit(int n, int k) {
        if(k == 1) return '0';
        string binString = "0", tempString;

        for(int i = 2; i <= n; i++) {
            tempString = binString;
            int length = tempString.size();
            
            for(int j = 0; j < length; j++) {
                if(tempString[j] == '1') tempString[j] = '0';
                else tempString[j] = '1';
            }
            reverse(tempString.begin(), tempString.end());
            binString.push_back('1');
            binString += tempString;
        }

        return binString[k - 1];
    }
};
