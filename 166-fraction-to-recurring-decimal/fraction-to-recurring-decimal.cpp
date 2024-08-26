class Solution {
public:
    string fractionToDecimal(int num, int deno) {
        unordered_map<long ,int> mp;
        long lnum = abs(long(num));
        long ldeno = abs(long(deno));
        if(num == 0) return "0";

        string ans = "";
         if ((num < 0) ^ (deno < 0)) ans += "-";
        ans += to_string((lnum / ldeno));
        if(lnum % ldeno == 0) return ans;

        ans += ".";
        long r = lnum % ldeno;
        while(r != 0){
                if(mp.find(r) == mp.end()){
                mp[r] = ans.size();
                 r*=10;
                ans += to_string(r/ldeno);
                r = r%ldeno;
                
            }
            else{
                ans.insert(mp[r],"(");
                ans.push_back(')');
                break;
            }
           
            
            
        }
        return ans;
    }
};
// class Solution {
// public:
//     string fractionToDecimal(int num, int deno) {
//         unordered_map<long, int> mp;
//         long lnum = abs(long(num));
//         long ldeno = abs(long(deno));

//         string ans = "";
//         if ((num < 0) ^ (deno < 0)) ans += "-";
//         ans += to_string(lnum / ldeno);
//         long r = lnum % ldeno;
//         if (r == 0) return ans;

//         ans += ".";
//         while (r != 0) {
//             if (mp.find(r) != mp.end()) {
//                 ans.insert(mp[r], "(");
//                 ans += ")";
//                 break;
//             }

//             mp[r] = ans.size();

            
//             r *= 10;
//             ans += to_string(r / ldeno);
//             r %= ldeno;
//         }

//         return ans;
//     }
// };
