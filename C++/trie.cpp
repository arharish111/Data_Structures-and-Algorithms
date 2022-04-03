#include <iostream>
#include <unordered_map>
using namespace std;
class Trie {
    struct TrieNode
    {
      unordered_map<char,TrieNode*> children;
      bool endOfWord;
      TrieNode(): endOfWord(false){}
    };
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        TrieNode* current = root;
        for(auto i:word)
        {
            if(current->children.find(i)==current->children.end())
            {
                current->children[i] = new TrieNode();
            }
            current = current->children[i];
        }
        current->endOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        TrieNode* current = root;
        for(auto i:word)
        {
            if(current->children.find(i)==current->children.end())
                return false;
            else
                current = current->children[i];
        }
        return current->endOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
       TrieNode* current = root; 
        for(auto i:prefix)
        {
            if(current->children.find(i)==current->children.end())
                return false;
            else
                current = current->children[i];
        }
        return true;
    }
};