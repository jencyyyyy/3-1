#include<iostream>
#include<fstream>

using namespace std;

bool checkIntVariable(string word){
    //cout << word[0] << " = first letter" << endl;
    if(!(word[0] >= 'i' && word[0] <= 'n') && !(word[0] >= 'I' && word[0] <= 'N')){
        return false;
    }
    for(int i = 1; i< word.size(); i++){
        if(!(word[i] >= 'a' && word[i] <= 'z') && !(word[i] >= 'A' && word[i] <= 'Z') && !(word[i] >= '0' && word[i] <= '9')){
            return false;
        }
    }
    return true;
}

int main(){
    char ch;
    string word = "";
    ifstream readFile("chumki.txt");
    while(!readFile.eof()){
        readFile.get(ch);
        if(ch == ' ' || ch == ',' || ch == '.' || ch == '\0'){
            //cout << word << endl;
            if(checkIntVariable(word)){
                cout << word << " \t - Int Variable" << endl;
            }
            else {
                cout << word <<  "\t not int variable" << endl;
            }
            word = "";
        }
        else {
            word = word + ch;
        }
    }
    return 0;
}