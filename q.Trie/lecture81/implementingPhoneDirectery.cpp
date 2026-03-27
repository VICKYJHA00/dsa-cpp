// implement the phone directery for suggestion to complete sentence
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class TrieNode{
    public:
    char data;
    int childcount;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i =0;i<26;i++){
            children[i] = NULL;
        }
        childcount = 0;
        isTerminal = false;
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
        TrieNode * child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childcount++;
        }

        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    void printSuggestions(TrieNode* curr,vector<string> &temp,string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for(char ch = 'a';ch<='z';ch++){
            TrieNode* next = curr->children[ch-'a'];

            if(next != NULL){
                printSuggestions(next,temp,prefix + ch);
            }
        }
    }

    vector<vector<string>> getSuggestions(string str){
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";
        for(int i = 0;i<str.length();i++){
            char ch = str[i];
            prefix.push_back(ch);
            TrieNode* curr = prev->children[ch - 'a'];
            if(curr == NULL){
                break;
            }
            vector<string> temp;
            printSuggestions(curr,temp,prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }    
        return output;
    }

};

vector<vector<string>> phoneDirectory(vector<string> &contactList,string &querystr){
    Trie* t  = new Trie();
    for(int i = 0;i<contactList.size();i++){
        string str = contactList[i];
        t->insertWord(str);
    }
    return t->getSuggestions(querystr);

}

int main(){
    vector<string> contactList = {"gforgeeks","geeksquiz","geeksfor","geeksfortest"};
    string querystr = "geeksf";
    vector<vector<string>> ans = phoneDirectory(contactList,querystr);

    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}


