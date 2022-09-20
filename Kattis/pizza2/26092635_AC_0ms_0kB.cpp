#include<bits/stdc++.h>
using namespace std;

int main()
{
    double tot,nai,total,delet;
    scanf("%lf%lf",&tot,&nai);
    if(tot==nai)
    {
        printf("%.10f\n",0);
        return 0;
    }
    total=3.1416*tot*tot;
    tot-=nai;
    delet=3.1416*tot*tot;
    //printf("%lf %lf\n",total,delet);
    double ans=(delet/total);
    printf("%.10f\n",ans*100);
}
