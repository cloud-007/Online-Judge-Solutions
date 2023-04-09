#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    getchar();
    string a;
    for(int i=0;i<n;i++){
        getline(cin, a);
        if(a.size()>10){
            cout<<a[0]<<a.size()-2<<a[a.size()-1]<<endl;
        }
        else
            cout<<a<<endl;
    }
}
