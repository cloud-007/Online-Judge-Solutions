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
        puts(min(a,b)%2==0 && abs(a-b)%2==0?"abdullah":"hasan");
    }
}
