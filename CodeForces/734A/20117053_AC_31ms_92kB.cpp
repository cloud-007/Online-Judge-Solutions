#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
    int an=0,d=0;
    int n;
    cin>>n;
    getchar();
    char a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]=='A'){
            an++;
        }
        if(a[i]=='D')
            d++;
    }
    if(an>d)
        cout<<"Anton"<<endl;
    else if(an<d)
        cout<<"Danik"<<endl;
    else if(an==d)
        cout<<"Friendship"<<endl;
    return 0;
}
