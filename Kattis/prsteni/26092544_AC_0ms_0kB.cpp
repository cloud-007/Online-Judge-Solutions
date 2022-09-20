#include<bits/stdc++.h>
using namespace std;

void reduceFraction(int x, int y)
{
    int d;
    d = __gcd(x, y);
    x = x / d;
    y = y / d;
    printf("%d/%d\n",x,y);
}

int main()
{
    int n;
    scanf("%d",&n);
    vector < int > v(n+5);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=2;i<=n;i++)
    {
        reduceFraction(v[1],v[i]);
    }
}
