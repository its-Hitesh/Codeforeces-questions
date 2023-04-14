#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    unordered_map<char,TrieNode*> mp;
    bool eow; // end of word    
};
string ans;
class Trie {
TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode;
        root->eow=false;
    }
    
    /** Inserts a word into the trie. */
    bool insert(string word) {
        int len=word.length();
        TrieNode* temp=root;
        bool flag=true;
        ans="";
        for(int i=0 ; i<len; i++)
        {
            if((temp->mp).count(word[i]))
            {
                temp=(temp->mp)[word[i]];
                if(temp->eow)
                {
                    return false;
                }
                if(i==len-1)
                {
                    return false;
                    temp->eow=true;                  
                }
            }
            else
            {
                TrieNode* newNode= new TrieNode;
                newNode->eow=false;
                if(i==len-1)
                {
                    newNode->eow=true; 
                }
                (temp->mp)[word[i]]=newNode;
                temp=newNode;
            }
        }
    return flag;
    }
    };
    
int32_t main()
{
    int n;
    cin>>n;
    vector<string> vec(n);
    Trie T;
    bool flag=true;
    string req="";
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
        flag=flag&&T.insert(vec[i]);
        if(!flag&&!req.length())
        {
            req=vec[i];
        }
    }
    if(!flag)
    {
                    cout<<"BAD SET\n";
                    cout<<req<<'\n';
    }
    else {
    cout<<"GOOD SET\n";
    }    
    return 0;
}