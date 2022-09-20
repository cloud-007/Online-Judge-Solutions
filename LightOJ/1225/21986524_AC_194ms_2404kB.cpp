#include<bits/stdc++.h>
using namespace std;
int reverse( int num);
bool isPalindrome(int num);

bool isPalindrome(int num)
{
    if(num==reverse(num))
        return true;
    return false;
}
int reverse(int num)
{
    int digit=(int )log10(num);
    if(num==0)
        return 0;
    return ((num%10 * pow(10,digit)) + reverse(num/10));
}

int main()
{
    int n,casee=1;
    cin>>n;
    while(n--){
        int a;
    cin>>a;
    {
        if(isPalindrome(a))
            cout<<"Case "<<casee<<": Yes"<<endl;
        else
            cout<<"Case "<<casee<<": No"<<endl;
        casee++;
    }
    }
    return 0;
}