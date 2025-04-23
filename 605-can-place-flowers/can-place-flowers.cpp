class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        // if(fb.size() == )
        if(fb[0] == 0 && (fb.size() == 1 || fb[1] == 0)){ fb[0] = 1; n--;}
        for(int i = 1;i<fb.size() - 1;i++){
            if(n <= 0) return true;
            if(fb[i] == 0 && fb[i - 1] == 0 && fb[i + 1] == 0) {
                fb[i] = 1;
                n--;
            }

        }
        // cout<<n<<endl;
        int s = fb.size();
        if(fb[s - 1] == 0 && fb[s - 2] == 0) n--;
        // cout<<n<<endl;
        return n <= 0;
    }
};