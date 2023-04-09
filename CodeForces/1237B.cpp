#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,tot=0;
    scanf("%d",&n);
    map < int , int > mp;
    deque < int > dq;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        dq.push_back(a);
        mp[a]++;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        while(!mp[dq.front()])
            dq.pop_front();
        if(dq.front()==a)dq.pop_front();
        else
        {
            tot++;
            mp[a]--;
        }
    }
    printf("%d\n",tot);
}
