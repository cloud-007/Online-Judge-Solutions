#include<bits/stdc++.h>
using namespace std;

deque < int > x[50];
vector < int > fx={4,8,15,16,23,42};

int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        x[a].push_back(i);
    }
    int cnt=0,ok=0;
    while(true)
    {
        int last=-1;
        bool fl=true;
        for(auto i : fx)
        {
            if(x[i].empty())
            {
                printf("%d\n",abs(n-ok));
                return 0;
            }
            else if(last==-1)
                last=x[i].front(),x[i].pop_front();
            else
            {
                while(x[i].size() && last > x[i].front())
                    x[i].pop_front();
                if(x[i].size())
                    last=x[i].front(),x[i].pop_front();
                else
                {
                    printf("%d\n",abs(n-ok));
                    return 0;
                }
            }
        }
        ok+=6;
    }
}
