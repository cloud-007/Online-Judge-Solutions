#include<bits/stdc++.h>
using namespace std;
const int sz=1e9+50;
map < int, int > mp;
vector < int > v;
void init()
{
    int sum=1;
    mp[1]=1;
    v.push_back(1);
    for(int i=2; sum<=sz; i++)
    {
        sum+=i;
        v.push_back(sum);
        mp[sum]=1;
    }
}

int main()
{
    init();
    int n;
    scanf("%d",&n);
    for(auto i : v)
    {
        int x=abs(n-i);
        if(i<n)
        {
            if(mp[x])
            {
                puts("YES");
                return 0;
            }
        }
        else
            break;
    }
    puts("NO");
}
