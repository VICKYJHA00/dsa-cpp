#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root,string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // assume word will be in uppercase
        int index = word[0] -'A';
        TrieNode* child;

        //if present
        if(root->children[index] != NULL){
            child = root->children[index];
        }

        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child,word.substr(1));

    }

    void insertWord(string word){   //we call this for insertion from main or outside then this call insertUtil 
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root,word);
    }
};

int main(){
    Trie* t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("ABCE");
    t->insertWord("ABCD");
    cout<<t->searchWord("ABCD")<<endl;
    cout<<t->searchWord("ABCE")<<endl;

    return 0;
}