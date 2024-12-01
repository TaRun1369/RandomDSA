class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;
        for(auto it : arr){
            if(it % 2 == 0){
                if(s.find(it/2) != s.end()) return true;
            }

            if(s.find(it*2) != s.end()) return true;

            s.insert(it);
        }
        return false;
    }
};