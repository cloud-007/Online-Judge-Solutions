#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)
            swap(a,b);
        puts((a+b)%3==0 && a*2>=b?"YES":"NO");
    }
}