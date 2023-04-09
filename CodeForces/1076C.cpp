/*Editorial*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        double n,temp;
        scanf("%lf",&n);
        if(n&&n<4)puts("N");
        else
        {
            printf("Y %.10f %.10f\n",(n+sqrt(n*n-4*n))/2.0,(n-sqrt(n*n-4*n))/2.0);
        }
    }
}
