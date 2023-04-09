#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
    int n,casee=1;
    cin>>n;
    getchar();
    while(n--)
    {
        int index = 0, count[26] = {0}, x,y,count1[26]= {0};
        char a[50],b[50];
        gets(a);gets(b);
        while (a[index] != '\0')
        {
            if (a[index] >= 'a' && a[index] <= 'z')
            {
                x = a[index] - 'a';
                count[x]++;
            }
            index++;
        }
        index=0;
        while (b[index] != '\0')
        {
            if (b[index] >= 'a' && b[index] <= 'z')
            {
                y = b[index] - 'a';
                count1[y]++;
            }
            index++;
        }
        int sum=0;
        for(index=0; index<26; index++)
        {
            if(count1[index]>0)
            {
                sum+=abs(count1[index]-count[index]);
            }
            else
                sum+=abs(count[index]-count1[index]);
        }
        printf("Case #%d:  %d\n",casee,sum);
        casee++;
    }

    return 0;
}
