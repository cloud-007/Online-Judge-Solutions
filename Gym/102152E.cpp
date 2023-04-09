#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int x;
    cin>>x;
   // getchar();
    while(x--)
    {
        int n,m;
        cin>>n>>m;
        string a;
        cin>>a;

        string b;
        cin>>b;

        string c;
        cin>>c;
        //vm.push_back(c);

        int count=0,sum=0,flag=0;
        for(int i=0; i<c.size(); i++)
        {
            int min1=0;
            for(int j=0; j<a.size(); j++)
            {
                if(c[i]==a[j]&& flag==1)
                {
                    min1=min(min1,b[j]-'0');
                }
                if(c[i]==a[j] && flag==0)
                {
                    flag=1;
                    if(min1<b[j]-'0')
                        min1=b[j]-'0';
                }
            }
            if(flag==1)
            {
                //cout<<min1<<endl;
                count++;
                sum+=min1;
                flag=0;
            }

        }
        //cout<<count<<endl;
        if(count==c.size())
            cout<<sum<<endl;
        else
            cout<<-1<<endl;
    }
}
