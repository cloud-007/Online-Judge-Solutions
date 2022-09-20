#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
    int n,casee=1;
    cin>>n;
    getchar();
    for(int z=0;z<n;z++)
    {
        int index = 0, count = 0;
        char a[50],b[50];
        gets(a);
        gets(b);
        int x=strlen(a),y=strlen(b);
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(a[i]==b[j])
                {
                    a[i]='!';
                    b[j]='!';
                    count++;
                    break;
                }
            }
        }
        printf("Case #%d:  %d\n",casee,(x+y)-(count*2));
        casee++;
    }

    return 0;
}
