#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        set < int > st;
        for(int j=1; j*j<=n; j++)
        {
            st.insert(n/j);
            st.insert(j);
        }
        st.insert(0);
        printf("%d\n",st.size());
        for(auto i : st)
            printf("%d ",i);
        printf("\n");
    }

}
