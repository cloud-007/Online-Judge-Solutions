#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long tot=0;
    for(int i=2;i<n;i++)
    {
        tot+=(i*(i+1));
    }
    cout<<tot<<endl;
}
