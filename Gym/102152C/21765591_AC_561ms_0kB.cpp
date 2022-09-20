#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        if((a+b)%2==0)
            cout<<12<<endl;
        else
            cout<<2<<endl;
        //long long int z=__gcd(5^a+7^a,5^b+7^b);
        //cout<<z<<endl;
    }
}
