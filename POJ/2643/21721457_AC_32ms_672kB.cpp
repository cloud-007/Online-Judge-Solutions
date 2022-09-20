#include<iostream>
#include<string.h>
#include<iterator>
#include<vector>
#include<stdio.h>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<string,int>::iterator it;
    map<string,string>mp1;
    map<string,int>mp2;
    getchar();
    while(n--)
    {
        char a[100],b[100];
        gets(a);
        gets(b);
        mp1[a]=b;
    }
    int m;
    cin>>m;
    getchar();
    while(m--)
    {
        char a[100];
        gets(a);
        //auto it=mp1.find(a);
        if(mp1.count(a))
            mp2[a]++;
    }
    int max=0;
    for(it=mp2.begin();it!=mp2.end();it++)
    {
        if(it->second>max)
            max=it->second;
    }
    int count=0;
    vector<string>v;
    for(it=mp2.begin();it!=mp2.end();it++)
    {
        if(it->second==max)
        {
            count++;
            v.push_back(mp1[it->first]);
        }
    }
    if(count==1)
        cout<<v[0]<<endl;
    else
        cout<<"tie"<<endl;
    //cout<<count<<endl;

}
