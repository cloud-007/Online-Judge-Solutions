/*
Quick_Round_64______________
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    long long n;
    vector < double > v;
    while(cin>>n)
        v.push_back(sqrt(n));
    reverse(v.begin(),v.end());
    for(auto i : v)
        printf("%.4f\n",i);
}
