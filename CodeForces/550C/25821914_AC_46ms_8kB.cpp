#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size(),a;
    for(int i=0;i<n;i++)
    {
        a=s[i]-'0';
        if(a%8==0)
        {
            printf("YES\n%d\n",a);
                    return 0;
        }
        for(int j=i+1;j<n;j++)
        {
            a=10*(s[i]-'0');
            a+=s[j]-'0';
            if(a%8==0)
            {
                puts("YES");
                printf("%d\n",a);
                return 0;
            }
            for(int k=j+1;k<n;k++)
            {
                a=100*(s[i]-'0');
                a+=10*(s[j]-'0');
                a+=s[k]-'0';
                if(a%8==0)
                {
                    printf("YES\n%d\n",a);
                    return 0;
                }
            }
        }
    }
    puts("NO");
}
