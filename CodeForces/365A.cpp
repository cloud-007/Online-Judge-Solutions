#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    map< int, int > mp;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int c=0;
    for(auto i: mp)
    {
        set< int > st;
        int x=i.first;
        while(x!=0)
        {
            if(x%10<=k)
                st.insert(x%10);
            x/=10;
        }
        if(st.size()==k+1)
            c+=i.second;
    }
    cout<<c<<endl;

}
