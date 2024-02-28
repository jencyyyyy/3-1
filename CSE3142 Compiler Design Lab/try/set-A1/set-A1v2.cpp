#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include <ctype.h>
#include<vector>
//#include<boost/algorithm/string.hpp>

using namespace std;

vector <string> parts;


void partition(string str);
void checker(string part);
int VariableChecker(string c);
bool IntegerChecker(string c); 


int main(){

    fstream myFile;
    string line;
    myFile.open("input.txt ", ios::in);//read
    if(myFile.is_open()){
      /*  string line;
        while(getline(myFile,line)){ //all lines one by one
            cout<<line<<endl;
        }*/
        getline(myFile,line,'\0');
      //  cout<<line<<endl;
        myFile.close();

      }
      else{
        cout<<"ERROR! "<<endl;
      }
       /* while(!myFile.eof()){
            readFile.get();
        }
    */
    partition(line);
    
 
}

void partition(string str){

    string portion="";
    int len = size(str);
    
    for(int i = 0 ; i<len;i++ )  
    {  
        portion+=str[i];

        if(str[i] == ' '|| i == len- 1){
            parts.push_back(portion);
            portion = "";
        }
    } 

    for(int i = 0; i < parts.size(); i++){
        // cout<<parts[i]<<endl;
        checker(parts[i]);
    }
        


    //checking vector components
     /*for(int i = 0; i < parts.size(); i++)
        cout << parts[i] << '\n';
        */
}


void checker(string part){

    VariableChecker(part);
    
if ((part.size() <= 4) && IntegerChecker(part)) 
    {
        cout <<part<< "- ShortInt Number"<<endl;
    }
    else if (IntegerChecker(part))
    {
        cout <<part<< "- LongInt Number"<<endl;
    }
    else cout <<part<< "- Invalid Input or Undefined"<<endl;
}

void VariableChecker(string c){

    int value = 1;

    cout<<"Word 1 "<<c<<endl;
    if(c[0]>='i' && c[0] <= 'n'){
        value = 0;
    }

    cout<<"Word 2 "<<c<<endl;

    int len = size(c);

    for(int i=0;i<len;i++){
        c[i]=tolower(c[i]);
    }
    
    cout<<"Word 3 "<<c<<endl;
    for (int i = 1; i < len; i++) {
        if (!(c[i] >= 'a' && c[i] <= 'z')&& !(c[i] >= '0' && c[i] <= '9')) {
            return false;
        }
    }
    return true;

      /*  
      if(!(c[i]>='a' and c[i]<='z') and !(isdigit(c[i]))){
                return false;
            cout<<"Word 4 "<<c<<endl;
            break;
        }
        
        cout<<"Word 5 "<<c<<endl;*/
}

bool IntegerChecker(string x)
{
    if(x.length<=4) return false;
    bool mark = true;
    for (int i = 0; x[i]; i++)
    {
        if (isdigit(x[i]))
            continue;
        else
        {
            mark = false;
            break;
        }
    }
    return mark;
}



