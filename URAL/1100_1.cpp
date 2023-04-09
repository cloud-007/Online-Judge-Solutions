/*
Quick_Round_64______________
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct R{
    int id,solve,time;
    bool operator<(R a)const
    {
        if(a.solve==solve)return time<a.time;
        return solve>a.solve;
    }
};
int main()
{
    int n;
    vector < R > v;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        v.push_back({l,r,i});
    }
    sort(v.begin(),v.end());
    for(auto i : v)
        printf("%d %d\n",i.id,i.solve);
}
