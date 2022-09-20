#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    while(n--)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    bool flag=false;
    for(int i=0;i<v.size()-2;i++)
    {
        if(v[i]+v[i+1]>v[i+2] && v[i+2]+v[i]>v[i+1] && v[i+2]+v[i+1]>v[i] )
        {
            flag=true;
            break;
        }
    }
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
