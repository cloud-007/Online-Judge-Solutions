#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,casee=1;;
    while(cin>>n)
    {
        if(n<0)
            break;

        int a[12];
        int b[12];
        for(int i=0; i<12; i++)
            cin>>a[i];
        for(int i=0; i<12; i++)
            cin>>b[i];
        cout<<"Case "<<casee<<":"<<endl;
        casee++;
        int cur=n;
        for(int i=0; i<12; i++)
        {
            if(cur>=b[i])
            {
                cout<<"No problem! :D"<<endl;
                cur-=b[i];
            }
            else
                cout<<"No problem. :("<<endl;
            cur+=a[i];
        }
    }
}
