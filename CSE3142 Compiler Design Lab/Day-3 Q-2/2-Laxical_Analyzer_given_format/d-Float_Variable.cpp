//2-a) Integer variable = (i-n,l-N)(a-z,A-Z,0-9)*
#include<iostream>
#include<string.h>
int i,check;
using namespace std;
int main(){

    string str;
    cin>>str;

    char first= str.at(0);

    if((first>='a' && first <= 'h' )|| (first>='A' && first <= 'H' )|| (first>='o' && first <= 'z') || (first>='O' && first <= 'Z' ))
    {
        for(i=1;i<str.length();i++)
        {
            if(isalpha(str[i]) || isdigit(str[i])){
                check=1;
            }
            else{
                check=0;
                break;
            }
        }
    }

    if(check) {
        cout<<"Float variable"<<endl;
    }
    else{
        cout<<"Wrong Float variable format"<<endl;
    }


    return 0;
}


