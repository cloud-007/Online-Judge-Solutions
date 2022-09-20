#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc,casee=1;
    cin>>tc;
    int cnt=0;
    while(tc--)
    {
        int i=0;
        string s;
        cin>>s;
        int j=s.size()-1;
        bool ok=true;
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                ok=false;
                break;
            }
            i++;
            j--;
        }
        if(ok)
            cnt++;


    }
    cout<<cnt<<endl;
    return 0;
}
