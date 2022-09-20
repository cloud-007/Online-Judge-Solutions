#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int count=0;
    string a,b;
    int j=1;
    getline(cin, a);
    for(int i=0;i<a.size();i++){
        if(a[i]>=65 && a[i]<=90){
            count++;
        }
    }
    cout<<count+1<<endl;
}
