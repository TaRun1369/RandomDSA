class Solution {
public:
    bool bol(string s,string goal,int st){
        string sst = "",send = "",gst = "",gend = "";
        send = s.substr(st,s.size() - st);
        gend = goal.substr(0,s.size() - st);
        sst = s.substr(0,st);
        gst = goal.substr(s.size() - st,st);
        if(sst == gst && send == gend) return true;
        else return false;
    }
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        // if(s[0] == goal[0]){
        //     for(int i = 1;i<s.size();i++){
        //         if(s[i] != goal[i]) return false;
        //     }
        //     return true;
        // }
        // else{
            int i = 0;
            while(i < s.size()){
                if(s[i] == goal[0]) if(bol(s,goal,i) == true) return true; 
                i++;
            }
            
            return false;
        // }
    }
};