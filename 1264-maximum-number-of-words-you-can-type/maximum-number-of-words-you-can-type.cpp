class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> s;
        for(auto it : brokenLetters){
            s.insert(it);
        }

        // for(auto it : s) cout<<it<<endl;
        int n = text.size();
        int ans = 0,i = 0,wc = 0;
        bool iscurr = false;
        while(i < n){
            if(text[i] == ' '){
                wc++;
                cout<<i<<" ";
                if(iscurr == true){
                    // cout<<"true"<<endl;
                    ans++;
                } 
                iscurr = false;
                i++;
            }

            else if(s.find(text[i]) != s.end()){
                iscurr = true;
                while(i < n && text[i] != ' ') i++;
                
            }
            else{
                i++;
            }
            

        }
        wc++;
        if(iscurr == true){
                // cout<<"true"<<endl;
                ans++;
        } 
        return wc - ans;
    }
};