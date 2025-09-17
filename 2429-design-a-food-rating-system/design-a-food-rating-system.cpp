struct cmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first != b.first) 
            return a.first > b.first;  // bigger rating first
        return a.second < b.second;    // smaller string first
    }
};
class FoodRatings {
public:
        map<string,set<pair<int,string>,cmp>> Cmap;
        map<string,string> fcmap;
        map<string,int> oldr;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    //    or = ratings;
        int n = foods.size();
        for(int i = 0;i<n;i++){
            fcmap[foods[i]] = cuisines[i];
            Cmap[cuisines[i]].insert({ratings[i],foods[i]});
            oldr[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        Cmap[fcmap[food]].erase({oldr[food],food});
        Cmap[fcmap[food]].insert({newRating,food});
        oldr[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return (Cmap[cuisine].begin()->second);
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */