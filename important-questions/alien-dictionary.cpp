#include <bits/stdc++.h>
using namespace std;

class AlienDictionary {
  public:
    bool cycle(vector<int> adj[], int src, vector<bool>& visited, vector<bool>& recSt) {
        visited[src]=true;
        recSt[src]=true;
        for(auto &u : adj[src]) {
            if(!visited[u]) {
                if(cycle(adj, u, visited, recSt))
                  return true;
            }
            else if(recSt[u]) {
                //this means in our currect recursion call stack we have a back-edge which means
                //we have a cycle in this directed graph meaning a node has an edge to a node which
                //is already visited which creates a cycle.
                return true;
            }
        }
        recSt[src]=false;
        return false;
    }
    
    void topoSortDFS(vector<int> adj[], int src, vector<bool>& visited, stack<int>& st) {
        visited[src]=true;
        for(auto &u : adj[src]) {
            if(!visited[u])
              topoSortDFS(adj, u, visited, st);
        }
        st.push(src);
    }
    string findOrder(vector<string> &words) {
        unordered_map<char, int> charToIndex;
        unordered_map<int, char> indexToChar;
        int index = 0;
        int n=words.size();
        for (const auto& word : words) {
            for (char ch : word) {
                if (charToIndex.find(ch) == charToIndex.end()) {
                    charToIndex[ch] = index;
                    indexToChar[index] = ch;
                    index++;
                }
            }
        }
        int characterCnt = index;
        vector<int> adj[characterCnt];
        for(int i=0;i<n-1;i++) {
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.length(), s2.length());
            bool found = false;
            for(int j=0;j<len;j++) {
                if(s1[j]!=s2[j]) {
                    int u = charToIndex[s1[j]];
                    int v = charToIndex[s2[j]];
                    adj[u].push_back(v);
                    found = true;
                    break;
                }
            }
            // Handle edge case: s1 is longer than s2 but otherwise same (invalid order)
            //ex: abcd, abc
            if (!found && s1.length() > s2.length()) {
                return "";
            }
        }
        
        vector<bool> recSt(characterCnt, false);
        vector<bool> visited(characterCnt, false);
        for(int i=0;i<characterCnt;i++) {
            if(!visited[i] and cycle(adj, i, visited, recSt))
              return "";
        }
        
        fill(visited.begin(), visited.end(), false);
        stack<int> st;
        for(int i=0;i<characterCnt;i++) {
            if(!visited[i])
              topoSortDFS(adj, i, visited, st);
        }
        
        string ans = "";
        while (!st.empty()) {
            ans += indexToChar[st.top()];
            st.pop();
        }

        return ans;
    }
};
/*
here we are given the alien dictionary which is array of strings so
here we need to find the correct alphabetical order in the alien dictionary
there can be many possible order we just need to find one order. Also in our
original dictionary we know the order it is: a,b,c...z meaning a comes before b
, b comes before c and so on.

Now we can solve this problem using graph so given array of strings since we know
how a dictionary works if a word x comes before y in dictionary so what we can say
is either the first differentiating character in word x is smaller than y or
y is larger than x mean lets say x is abc then y will be abcd like that.

So now after understanding so we can say that from this array consider the
adjacent pair and compare the characters and build the character graph by
first differentiating character so if [x,y] 2 words given then lets say
it is ["baa","abcd"] so at first index they differ so it means we can say
b comes before a here so a directed edge from b to a (b->a). After
constructing the graph just check if there is a cycle if there is then it means
the dictionary given is incorrect and if no cycle then just find the topological'sort
as topo sort involves ordering and here we want a valid order of characters
which represents this alien dictionary. And the final string which is topo sort
represent that the characters specified in the string follow the dictionary.

*/

int main() {
  vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
  vector<string> words2 = {"caa", "aaa", "aab"};
  vector<string> words3 = {"ab", "cd", "ef", "ad"};
  vector<string> words4 = {"bdbc", "dbe", "bcebc", "e", "bedb"};

  AlienDictionary alienDict; //default constructor gets called
  alienDict.findOrder(words4);


  return 0;
}