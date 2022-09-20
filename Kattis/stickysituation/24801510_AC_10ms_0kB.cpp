#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    long long a;
    cin>>n;
    vector < long long > v;
    bool fl=false;
    while(n--)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size()-2; i++)
    {
        int j=i+1,k=i+2;
        if(v[i]+v[j]>v[k] & v[j]+v[k]>v[i] && v[i]+v[k]>v[j])
        {
            fl=true;
            break;
        }
    }
    puts(fl?"possible":"impossible");
}
