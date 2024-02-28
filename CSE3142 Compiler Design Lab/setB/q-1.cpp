#include <bits/stdc++.h>
#include<ctype.h>
using namespace std;

bool isletter(char x)
{
    return (x >= 'A' and x <= 'Z');
}

bool isNum(char x){
    return ((x >= '0' and x <= '9') or x == '.');
}

bool isVariable(string c)
{   
    for(int i=0; i<c.length();i++){
        if(!isletter(c[i])){
                return 0;
            }
    }
    int firstChar=0, rest=1;
    bool pass = false;

    int len = c.length();
    cout<< len <<" " << c << endl;

    for(int i=0;i<len;i++){
        c[i]=tolower(c[i]);
    }
    cout<< c << endl;

    if((c[0]>='a' && c[0] <= 'h' )||( c[0]>='o' && c[0] <= 'z')){
        firstChar =1;
    }
     cout<<"First char: "<< firstChar << endl;

    for (int i = 1; i <len; i++) {
        if (!(c[i] >= 'a' && c[i] <= 'z') && !(c[i] >= '0' && c[i] <= '9')) {
            rest = 0;
            break;
        }
    }

    if(firstChar && rest){
        pass = true;
    }

    cout<<pass<<endl;;
        return pass;

        
}

int isFloat(string x)
{
    for(int i=0; i<x.length();i++){
        if(!isNum(x[i])){
                return 0;
        }
    }

    int count = 0;
    for (int i = x.size() - 1; x[i]; i--)
    {
        if (x[i] == '.') break;
        count++;
    }
    return count;
}

int main()
{
    string word = "0.000";
  //  cin >> word;
    if (isVariable(word)) 
    {
        cout << "Float Variable"<<endl;
    }
    else if (isFloat(word) == 2) 
    {
        cout << "Float Number"<<endl;
    }
    else if (isFloat(word) > 2)
    {
        cout << "Double Number"<<endl;
    }
    else cout << "Invalid Input or Undefined";
    return 0;
}