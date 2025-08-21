#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie
{
    public:
       TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void InsertUtil(TrieNode *root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }


        // finding index of word to be inserted as per mapping
        int index=toupper(word[0])-'A';  
        TrieNode * child;

        if(root->children[index]!=nullptr){
            child=root->children[index];
    
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
         

        // recursion
        InsertUtil(child,word.substr(1));
    
    }

    bool searchUtil(TrieNode*root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index=toupper(word[0])-'A';  
        TrieNode * child;
        
        if(root->children[index]!=nullptr){
            child=root->children[index];
        }
        else{
            return false;
        }

        return searchUtil(child,word.substr(1));

    }

    bool searchWord(string word){
        return searchUtil(root,word);
    }


    void InsertWord(string word){

           InsertUtil(root,word);
    }
};

int main(){

    Trie *t= new Trie;
    t->InsertWord("DO");
    t->InsertWord("TIME");
    t->InsertWord("CAT");
    t->InsertWord("DU");
    t->InsertWord("DUCK");
    cout<<"presnt or not :"<<t->searchWord("TIM");
    return 0;

    // TIME COMPLEXITY=O(length of word)->search,insert.delete
}
