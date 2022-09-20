#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0),cout.tie(0);
    int n,h,k,cur=0,last;
    long long sum=0,cnt=0;
    cin>>n>>h>>k;
    int a[n+5];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sum+=a[0];
    for(int i=1; i<n; i++)
    {
        if(sum+a[i]<=h)
            sum+=a[i];
        else
        {
            //cout<<sum<<" ";
            int lo=0,hi=sum/k,temp=sum%k,ans=-1,y=hi;
            while(lo<=hi)
            {
                int mid=(lo+hi)/2;
                if((mid*k)+temp+a[i]<=h)
                    ans=mid,lo=mid+1;
                else
                    hi=mid-1;
            }
            //cout<<ans<<endl;
            if(ans!=-1)
                sum=(ans*k)+temp+a[i],cnt+=y-ans;
            else
                cnt+=(sum/k)+(sum%k?1:0),sum=a[i];
        }
    }
    if(sum<0)
        sum=0;
    cnt+=(sum/k);
    if(sum%k)
        cnt++;
    cout<<cnt<<endl;
}
