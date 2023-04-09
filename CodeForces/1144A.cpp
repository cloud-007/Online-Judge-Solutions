#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    int n,i=0;
    cin>>n;
    getchar();
    for(int i=0; i<n; i++)
    {
        int count=0;
        string a;
        getline(cin, a);
        for(int i=0; i<a.size()-1; i++)
        {
            for(int j=i+1; j<a.size(); j++)
            {
                if(a[i]>a[j])
                {
                    char t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }
        for(int i=0;i<a.size()-1;i++){
            if(a[i]+1==a[i+1]){
            count++;
        }
        }
        if(count+1==a.size())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
