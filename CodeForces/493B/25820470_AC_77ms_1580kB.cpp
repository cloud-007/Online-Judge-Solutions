#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll suma=0,sumb=0;
vector < int > a,b;
bool fl=true;
int main()
{
    int n,x;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        if(x>0)suma+=x,a.push_back(x),fl=true;
        else sumb+=abs(x),b.push_back(abs(x)),fl=false;
    }
    if(suma>sumb)
    {
        puts("first");
    }
    else if(suma<sumb)puts("second");
    else
    {
        if(a>b)puts("first");
        else if(a<b)puts("second");
        else
        {
            puts(fl?"first":"second");
        }
    }
}
