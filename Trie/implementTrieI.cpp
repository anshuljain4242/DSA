#include<iostream>
using namespace std;

struct Node{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL); // means ch does exist in the node
    }

    void put(char ch, Node *node){
        // if word = "apple" and ch = 'a' then 'a' will point to new newNode(new Trie)
        links[ch -'a'] = node;
    }

    Node *get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */

    // TC -> O(len)
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            // if node does not contain the word[i]
            if(!node -> containsKey(word[i]))
            {
                node -> put(word[i], new Node());
            }
            // moves to the reference trie
            node = node -> get(word[i]); 
        }
        // once the word ends, sets the flag to true.
        node -> setEnd();
    }

    /** Returns if the word is in the trie. */

    // TC -> O(len)
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node -> containsKey(word[i])){
                return false;
            }                   
            node = node -> get(word[i]);    
        }
        // if flag's value is true means the word exists.
        return node -> isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */

    // TC -> O(len)
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.length(); i++){
            if(!node -> containsKey(prefix[i])){
                return false;
            }
            node = node -> get(prefix[i]);
        }
        return true;
    }
};