#include<bits/stdc++.h>
using namespace std;

struct R
{
    int id,i,j;
};
vector < R > v;
map < int, int > mp;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n+5],mx=0,pos=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]]++;
        if(mp[a[i]]>mx)
        {
            mx=mp[a[i]];
            pos=i;
        }
    }
    int i=pos,j=pos;
    while(i>=2)
    {
        if(a[i]>a[i-1])
        {
            int add=abs(a[i]-a[i-1]);
            a[i-1]=a[i];
            v.push_back({1,i-1,i});
        }
        else if(a[i-1]>a[i])
        {
            int del=abs(a[i]-a[i-1]);
            a[i-1]=a[i];
            v.push_back({2,i-1,i});
        }
        i--;
    }
    i=j;
    while(i<n)
    {
        if(a[i]>a[i+1])
        {
            int add=abs(a[i]-a[i+1]);
            a[i+1]=a[i];
            v.push_back({1,i+1,i});
        }
        else if(a[i+1]>a[i])
        {
            int del=abs(a[i]-a[i+1]);
            a[i+1]=a[i];
            v.push_back({2,i+1,i});
        }
        i++;
    }
    printf("%d\n",v.size());
    for(auto i : v)
        printf("%d %d %d\n",i.id,i.i,i.j);
}
