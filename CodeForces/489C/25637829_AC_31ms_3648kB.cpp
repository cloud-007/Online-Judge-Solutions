#include<bits/stdc++.h>
using namespace std;
int main()
{
    int d,sum;
    scanf("%d%d",&d,&sum);
    if((sum>d*9) || (sum==0 && d>1))
    {
        puts("-1 -1");
        return 0;
    }
    if(sum==0 && d==1)
    {
        puts("0 0");
        return 0;
    }
    string mx="";
    int y=sum/9;
    d-=y;
    int z=sum%9;
    while(y--)
        mx+='9';
    if(d && z)
        mx+=z+'0',d--;
    while(d>0)
        mx+='0',d--;
    string mn=mx;
    reverse(mn.begin(),mn.end());
    if(mn[0]=='0')
    {
        int j=0;
        while(j<mn.size() && mn[j]=='0')
            j++;
        if(j!=mn.size())
        {
            mn[j]=((mn[j]-'0')-1)+'0';
            mn[0]='1';
        }
    }
    cout<<mn<<" "<<mx<<endl;
}
