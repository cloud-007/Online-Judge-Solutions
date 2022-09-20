#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    vector<string>v(3);
    for(int i=0;i<3;i++)
        cin>>v[i];

    sort(v[2].begin(),v[2].end());
    v[0]+=v[1];
    sort(v[0].begin(),v[0].end());
    if(v[0]==v[2])
        printf("YES\n");
    else
        printf("NO\n");
}
