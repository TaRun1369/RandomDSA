class Solution {
public:
    string maximumBinaryString(string b) {
        int n = b.size();
        int i = 0;
        
        while (i < n && b[i] == '1') {
            i++;
        }
        
        int zeroCount = 0, firstZeroIndex = i;
        
        while (i < n) {
            if (b[i] == '0') {
                zeroCount++;
            }
            i++;
        }
        
        if (zeroCount <= 1) {
            return b;
        }
        for (i = firstZeroIndex; i < n; i++) {
            b[i] = '1';
        }
        
        b[firstZeroIndex + zeroCount - 1] = '0';
        
        return b;
    }
};
