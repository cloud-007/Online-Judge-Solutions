#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    cin>>s>>n;
    set < char > st;
    for(auto i : s)st.insert(i);
    int len=st.size();
    if(len>=n)cout<<0<<endl;
    else if (n>(int)s.size())cout<<"impossible"<<endl;
    else cout<<abs(len-n)<<endl;
}
