#include <bits/stdc++.h>
using namespace std;

// Basic methods are:-
// clear()- To clear the stream.
// str()- To get and set string object whose content is present in the stream. 
// operator <<- Add a string to the stringstream object. 
// operator >>- Read something from the stringstream object.

int main()
{
    string s="I am know well why do you see";
    // stringstream ss(s);
    stringstream ss;
    ss<<s;
    cout<<ss.str()<<endl; // It will print whatever is present in the stream;
    string word;
    // Note:- space is a by default separator for stringstream
    // while(getline(ss, word, ' ')){ //in getline the third parameter is the separator
    //     cout<<word<<'\t';
    // }
    while( ss >> word )
       cout<<word<<'\t';
    int x = 123;
    string st="Got you";
    stringstream ss1, ss2;
    ss2.str(st);  // Add value in ss23 using str() function.
    cout<<endl<<ss2.str()<<endl;
    ss2.clear();  // Clear the stream
    ss1<<x;
    string val;
    ss1>>val;
    cout<<endl<<val;
    return 0;
}
