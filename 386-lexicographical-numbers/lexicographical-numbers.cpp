class Node{
    public:
    Node* links[10];//reference link for each node - 26 characters i.e. 26 links
    bool flag = false; // end of word checking flag 
    bool containsKey(char ch){ // to check if character exist or not
        return links[ch-'0']!=NULL;
    }

     void put(char ch,Node* node){
        // to add ch char link
        links[ch-'0'] = node;
     }

     Node* get(char ch){
        return links[ch - '0'];
     }

     void setEnd(){
        flag = true;
     }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (auto it : word) {
            if (!node->containsKey(it)) {
                node->put(it, new Node());
            }
            node = node->get(it);
        }
        node->setEnd();
    }

    bool search(string word) { 
        Node* node = root;
        for (auto it : word) {
            if (!node->containsKey(it)) {
                return false;
            }
            node = node->get(it);
        }
        return node->flag;
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (auto it : prefix) {
            if (!node->containsKey(it)) {
                return false;
            }
            node = node->get(it);
        }
        return true;
    }

    void dfs(Node* node, string current, vector<int>& result) {
        // If the node marks the end of a word, add the current string as an integer to the result
        if (node->flag) {
            result.push_back(stoi(current));
        }
        // Traverse the children nodes in lexicographical order (0 to 9)
        for (int i = 0; i < 10; i++) {
            if (node->links[i] != nullptr) {
                dfs(node->links[i], current + char(i + '0'), result);
            }
        }
    }

    vector<int> traverse() {
        vector<int> result;
        // Start DFS from the root with an empty string
        dfs(root, "", result);
        return result;
    }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Trie th;
        for (int i = 1; i <= n; i++) {
            th.insert(to_string(i));
        }

        vector<int> ans = th.traverse();
        return ans;
    }
};
