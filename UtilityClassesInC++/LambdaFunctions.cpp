#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int d=7,e=5;
    vector<int> v{2,3,7,14,23};
    auto checkEven = [&] (int x) {
        if(x%d==0)
          cout<<x<<" is divisible by "<<d<<"\n";
        else
          cout<<x<<" is not divisible by "<<d<<"\n";
    };
    // std::for_each(v.begin(),v.end(), [&] (int x) {
    //     if(x%d==0)
    //       cout<<x<<" is divisible by "<<d<<"\n";
    //     else
    //       cout<<x<<" is not divisible by "<<d<<"\n";
    // });
    std::for_each(v.begin(),v.end(), checkEven);
    // for_each(v.begin(),v.end(), [=] (int x) {
    //     if(x%d==0)
    //       cout<<x<<" is divisible by "<<d<<"\n";
    //     else
    //       cout<<x<<" is not divisible by "<<d<<"\n";
    // });
    // for_each(v.begin(),v.end(), [&d, e] (int x) {
    //     if(x%d==0)
    //       cout<<x<<" is divisible by "<<d<<"\n";
    //     else
    //       cout<<x<<" is not divisible by "<<d<<"\n";
    // });
    return 0;
}
//Lambda functions are:- inline anonymous functions
//Points:- [] in the square brackets we capture the outside scope variable here in this case the outside scope is main.
//if [] it is empty then we cannot use outside scope variables inside the lambda functions.
//if [=] -> it means that we can use all the the variables of the outside scope by value that is we cannot modify those 
//values but we can use access those values as these values are pass by values
//if [&] -> it means we can modify the all outside scope values insdie the lambda functions 
//if we sepecify [&d] -> then we can only use d and can modify it inside the lambda function and if we specify 
//[d] -> then we can only use its value and we cannot modify it.
//() -> these parenthesis is used for passing any arguments to the lambda functions.