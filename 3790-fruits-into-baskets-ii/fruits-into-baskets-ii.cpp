class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = b.size();
        vector<int> mark(n,0);

        for(auto it : f){
            for(int i = 0;i<n;i++){
                if(b[i] >= it && mark[i] == 0){
                    mark[i] = 1;
                    break;
                }

            }
        }

        int sum = accumulate(mark.begin(),mark.end(),0);
        return n - sum;
    }
};