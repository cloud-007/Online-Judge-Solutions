#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
    int a[n],m=0,j=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
            m++;
        else
            j++;
    }
    cout<<"Mary won "<<m<<" times and John won "<<j<<" times"<<endl;
    }
}
