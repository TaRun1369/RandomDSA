class Solution {
public:
    bool isNumber(string s) {
        int sign  = 0;
        bool digits = false,e = false,dot = false;
        for(int i = 0;i<s.size();i++){
            char it = s[i];
            if(isdigit(it)){
                digits = true;
            }
            else if(it == '+' || it == '-'){
                if(sign == 2) return false;

                if(i > 0 && (s[i-1] != 'e' && s[i-1] != 'E' ) ) return false;

                if(i == s.size() - 1) return false;

                sign++;
            }
            else if(it == '.'){
                if(e || dot) return false;

                if(i == s.size() - 1 && !digits) return false;

                dot = true;
            }
            else if(it == 'e' ||it == 'E'){
                if(e || !digits || i == s.size() - 1) return false;
                e = true;
            }
            else return false;

        }
        return true;
    }
};