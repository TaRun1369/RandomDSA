// class Solution {
// public:
    
//     int longestSubsequence(string s, int k) {
//         int n = s.size();
//         vector<int> zeros(n,0);

//         int zero = 0;
//         // cout<<"dikkat ?"<<endl;
//         for(int i = 0 ;i<n;i++){

//             zeros[i] = zero;
//             // cout<<i<<"  - "<<zero<<endl;
//             if(s[i] == '0') zero++;
//         }




//                 // cout<<"dikkat 1"<<endl;

//         int val = 0;
//         int kitna = 0;
//         int j;
//         for(j = n-1;j>=0;j--){
//             if(val > k){ 
//                 kitna = j + 1;    
//                 break;
//             }
//             cout<<j <<" - "<<(n - j - 1)<<" - "<<pow(2,(n-j - 1))<<endl;
//             if(s[j] == '1')val += pow(2,(n-j - 1));

//         }
//                 // cout<<"dikkat 2"<<endl;
//         cout<<" j "<<j<<endl;
//         int z = 0;
//         if(j < n && j >= 0 ) z = zeros[kitna];
//         cout<<z<<" "<<n<<" "<<kitna<<endl;
//         return z + n - kitna - 1;
//     }
// };

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();

        // Step 1: Prefix zero count from the left
        vector<int> prefixZeros(n, 0);
        int zeroCount = 0;
        for (int i = 0; i < n; ++i) {
            prefixZeros[i] = zeroCount;
            if (s[i] == '0') zeroCount++;
        }

        // Step 2: Traverse from right to left (LSB to MSB)
        long long val = 0;
        int bit = 0;
        int indexWhereKExceeded = -1;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                if (bit < 32 && val + (1LL << bit) <= k) {
                    val += (1LL << bit);
                    bit++;
                } else {
                    indexWhereKExceeded = i;
                    break;
                }
            } else {
                bit++; // still go up in bit position (0s don’t affect value)
            }
        }

        // Step 3: Decide how many characters can be taken
        int taken = (indexWhereKExceeded == -1) ? n : (n - indexWhereKExceeded - 1);
        int zerosFromLeft = (indexWhereKExceeded == -1) ? zeroCount : prefixZeros[indexWhereKExceeded];

        return min(taken + zerosFromLeft,n);
    }
};
