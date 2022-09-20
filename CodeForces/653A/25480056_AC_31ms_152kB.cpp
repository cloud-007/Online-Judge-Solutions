#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector < int > v;
    set < int > st;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        st.insert(x);
    }
    for(auto i : st)v.push_back(i);
    bool fl=false;
    if(v.size()>=3)
    for(int i=2;i<n;i++)
    {
        if(v[i-2]+1==v[i-1] && v[i-1]+1==v[i])
        {
            fl=true;
            break;
        }
    }
    puts(fl?"YES":"NO");
}
