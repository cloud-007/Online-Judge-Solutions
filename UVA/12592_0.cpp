#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    getchar();
    char a[10000],b[10000];
    map<string,string >mp;
    for(int i=0; i<n; i++)
    {
        gets(a);
        gets(b);
        mp[a]=b;
    }
    int q;
    cin>>q;
    getchar();
    char c[10000];
    for(int i=0; i<q; i++)
    {
        gets(c);
        if(mp.begin()!=mp.end())
            cout<<mp[c]<<endl;
    }
}
