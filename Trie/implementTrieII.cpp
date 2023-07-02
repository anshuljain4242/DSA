#include<iostream>
#include<string>
using namespace std;

struct Node{
    Node* links[26];
    int cntEndsWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    void increaseEnd(){
        cntEndsWith++;
    }
    
    void increaseCntPrefix(){
        cntPrefix++;
    }

    void deleteEnd(){
        cntEndsWith--;
    }

    void reduceCntPrefix(){
        cntPrefix--;
    }

    int getEnd(){
        return cntEndsWith;
    }

    int getCntPrefix(){
        return cntPrefix;
    }
};

class Trie{
    private:
        Node* root;
    public:
        
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
          if (!node->containsKey(word[i])) {
            node->put(word[i], new Node());
            }
            node = node -> get(word[i]);
            node -> increaseCntPrefix();    
        }
        node -> increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node -> containsKey(word[i]))
                node = node -> get(word[i]);
            else    
                return 0;    
        }
        return node -> getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node -> containsKey(word[i]))
                node = node -> get(word[i]);
            else    
                return 0;    
        }
        return node -> getCntPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->containsKey(word[i])){
                node = node -> get(word[i]);
                node -> reduceCntPrefix(); 
            }
            else
                return;
        }
        node -> deleteEnd();
    }
};
