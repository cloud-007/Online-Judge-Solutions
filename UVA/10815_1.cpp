#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    set < string > st;
    while(cin>>s)
    {
        string word="";
        for(int i=0; i<s.size(); i++)
        {
            if(isalpha(s[i]))
                word+=tolower(s[i]);
            else
            {
                if(word.size())
                    st.insert(word);
                word="";
            }
        }
        if(word.size())
            st.insert(word);
    }
    for(auto i : st)
        cout<<i<<endl;
}
