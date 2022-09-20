#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    int n,count=0;
    cin>>n;
    getchar();
    string a[n];
    for(int i=0;i<n;i++){
        getline(cin, a[i]);
        for(int j=0;j<i;j++){
            if(a[i]==a[j]){
                count++;
                break;
            }
        }
        if(count>0){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
count=0;
    }
    return 0;
}
