#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    vector < int > v;
    v.push_back(b);
    while(b>a)
    {
        string s=to_string(b);
        if(s[s.size()-1]=='1')
        {
            string y="";
            for(int i=0; i<s.size()-1; i++)
                y+=s[i];
            b=stoi(y);
        }
        else if(b%2==0)
            b/=2;
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
        v.push_back(b);
    }
    if(b==a)
    {
        reverse(v.begin(),v.end());
        cout<<"YES"<<endl;
        cout<<v.size()<<endl;
        for(auto i : v)cout<<i<<" ";
        cout<<endl;
    }
    else
        cout<<"NO"<<endl;
}
