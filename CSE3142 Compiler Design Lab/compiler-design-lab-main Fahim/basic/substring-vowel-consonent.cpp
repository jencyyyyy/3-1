#include <iostream>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;

string vowel = "", consonent = "", word = "";

bool isVowel(char c){
    char ch = tolower(c);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

void setWord(string word){
    if (isVowel(word[0])){
        
        vowel = vowel + word + " ";
    }
    else{
        consonent = consonent +  word + " ";
    }
}

void subString(string str){
    for (auto x : str){
        if (x == ' ' || x == EOF || x=='\0' || x == '.' || x==','){
            setWord(word);
            word = "";
        }
        else{
            word += x;
        }
    }
    setWord(word);
}

int main()
{
    string str = "Hello everyone! How are you today?";
    // ifstream readFile("input.txt");
    // while(getline(readFile, str)){
    //     subString(str);
    // }
    subString(str);
    cout <<"Vowel Substring: "<< vowel << endl;
    cout <<"Consonent Substring: "<< consonent << endl;
    return 0;
}