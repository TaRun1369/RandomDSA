// // class Solution {
// // public:
// //     vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
// //         map<string,int> mp;
// //         int id = 1;
// //         for(auto it : supplies){
// //             if(mp.find(it) == mp.end()){
// //                 mp[it] = id;
// //                 id++;
// //             }
// //         }

        

// //         vector<vector<int>> adj(mp.size() + recipes.size());
// //         for(int i = 0;i<recipes.size();i++){
// //             if(mp.find(recipes[i]) == mp.end()){
// //                 mp[recipes[i]] = id;id++;
// //             }
// //             int f = 1;
// //             for(auto it : ingredients[i]){
// //                 if(mp.find(it) == mp.end()){
// //                     mp.erase(recipes[i]);
// //                     f = 0;
// //                     adj[mp[it]].erase();
// //                     break;
// //                 }
// //                 else{
// //                     adj[mp[it]].push_back(mp[recipes[i]]);
// //                     indegree[mp[recipes[i]]]++;
// //                 }
// //             }
// //             if(f == 0)break;
// //         }

// //         vector<int> indegree(mp.size() + recipes.size(),0),vis(mp.size() + recipes.size(),0);
        
// //         queue<int>q;
// //         for(int i = 1;i<indegree.size();i++){
// //             if(indegree[i] == 0) q.push(i);
// //         }
// //         set<int> ans;
// //         while(!q.empty()){
// //             int t = q.top();
// //             q.pop();
// //             ans.insert(t);
// //             vis[t] = 1;
// //             for(auto it : adj[t]){
// //                 if(!vis[it]){
// //                 indegree[it]--;
// //                 if(indegree[it] == 0) q.push(it);
// //                 }
// //             }
// //         }
        
// //     vector<string >anss;
// //     for(auto it:  recipes){
// //         if(ans.find(mp[it]) != ans.end()){
// //             anss.push_back(it);
// //         }
// //     }
// //     return anss;

// //     }
// // };
// class Solution {
// public:
//     vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
//         map<string, int> mp;
//         int id = 1;

//         // Map all supplies
//         for (auto& it : supplies) {
//             if (mp.find(it) == mp.end()) {
//                 mp[it] = id++;
//             }
//         }

//         // Create adjacency list and indegree vector
//         vector<vector<int>> adj(id + recipes.size());
//         vector<int> indegree(id + recipes.size(), 0);

//         for (int i = 0; i < recipes.size(); i++) {
//             if (mp.find(recipes[i]) == mp.end()) {
//                 mp[recipes[i]] = id++;
//             }
//             int recipeId = mp[recipes[i]];

//             for (auto& it : ingredients[i]) {
//                 if (mp.find(it) == mp.end()) {
//                     mp[it] = id++;
//                 }
//                 int ingredientId = mp[it];
//                 adj[ingredientId].push_back(recipeId);
//                 indegree[recipeId]++;
//             }
//         }

//         vector<int> vis(id + recipes.size(), 0);

//         queue<int> q;
//         for (int i = 1; i < indegree.size(); i++) {
//             if (indegree[i] == 0) {
//                 q.push(i);
//             }
//         }

//         set<int> ans;
//         while (!q.empty()) {
//             int t = q.front(); // Correctly use queue front
//             q.pop();
//             ans.insert(t);
//             vis[t] = 1;
//             for (auto& it : adj[t]) {
//                 if (!vis[it]) {
//                     indegree[it]--;
//                     if (indegree[it] == 0) {
//                         q.push(it);
//                     }
//                 }
//             }
//         }

//         vector<string> anss;
//         for (auto& it : recipes) {
//             if (ans.find(mp[it]) != ans.end()) {
//                 anss.push_back(it);
//             }
//         }

//         return anss;
//     }
// };

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> available(supplies.begin(), supplies.end());

        // Build the graph
        for (int i = 0; i < recipes.size(); ++i) {
            for (const string& ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;
        // Start with all supplies
        for (const string& supply : supplies) {
            q.push(supply);
        }

        vector<string> result;

        while (!q.empty()) {
            string current = q.front();
            q.pop();
            
            // If the current item is a recipe and all its ingredients are met, add to the result
            if (available.find(current) == available.end()) {
                result.push_back(current);
            }

            for (const string& neighbor : graph[current]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                    available.insert(neighbor);
                }
            }
        }

        // Filter the result to include only recipes
        vector<string> finalResult;
        for (const string& recipe : recipes) {
            if (available.find(recipe) != available.end()) {
                finalResult.push_back(recipe);
            }
        }

        return finalResult;
    }
};
