#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int tc,casee=1;
    cin>>tc;
    while(tc--)
    {
        int sz,m;
        cin>>sz>>m;
        deque < int > dq;
        printf("Case %d:\n",casee++);
        while(m--)
        {
            string s;
            int a;
            cin>>s;
            if(s[1]=='u')
                cin>>a;
            if(dq.size()==sz && s[1]=='u')
            {
                printf("The queue is full\n");
            }
            else
            {
                if(s=="pushLeft")
                {
                    dq.push_front(a);
                    printf("Pushed in left: %d\n",a);
                }
                else if(s=="pushRight")
                {
                    dq.push_back(a);
                    printf("Pushed in right: %d\n",a);
                }
                else if(s=="popLeft")
                {
                    if(dq.size())
                    {
                        printf("Popped from left: %d\n",dq.front());
                        dq.pop_front();
                    }
                    else
                        printf("The queue is empty\n");
                }
                else
                {
                    if(dq.size())
                    {
                        printf("Popped from right: %d\n",dq.back());
                        dq.pop_back();
                    }
                    else
                        printf("The queue is empty\n");
                }
            }
        }
    }
}
