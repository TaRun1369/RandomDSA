class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a=0,b=0;
        int pos = 1;
        while(n){
            int rem = n%10;
            if(rem == 0){
                a += (1*pos);
                b += (9*pos);
                n-=10;
            }
            else if(rem == 1 && n >= 10){
                a += 2*pos;
                b += 9*pos;
                n-=10;
            }
            else{
                a += (rem - 1)*pos;
                b += 1*pos;
            }
            pos*=10;
            n/=10;
        }

        return {a,b};


    }
};