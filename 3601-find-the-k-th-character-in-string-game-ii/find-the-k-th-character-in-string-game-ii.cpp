class Solution {
public:
    char kthCharacter(long long k, vector<int>& ops) {
        if(k == 1) return 'a';

        int n = ops.size();
        long long len = 1;
        long long type = -1;
        long long newk = -1;
        for(int i = 0;i<n;i++){
            len*=2;

            if(len >= k){
                type = ops[i];
                newk = k - len/2;
                break;
            }
        }

        char ch = kthCharacter(newk,ops);

        if(type == 0){
            return ch;
        }
        else{
            if(ch == 'z') return 'a';
            else return (ch + 1);
        }
    }
};