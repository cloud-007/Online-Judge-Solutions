#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
    string a;
    int k=65,count=0;
    getline(cin,a );
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]>=97 && a[i]<=122)
        {
            a[i]=a[i]-32;
        }
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
        for(int i=0; i<a.size(); i++)
        {
            if(a[i]==k)
            {
                count++;
                k++;
            }
        }
    }
    if(count==26)
        cout<<"pangram"<<endl;
    else
        cout<<"not pangram"<<endl;
    return 0;
}
