#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    Node* links[26]={NULL};
    int cntEndsWith=0;
    int cntPrefix=0;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
};
class Trie{
   private:
        Node* root;
   public:
        Trie(){
            root=new Node();
        }
        void insert(string word){
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    node->links[word[i]-'a']=new Node();
                }
                node=node->links[word[i]-'a'];
                node->cntPrefix++;
            }
            node->cntEndsWith++;
        }
        
        int countWords(string word){
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    return 0;
                }
                node=node->links[word[i]-'a'];
            }
            return (node->cntEndsWith);
        }
        
        int countWordsStartsWith(string word){
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    return 0;
                }
                node=node->links[word[i]-'a'];
                
            }
            return (node->cntPrefix);
        }
        
        void erase(string word){
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    return;
                }
                node=node->links[word[i]-'a'];
                node->cntPrefix--;
            }
            node->cntEndsWith--;
        }

        bool canSegment(string &s){
            Node* node=root;
            for(int i=0;i<s.length();i++){
                if(!node->containsKey(s[i]))
                   return false;
                node=node->links[s[i]-'a'];
            }
            return node->cntEndsWith;
        }
};

int main()
{
    
    Trie dict;
    
    dict.insert("apple");
    dict.insert("apple");
    dict.insert("apple");
    dict.insert("apps");
    dict.insert("app");
    dict.insert("bat");
    dict.insert("bac");
    
    cout<<dict.countWords("apple")<<endl;
    cout<<dict.countWords("apps")<<endl;
    cout<<dict.countWords("appl")<<endl;
    cout<<dict.countWordsStartsWith("app")<<endl<<endl;
    
    dict.erase("apple");
    
    cout<<dict.countWords("apple")<<endl;
    cout<<dict.countWords("apps")<<endl;
    cout<<dict.countWords("appl")<<endl;
    cout<<dict.countWordsStartsWith("app")<<endl<<endl;

    return 0;
}
