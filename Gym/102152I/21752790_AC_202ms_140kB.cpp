#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x,k;
        cin>>x>>k;
        priority_queue< int, vector<int> , greater <int> > v;
        for(int i=0; i<x; i++)
        {
            int x;
            scanf("%d",&x);
            v.push(x);
        }
        int sum=0;
        //sort(v.begin(),v.end());
        //for(int i=0;i<v.size();i++)
        //   cout<<v[i]<<endl;
        int z=v.size()-1;
        //cout<<z<<endl;
        int b=0;
        for(int i=0; i<k; i++)
        {
            int c=v.top();
            v.pop();
            c *= -1;
            b++;
            v.push(c);
            if(b==z);
            {
                b=0;
                //sort(v.begin(),v.end());
                //cout<<"true"<<endl;
            }
        }
        while(!v.empty())
        {
            sum+=v.top();
            v.pop();
        }
        printf("%d\n",sum);
    }



}
