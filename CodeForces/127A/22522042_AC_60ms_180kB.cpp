#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    float a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>a[i][j];
        }
    }
   // vector < int > dist;
    double x,sum=0;
    for(int i=1;i<n;i++)
    {
        x=sqrt((a[i][0]-a[i-1][0])*(a[i][0]-a[i-1][0])  + (a[i][1]-a[i-1][1])*(a[i][1]-a[i-1][1]));
        sum+=x;
    }
    sum*=k;
    printf("%.9f\n",sum/50);
}
