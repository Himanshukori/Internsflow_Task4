#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const char alphanum[] = "0123456789!@#$%^&*_abcdefghijklmnopqrstuvwxyz";
int strLen = sizeof(alphanum);

int searchNum(string pass)
{
    int passLen = sizeof(pass);
    for (int i = 0; i < passLen; i++)
    {
        if (pass[i]>=48 && pass[i]<=57)
        {
            return 1;
        }
    }
    return 0;
}

int searchalpha(string pass)
{
    int passLen=sizeof(pass);
    for(int i=0;i<passLen;i++)
    {
        if(pass[i]>=65 && pass[i]<=90)
        {
            return 1;
        }
    }
    return 0;
}

int searchspec(string pass)
{
    int passLen=sizeof(pass);
    for(int i=0;i<passLen;i++)
    {
        if(pass[i]=='!' || pass[i]=='@' || pass[i]=='#' || pass[i]=='$' ||pass[i]=='%' || pass[i]=='^' || pass[i]=='&' || pass[i]=='*')
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    while (1)
    {
        int length;
        int num,alpha,spchar;
        char exit;
        string pass = "";
        cout << "Enter the length of password: ";
        cin >> length;
        if (length < 8)
        {
            cout << "The input length is wrong."<<endl;
            continue;
        }
        srand(time(0));

        for (int i = 0; i < length; i++)
        {
            pass = pass + alphanum[rand() % strLen];
        }
        cout<<"The password is: "<<pass<<endl;
        num=searchNum(pass);
        alpha=searchalpha(pass);
        spchar=searchspec(pass);
        cout<<"The strength of password is: ";
        if(num==1 && alpha==1 && spchar==0) cout<<"Strong";
        else if(num==0 && alpha==0 && spchar==1) cout<<"Strong";
        else if(num==0 && alpha==1 && spchar==1) cout<<"Strong";
        else if(num==1 && alpha==1 && spchar==1) cout<<"Very Strong";
        else cout<<"Weak";
        cout<<endl;
        cout << "Do you want to exit(Y/N):";
        cin >> exit;

        if (exit == 'Y' || exit == 'y')
        {
            break;
        }
    }
    return 0;
}