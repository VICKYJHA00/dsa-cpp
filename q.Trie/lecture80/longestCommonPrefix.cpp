#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    int childCount;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i =0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }
        insertUtil(child,word.substr(1));
    }

    void insertword(string word){
        insertUtil(root,word);
    }

    void lcp(string str,string &ans){
        TrieNode* temp = root;
        for(int i = 0;i<str.length();i++){
            char ch = str[i];

            if(temp->childCount == 1 && !temp->isTerminal){
                ans.push_back(ch);
                int index = ch - 'a';
                temp = temp->children[index];
            }else{
                break;
            }
        }
    }
};

string commonLongestPrefix(string arr[], int n){
    Trie*t = new Trie();
    for(int i =0;i<n;i++){
        t->insertword(arr[i]);
    }

    string ans = "";
    string first = arr[0];
    t->lcp(first,ans);
    return ans;
    
}

int main(){
    string arr[] = {"flower","flow","flight"};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<commonLongestPrefix(arr,n);
    return 0;
}