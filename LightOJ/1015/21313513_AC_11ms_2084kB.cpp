#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,casee=1;
    cin>>n;
    while(n--)
    {
        int a,sum=0;
        cin>>a;
        while(a--)
        {
            int b;
            cin>>b;
            if(b>0)
                sum+=b;
            else
                sum+=0;
        }
        cout<<"Case "<<casee<<": "<<sum<<endl;
        casee++;
    }
}
