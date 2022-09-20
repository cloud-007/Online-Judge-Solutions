#include<bits/stdc++.h>
using namespace std;
#define pi 3.141592653
int main()
{
    double v,s;
    scanf("%lf%lf",&v,&s);
    double x=(360/v)/2;
    x=x*(pi/180);
    x=sin(x);
    double z=(s/2)/x;
    printf("%.9f\n",pi*z*z);

}
