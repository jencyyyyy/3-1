#include<bits/stdc++.h>
#include <cstring>
using namespace std;
int i,check;
bool integerVariable(string str){

    char first= str.at(0);

    if((first>='i' && first <= 'n' )|| (first>='I' && first <= 'N' )){
        for(i=1;i<str.length();i++){
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
        return false;
    }

    return true;
    
}


int main()
{
	string str;
    cout<<"Enter :";
    cin>> str;

//a 
    if(integerVariable(str)){
        cout<<"Integer Variable"<<endl;
    }
//b 
    else if(shortIntNumber(str)){
        cout<<"short Int number"<<endl;
    }
//c
    else if(LongIntNumber(str)){
        cout<<"Long Int number"<<endl;
    }
//d
    else if(floatVariable(str)){
        cout<<"float Variable"<<endl;
    }
//e
    else if(floatVariable(str)){
        cout<<"float Variable"<<endl;
    }
//f
    else if(floatVariable(str)){
        cout<<"float Variable"<<endl;
    }
//g
    else if(floatVariable(str)){
        cout<<"float Variable"<<endl;
    }
//h
    else if(floatVariable(str)){
        cout<<"float Variable"<<endl;
    }
//i
    else if(floatVariable(str)){
        cout<<"float Variable"<<endl;
    }
//j
    else{
        cout<<"Invalid or Undefined"<<endl;
    }   
    return 0;
}
