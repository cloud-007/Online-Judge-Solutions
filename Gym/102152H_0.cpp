#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        int count=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='z')
            {
                if(s[i+1]=='a')
                    count++;
            }
            else if(s[i]+1==s[i+1])
                count++;
        }
        if(count+1==s.size())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
