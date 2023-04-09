#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        int b=0,k=0,l=0;
        while(n--)
        {
            string s;
            cin>>s;
            if(s[0]=='b' && s[1]=='e' && s[2]=='d')
                b++;
            else if(s[0]=='k' && s[1]=='i' && s[2]=='t' && s[3]=='c' && s[4]=='h' && s[5]=='e' && s[6]=='n')
                k++;
            else if(s[0]=='l' && s[1]=='i' && s[2]=='v' && s[3]=='i' && s[4]=='n' && s[5]=='g')
                l++;
        }
        b/=2;
        cout<<min(b,(min(k,l)))<<endl;
    }
}
