#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,casee=1;
    cin>>n;
    while(n--)
    {
        int a,b,sum=0;
        cin>>a>>b;
        for(int i=a;i<=b;i++)
        {
            if(i%2!=0)
                sum+=i;
        }
        cout<<"Case "<<casee<<": "<<sum<<endl;
        casee++;
    }
}
