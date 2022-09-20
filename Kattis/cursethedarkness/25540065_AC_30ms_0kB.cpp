#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        double x,y;
        cin>>x>>y;
        int n;
        cin>>n;
        bool fl=false;
        while(n--)
        {
            double x1,y1;
            cin>>x1>>y1;
            double z=sqrt(pow((x1-x),2)+pow((y1-y),2));
            if(z<=8)fl=true;
        }
        puts(fl?"light a candle":"curse the darkness");
    }
}
