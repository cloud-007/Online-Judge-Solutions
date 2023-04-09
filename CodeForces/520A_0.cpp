#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    getchar();
    vector<char>v(n);
    for(int i=0; i<n; i++)
        scanf("%c",&v[i]);
    int k=65,count=0;
    for(int i=0; i<n; i++)
    {
        if(v[i]>=97 && v[i]<=122)
        {
            v[i]=v[i]-32;
        }
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++)
    {
        if(v[i]==k)
        {
            count++;
            k++;
        }
    }
    //cout<<count<<endl;
    if(count==26)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
