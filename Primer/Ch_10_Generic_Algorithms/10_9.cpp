
// Implement your own version of elinDups. Test your program by printing the vector after you read the input,
// after the call to unique, and after the call to erase.

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>



using namespace std;

void funct(int a, int b);

void elimDups(vector<string> &words)
{
    sort(words.begin(),words.end());

    auto end_unique=unique(words.begin(),words.end());

    words.erase(end_unique,words.end());

}



int main(){

    
    vector<string>words;
    string s;
    while (cin>>s)
        words.push_back(s);

    for (auto i=words.begin(); i!=words.end();i++)
        cout<<words.size()<<endl;
 
    return 0;
}
