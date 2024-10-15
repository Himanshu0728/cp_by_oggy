#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include<unordered_set>
#include<set>
#include<list>
using namespace std;

class TrieNode{
    public:
        char value;
        vector<TrieNode*> children;
        bool isTerminal;

        TrieNode(char val){
            this->value = val;
            this->children = vector<TrieNode*>(26, NULL);
            this->isTerminal = false;

        }
};


void insertWord(TrieNode* root, string word, int wordIndex){
    if(wordIndex == word.length()){
        root->isTerminal = true;
        return ;
    }
    char ch = word[wordIndex];
    int index = ch-'a';
    TrieNode* child;
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    else{
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    insertWord(child, word,wordIndex+1);
}

bool search(TrieNode* root, string word, int wordIndex){
    if(wordIndex == word.size()){
        return root->isTerminal;
    }
    int index = word[wordIndex]- 'a';
    if(root->children[index]!= NULL){
        return search(root->children[index], word, wordIndex+1);
    }
    return false;
}
void printAllStringStartingWithSomeString(TrieNode* root, string &word){
    if(root->isTerminal){
        cout<<word<<endl;
    }

    for(int i =0 ; i<26;i++){
        if(root->children[i]!=NULL){
            word.push_back('a'+i);
            printAllStringStartingWithSomeString(root->children[i], word);
            word.pop_back();
        }
    }
}
void printAllString(TrieNode* root, string word, int wordIndex){
    if(wordIndex == word.size()){
        printAllStringStartingWithSomeString(root,word);
        return;
    }
    int index = word[wordIndex]- 'a';
    if(root->children[index]!= NULL){
        // cout<<word<<" "<<wordIndex<<endl;
        printAllString(root->children[index], word, wordIndex+1);
    }
    return ;
}
void delete_Trie(TrieNode* root, string word, int wordIndex){
    if(wordIndex == word.size()){
        root->isTerminal = false;
        return;
    }
    int index = word[wordIndex]- 'a';
    if(root->children[index]!= NULL){
        delete_Trie(root->children[index], word, wordIndex+1);
    }
}

int main(){
    TrieNode * root = new TrieNode('-');
    insertWord(root, "cater",0);
    insertWord(root, "care",0);
    insertWord(root, "com",0);
    insertWord(root, "lover",0);
    insertWord(root, "loved",0);
    insertWord(root, "load",0);
    insertWord(root, "lov",0);
    insertWord(root, "bat",0);
    insertWord(root, "cat",0);
    insertWord(root, "car",0);
    printAllString(root,"lov",0);
    return 0;
}