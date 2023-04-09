#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int c=0,s=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]>='A' && a[i]<='Z')
            c++;
        else
            s++;
    }
    if(a[0]>='a' && a[0]<'z' && c!=a.length()-1)
        cout<<a<<endl;
    else if(c==a.length())
    {
        for(int i=0; i<a.length(); i++)
            a[i]=tolower(a[i]);
        cout<<a<<endl;
    }
    else
    {
        if(a[0]>='a' && a[0]<='z' && c==a.length()-1)
        {
            a[0]=toupper(a[0]);
        for(int i=1; i<a.length(); i++)
            a[i]=tolower(a[i]);
        cout<<a<<endl;
        }
        else if(s==1 && c==a.length()-1 && a[0]>='A' && a[0]<='Z')
            cout<<a<<endl;
        else if(s>=1 && c!=a.length()-1)
            cout<<a<<endl;

        else
        {
            a[0]=toupper(a[0]);
        for(int i=1; i<a.length(); i++)
            a[i]=tolower(a[i]);
        cout<<a<<endl;
        }
    }
}