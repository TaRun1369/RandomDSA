// class Solution {
// public:
//     string mul(string f,char c){
//         int l1 = c - '0';
//         string ans = "";
//         int carry = 0 ;
//         int n = f.size();
//         for(int i = n-1;i>=0;i--){
//             int l2 = l1*(f[i] - '0');
//             l2 += carry;
//             carry = l2%10;
//             l2/=10;
//             ans.push_back(l2);
//         }

//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
//     string add(string num1,string num2){
//         int n1 = num1.size(),n2 = num2.size();
//         int i = n1 - 1,j = n2 - 1;
//         string ans = "";
//         int carry = 0;
//         while(i >= 0 && j >= 0){
//             int l1 = (num1[i] - '0') + (num2[j] - '0');
//             l1 = l1 + carry;
//             carry = l1%10;
//             l1 /= 10;
//             ans.push_back(l1);
//             i--;
//             j--;
//         }

//         while(i >= 0){ ans.push_back(num1[i]);i--;}
//         while(j >= 0){ ans.push_back(num1[j]);j--;}

//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
//     string multiply(string num1, string num2) {
//         // 123 * 456 
//         // 6 * 123 + 5*123 * 10(last mein ek zero) + 4 * 123 * 100 (last mein do zero)
//         string ans = "";
//         reverse(num2.begin(),num2.end());
//         int n = num2.size();
//         for(int i = 0;i<n;i++){
//             string one = mul(num1,num2[i]);
//             for(int j = 0;j<=i;j++){
//                 one.push_back('0');
//             }
//             ans = add(ans,one);
//         }

//         return ans;
//     }
// };
class Solution {
public:
    string mul(string f, char c) {
        int l1 = c - '0';
        string ans = "";
        int carry = 0;
        int n = f.size();
        for (int i = n - 1; i >= 0; i--) {
            int l2 = l1 * (f[i] - '0') + carry;
            ans.push_back(l2 % 10 + '0');
            carry = l2 / 10;
        }
        if (carry > 0) {
            ans.push_back(carry + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string add(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        int i = n1 - 1, j = n2 - 1;
        string ans = "";
        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int l1 = (i >= 0 ? num1[i] - '0' : 0);
            int l2 = (j >= 0 ? num2[j] - '0' : 0);
            int sum = l1 + l2 + carry;
            ans.push_back(sum % 10 + '0');
            carry = sum / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        string ans = "0";
        reverse(num2.begin(), num2.end());
        int n = num2.size();
        for (int i = 0; i < n; i++) {
            string one = mul(num1, num2[i]);
            one.append(i, '0');  // Append i zeros to the result
            ans = add(ans, one);
        }
        return ans;
    }
};
