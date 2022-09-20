#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    map < int , int > ms,mt;
    set < char > st;
    bool tree=false,autom=true,arr=true;
    for(auto i : s)ms[i]++,st.insert(i);
    for(auto i : t)
    {
        if(ms[i])
        {
            ms[i]--;
            if(ms[i]==0)
                st.erase(i);
        }
        else tree=true,arr=false;
    }
    if(tree)
        puts("need tree");
    else
    {
        deque < char > dq;
        for(auto i : s)dq.push_back(i);
        for(auto i : t)
        {
            while(dq.size() && i!=dq.front())
                dq.pop_front();
            if(dq.size())dq.pop_front();
            else{autom=false; break;}
        }
        if(arr && s.size()!=t.size() && !autom)
            puts("both");
        else if(autom)
            printf("automaton\n");
        else if(arr)
            puts("array");
        else
            puts("both");
    }
}
