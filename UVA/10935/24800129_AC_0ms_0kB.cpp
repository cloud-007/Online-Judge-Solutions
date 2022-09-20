#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n;
    //deque < int > dq;
    while(cin>>n && n!=0)
    {
        queue < int > q;
        for(int i=1; i<=n; i++)
            q.push(i);
        if(n!=1)
            printf("Discarded cards: ");
        else
            printf("Discarded cards:\n");
        while(q.size()!=1)
        {
            if(q.size()==2)
            {
                cout<<q.front()<<endl;
                q.pop();
            }
            else
            {
                cout<<q.front()<<", ";
                q.pop();
                int x=q.front();
                q.pop();
                q.push(x);
            }
        }
        printf("Remaining card: %d\n",q.front());
    }
}
