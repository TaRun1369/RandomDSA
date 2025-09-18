class TaskManager {
public:
    struct cmp {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[0] != b[0]) return a[0] > b[0];   
       return a[1] > b[1];   
        // return a[2] < b[2];                    
    }
};

    set<vector<int>,cmp> s;
    map<int,pair<int,int>> mp;
    TaskManager(vector<vector<int>>& tasks) {
        

        for(auto it : tasks){
            vector<int> temp = {it[2],it[1],it[0]};
            s.insert(temp);
            mp[it[1]] = {it[2],it[0]};
        }

    }
    
    void add(int userId, int taskId, int priority) {
        // if(mp[taskId] != mp.end()) mp.erase(taskId);
        mp[taskId] = {priority,userId};
        s.insert({priority,taskId,userId});
    }
    
    void edit(int taskId, int newPriority) {
        auto old = mp[taskId];
        s.erase({old.first,taskId,old.second});
        mp[taskId] = {newPriority,old.second};
        s.insert({newPriority,taskId,old.second});
    }
    
    void rmv(int taskId) {
        auto old = mp[taskId];
        mp.erase(taskId);
        s.erase({old.first,taskId,old.second});
    }
    
    int execTop() {
        if(s.size() == 0) return -1;
        vector<int> v = *s.begin();
        rmv((*s.begin())[1]);
        return v[2];
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */