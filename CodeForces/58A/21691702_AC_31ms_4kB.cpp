#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main()
{
    string s;
    cin>>s;
    vector<char>st;
    vector<string>v;
    v.push_back("hello");
    //vector<char>v;
    int count=0;
    int in=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==v[0][in])
        {
            count++;in++;
        }
    }
    if(count==v[0].size())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
