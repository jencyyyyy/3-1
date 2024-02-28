#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

bool is_Char(char ch){
    if (ch >= 'A' && ch <= 'Z') return true;
    if (ch >= 'a' && ch <= 'z') return true;
    return false;
}

bool is_Digit(char ch){
    if(ch >= '0' && ch <= '9') return true;
    return false;
}

void Count(string str){
    int words = 0, letters = 0, digits = 0, other = 0;

    if(str[0] != ' ') words++;

    for (int i=0;i< str.size();i++){
        if(str[i] == ' ' && (is_Char(str[i+1]) || is_Digit(str[i+1]))) words++;
        if(is_Char(str[i])) letters++;
        if(is_Digit(str[i])) digits++;
        if(!is_Char(str[i]) && !is_Digit(str[i])) other++;
    }

    cout<< "Words: "<<words<< endl;
    cout<< "Letters: "<<letters<< endl;
    cout<< "Digits: "<<digits<< endl;
    cout<< "Other: "<<other<< endl;

}

int main(){
    string str = " Robin is now 5 years old!";
    cout<<"String: "<<str<<endl;
    Count(str);
}
