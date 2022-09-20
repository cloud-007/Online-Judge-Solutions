#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        if(s.size()==3)
        {
            if(s[0]=='o' && s[1]=='n' || s[1]=='n' && s[2]=='e' || s[0]=='o' && s[2]=='e')
            {
                puts("1");
            }
            else if(s[0]=='t'&&s[1]=='w'||s[1]=='w'&&s[2]=='o'||s[0]=='t'&&s[2]=='o')
                puts("2");
            else if(s[0]=='t'&&s[1]=='e'||s[1]=='e'&&s[2]=='n'||s[0]=='t'&&s[2]=='n')
                puts("10");
            else
                puts("3");
        }
        else if(s.size()==4)
        {
            if(s[0]=='f' && s[1]=='o' && s[3]=='r' || s[0]=='f' && s[2]=='u' && s[3]=='r' ||s[1]=='o' && s[2]=='u' && s[3]=='r')
                puts("4");
            else if(s[0]=='f' && s[1]=='i' && s[3]=='e' || s[0]=='f' && s[2]=='v' && s[3]=='e' ||s[1]=='i' && s[2]=='v' && s[3]=='e')
                puts("5");
            else
                puts("9");
        }
        else
        {
            if(s[0]=='t' && s[1]=='h' && s[4]=='e' || s[0]=='t' && s[2]=='r' && s[3]=='r' || s[1]=='h' && s[2]=='r')
                puts("3");
            else if(s[0]=='e' && s[1]=='i' && s[4]=='t' || s[0]=='e' && s[2]=='g' && s[3]=='h' || s[1]=='e' && s[2]=='g')
                puts("8");
            else
                puts("7");
        }
    }
}
