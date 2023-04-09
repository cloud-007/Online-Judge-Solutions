#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        vector < pair < int, string >> vp;
        for(int i=0; i<3; i++)
        {
            int a;
            cin>>a;
            if(i==0)
                vp.push_back({a,"First"});
            else if(i==1)
                vp.push_back({a,"Second"});
            else
                vp.push_back({a,"Third"});
        }
        sort(vp.begin(),vp.end());
        cout<<vp[0].second<<endl;
    }
}
