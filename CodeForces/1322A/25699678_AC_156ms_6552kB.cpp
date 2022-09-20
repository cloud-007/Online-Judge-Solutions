#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    int op=0,cl=0,cnt=0;
    if(n%2)
    {
        puts("-1");
        return 0;
    }
    for(auto i  : s)
    {
        if(i=='(')
        {
            if(cl)
            {
                cl--;
                cnt+=2;
            }
            else
                op++;
        }
        else if(i==')')
        {
            if(op)
            {
                op--;
            }
            else
                cl++;
        }
    }
    if(cl || op)
    {
        puts("-1");
        return 0;
    }
    printf("%d\n",cnt);
}
