// class Solution {
// public:
//     bool isAlpha(char c){
//         return ((c >= 'a' && c<= 'z') || (c >= 'A' && c <= 'Z'));
//     }
//     string simplifyPath(string path) {
//         vector<string> v;
//         int skip = 0;
//         int n = path.size(); int i = n-1;
//         while(i >= 0){
//             char it = path[i];
            
//             while(i >= 0 && it == '/'){
//                 i--;
//             }
//             if(i >= 0 && path[i] == '.'){
//                 i--;
//                 while(i >= 0 && path[i] == '/') i--;    
//                 while(i>= 0 && path[i] == '.'){
//                         skip++;
//                         i--;
//                 }
//                 while(i >= 0 && path[i] == '/') i--;    
//             }
            
           
//             string t = "";
//             while(i >= 0 && isAlpha(path[i]) ){
//                 t.push_back(path[i]);
//                 i--;
//             }
//             if(skip == 0){
//             reverse(t.begin(),t.end());
//             v.push_back(t);
//             }
//             else {
//                 if(t != "")
//                 skip--;
//             }
//         }

//         string ans = "";

//         reverse(v.begin(),v.end());
//         // for(auto it : v) cout<<it<<" ";
//         // cout<<skip<<endl;
//         if(skip > 0){
//             ans += "/";
//             for(int i = 0;i<=skip;i++) ans += '.';
//         }
//         for(auto it:v){
//             if(it != ""){
//             ans += "/";
//             // ans.push_back(it);
//             ans += it;
//             }
//         }
//         if(ans == "") return "/";
//         int j = ans.size() - 1;
//         while(j >= 0 && ans[j] == '.'){ 
//             // cout<<ans<<endl;
//             j--;
//         }
//         // cout<<j<<endl;
//         string anss = ans.substr(0,j + 1); 
//         return anss;
//     }
// };

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        int n = path.size();
        for (int i = 0; i < n; ) {
            while (i < n && path[i] == '/') i++;
            string part = "";
            while (i < n && path[i] != '/') {
                part += path[i];
                i++;
            }
            if (part == "..") {
                if (!stack.empty()) stack.pop_back();
            } else if (part != "." && !part.empty()) {
                stack.push_back(part);
            }
        }
        string result = "/";
        for (int i = 0; i < stack.size(); i++) {
            if (i > 0) result += "/";
            result += stack[i];
        }
        return result;
    }
};
