#include<bits/stdc++.h>
using namespace std;
map < int ,int >mp;
int main()
{
    cin.tie(0),cout.tie(0);
    mp[1]=2;
    mp[2]=5;
    mp[3]=5;
    mp[4]=4;
    mp[5]=5;
    mp[6]=6;
    mp[7]=3;
    mp[8]=7;
    mp[9]=6;
    mp[0]=6;
    long long sum=0;
    int a,b;
    cin>>a>>b;
    for(a;a<=b;a++)
    {
        int x=a;
        while(x>0)
        {
            sum+=mp[x%10];
            x/=10;
        }
    }
    cout<<sum<<endl;
}
