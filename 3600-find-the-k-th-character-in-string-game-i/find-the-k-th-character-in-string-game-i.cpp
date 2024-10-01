class Solution {
public:
    char kthCharacter(int k) {
        string h = "a";
        for(int i = 0;i < 10;i++){
            string dum = "";
            for(auto it : h){
                if(it != 'z')
                dum += (((it - 'a') + 1) + 'a');
                else dum += ('a');

            }
            h += dum;

        }

        return h[k - 1];
    }
};