#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);string s;
    cin>>s;
    stack < char > st;
    for(auto i : s)
    {
        if(st.size())
        {
            if(i==st.top())
                st.pop();
            else
                st.push(i);
        }
        else
            st.push(i);
    }
    string ans="";
    while(!st.empty())
        ans+=st.top(),st.pop();
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
