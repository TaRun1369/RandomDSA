#include<bits/stdc++.h>
using namespace std;


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

class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(auto it : word){
            if(!node->containsKey(it)){
                node->put(it,new Node());
            }
            // move to reference of this character 
            node = node->get(it);
             
        }
        node->setEnd();
    }

    bool search(string word){ 
        // to check if word exist or not
        Node* node = root;
        for(auto it : word){
            if(!node->containsKey(it)){
                return false;
            }
            node = node->get(it);
        }
        return node->flag;
    }

    int startsWith(string prefix){
        // to check if input is prefix of any word
        int count = 0;
        Node* node = root;
        for(auto it: prefix){
            if(!node->containsKey(it)){
                return count;
            }
            node = node->get(it);
            count++;
        }
        return count;
    }
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie th;
        for(auto it : arr2){
            th.insert(to_string(it));
        }
        int ans = 0;

        for(auto it : arr1){

            string s = to_string(it);
            // if(th.startsWith(s) == true){
            //     ans = max(ans,int(s.size()));
            // }
            ans = max(ans,th.startsWith(s));
        }
        return ans;

    }
};