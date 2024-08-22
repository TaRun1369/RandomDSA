class Solution {
public:
    int findComplement(int num) {
        int x = 1;

        while(num > x){
            x = x<<1;
            x|=1;
            

        }
        return num ^ x;
         
    }
};