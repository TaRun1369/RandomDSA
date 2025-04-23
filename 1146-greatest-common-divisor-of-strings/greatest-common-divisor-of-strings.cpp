class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int mini = min(str1.size(),str2.size());
        int maxi = max(str1.size(),str2.size());
        string ans = "";
        for(int size = 1;size<=mini;size++){
            // cout<<size<<" ";
            if(mini % size != 0 || maxi%size != 0) continue;
            int i = 0;
            string part = str1.substr(0,size);
            // cout<<part<<endl;
            int j = 0;
            while(i < maxi){
                if(i < str1.size()){
                    if(str1[i] != part[j]) break;
                }
                if(i < str2.size()){
                    if(str2[i] != part[j]) break;
                }
                i++;
                j++;
                if(j >= part.size()) j = 0;  
            }
            if(i == maxi) ans = part;
        }
        return ans;
    }
};