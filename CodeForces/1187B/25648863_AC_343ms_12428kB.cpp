#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sz;
    scanf("%d",&sz);
    string s;
    cin>>s;
    map < pair < char, int >, int > mp;
    map < char, int > mx;
    for(int i=0;i<sz;i++)
    {
        mx[s[i]]++;
        mp[{s[i],mx[s[i]]}]=i+1;
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        mx.clear();
        int mn=0;
        string temp;
        cin>>temp;
        for(auto i : temp)
        {
            mx[i]++;
            mn=max(mn,mp[{i,mx[i]}]);
        }
        printf("%d\n",mn);
    }
}
