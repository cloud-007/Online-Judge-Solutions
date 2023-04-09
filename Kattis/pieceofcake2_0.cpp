#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,h,v;
    scanf("%d%d%d",&n,&h,&v);
    priority_queue < int > pq;
    pq.push(h*v);
    pq.push((n-h)*(n-v));
    pq.push((n-h)*(v));
    pq.push((h)*(n-v));
    printf("%d\n",pq.top()*4);
}
