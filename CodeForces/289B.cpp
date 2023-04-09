#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row,col,d,tot=INT_MAX;
    scanf("%d%d%d",&row,&col,&d);
    set < int > st;
    int a[row+5][col+5];
    bool fl=false;
    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=col; j++)
        {
            scanf("%d",&a[i][j]);
            st.insert(a[i][j]);
        }
    }
    for(auto k : st)
    {
        int temp=0;
        for(int i=1; i<=row; i++)
        {
            for(int j=1; j<=col; j++)
            {
                if(abs(a[i][j]-k)%d)
                {
                    puts("-1");
                    return 0;
                }
                temp+=abs(a[i][j]-k)/d;
            }
        }
        tot=min(tot,temp);
    }
    printf("%d\n",tot);
}
