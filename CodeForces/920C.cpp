#include<bits/stdc++.h>
using namespace std;
int main()
{
    set < int > st;
    int n;
    scanf("%d",&n);
    int a[n+5];
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    string s;
    cin>>s;
    bool fl=true;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            st.insert(a[i+1]);
            st.insert(a[i+2]);
        }
        else
        {
            if(st.size())
            {
                if(*st.rbegin()==i+1)
                {
                    st.clear();
                }
                else
                {
                    fl=false;
                    break;
                }
            }
            else
            {
                if(a[i+1]==i+1)
                {
                    int do_nothing;
                }
                else
                {
                    fl=false;
                    break;
                }
            }
        }
    }
    puts(fl?"YES":"NO");
}
