#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    while(cin>>a)
    {
        string b;
        for(int i=0; i<a.length(); i++)
        {
            if(a[i]=='B' || a[i]=='F' || a[i]=='P' || a[i]=='V')
            {
                if(a[i-1]!='B' && a[i-1]!='F' && a[i-1]!='P' && a[i-1]!='V')
                    b+='1';
            }
            else if(a[i]=='C' || a[i]=='G' || a[i]=='J' || a[i]=='K' || a[i]=='Q' || a[i]=='S' || a[i]=='X' || a[i]=='Z')
            {
                if(a[i-1]!='C' && a[i-1]!='G' && a[i-1]!='J' && a[i-1]!='K' && a[i-1]!='Q' && a[i-1]!='S' && a[i-1]!='X' && a[i-1]!='Z')
                    b+='2';
            }
            else if(a[i]=='D' || a[i]=='T')
            {
                if(a[i-1]!='D' && a[i-1]!='T')
                    b+='3';
            }
            else if(a[i]=='L')
            {
                if(a[i-1]!='L')
                    b+='4';
            }
            else if(a[i]=='M' || a[i]=='N')
            {
                if(a[i-1]!='M' && a[i-1]!='N')
                    b+='5';
            }
            else if(a[i]=='R')
            {
                if(a[i-1]!='R')
                    b+='6';
            }
        }
        cout<<b<<endl;
        /*string c;

        for(int i=0; i<b.length(); i++)
        {
            if(b[i]!=b[i-1] && b[i]!='7')
                c+=b[i];
            else
            {
                while(b[i]!=b[i+1])
                {
                    i++;
                }
            }
        }
        cout<<c<<endl;*/
        ///string c;

        /*string c;
        c+=b[0];
        for(int i=1; i<b.length(); i++)
        {
                if(b[i]!=b[i-1])
                {
                    if(b[i]=='B' || b[i]== 'F' || b[i] == 'P' || b[i]=='V')
                        c+='1';
                    else if(b[i]=='C' || b[i]=='G' || b[i]=='J'|| b[i]=='K'|| b[i]=='Q'|| b[i]=='S'|| b[i]=='X'|| b[i]=='Z')
                    {
                        c+='2';

                    }
                    else if(b[i]=='D' || b[i]=='T')
                    {

                        c+='3';
                    }
                    else if(b[i]=='L')
                    {
                        c+='4';
                    }
                    else if(b[i]=='M' || b[i]=='N')
                    {
                        c+='5';
                    }
                    else if(b[i]=='R')
                    {
                        c+='6';
                    }
                }
        }
        cout<<c<<endl;*/
    }
    return 0;
}
