#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int a,b;
    cin>>a;
    int x[a];
    for(int i=0;i<a;i++)
        cin>>x[i];
    cin>>b;
    int y[b];
    for(int i=0;i<b;i++)
        cin>>y[i];
    int c=a+b;
    int z[c];
    for(int i=0;i<a;i++)
        z[i]=x[i];
    int f=a;
    for(int i=0;i<b;i++)
        {
            z[a]=y[i];
            a++;
        }
    sort(z,z+c);
    //for(int i=0;i<c;i++)
      //  cout<<z[i]<<' ';
    int d=1,count=0;
    for(int i=0;i<c;i++)
    {
        if(z[i]==d)
        {
            count++;
            d++;
        }
    }
    //cout<<count<<endl;
    if(count>=n)
        cout<<"I become the guy."<<endl;
    else
        cout<<"Oh, my keyboard!"<<endl;
 
}