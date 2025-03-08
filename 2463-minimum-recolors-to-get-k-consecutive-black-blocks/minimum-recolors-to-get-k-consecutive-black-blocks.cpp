class Solution {
public:
    int minimumRecolors(string b, int k) {
        int i = 0, j =0, n = b.size();
        int white = 0,black = 0;
        int ans = k;
        while(i<n && j < n){
            if(b[i] == 'W'){
                white++;
            }
            else{
                black++;
            }

            if(black + white == k){
                ans = min(ans , white);
                if(b[j] == 'W') white--;
                else black--;
                j++;
            }
            i++;
            
        }
        return ans;
    }
};