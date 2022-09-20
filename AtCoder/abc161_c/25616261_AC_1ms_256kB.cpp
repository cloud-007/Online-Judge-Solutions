#include<iostream>
#include<set>
using namespace std;
int main()
{
    long long int n,k;
    scanf("%lld%lld",&n,&k);
    long long x=n%k;
    if(x==0)
        puts("0");
    else
        printf("%lld\n",min(n,k-x));
}
