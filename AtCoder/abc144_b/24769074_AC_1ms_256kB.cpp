#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=9;i++)
    {
        for(int j=i;j<=9;j++)
        {
            if(i*j==n)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}
