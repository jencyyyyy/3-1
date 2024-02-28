#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include <ctype.h>
#include<vector>
#include <algorithm>

using namespace std;

vector <string> parts;

void partition(string str);
void checker(string part);
bool VariableChecker(string c);
bool IntegerChecker(string c); 
bool keywordChecker(string c);
bool constantChecker(string c);


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
    int len = str.length();
    
    for(int i = 0 ; i<len;i++ )  
    {  
        portion+=str[i];

        if(str[i] == ' '|| i == len- 1){
           // portion+='';
            parts.push_back(portion);
            portion = "";
        }
    } 

    for(int i = 0; i < parts.size(); i++){
        checker(parts[i]);
    }
        /*
    //checking vector components
     for(int i = 0; i < parts.size1(); i++)
        cout << parts[i];
        */
}


void checker(string part){

    if(keywordChecker(part))
    {
        cout<<part<< "- Keyword"<<endl;
    }
    else if(constantChecker(part))
    {
        cout<<part<< "- Constant"<<endl;
    }

    else if (VariableChecker(part))
    {
        cout <<part<< "- Integer Variable"<<endl;
    }
    else if ((part.length() <= 4) && IntegerChecker(part)) 
    {
        cout <<part<< "- ShortInt Number"<<endl;
    }
    else if (IntegerChecker(part))
    {
        cout <<part<< "- LongInt Number"<<endl;
    }
    else if (IntegerChecker(part))
    {
        cout <<part<< "- LongInt Number"<<endl;
    }
    else cout <<part<< "- Invalid Input"<<endl;
}


bool keywordChecker(string c)
{
c.pop_back();
vector<string> keywords = {"1","12","123","1234","12345","123456","1234567","12345678","123456789"};

  if (binary_search(keywords.begin(), keywords.end(), c))
        return true;
    else
        return false;

}


bool constantChecker(string c)
{   /*char * copy="";
    
    strcpy(copy, c);
    if (strcmp(copy, c) == 0)
		return true;
	else
        return false;
    */

    return c.find_first_not_of(c[0]) == string::npos;
}

bool VariableChecker(string c)
{

    c.pop_back();
    int firstChar=0, rest=1;
    bool pass = false;

    int len = c.length();

        for(int i=0;i<len;i++){
        c[i]=tolower(c[i]);
    }

    if(c[0]>='i' && c[0] <= 'n'){
        firstChar =1;
    }


    for (int i = 1; i <len-1; i++) {
        if (!(c[i] >= 'a' && c[i] <= 'z') && !(c[i] >= '0' && c[i] <= '9')) {
            rest = 0;
            break;
        }
    }

    if(firstChar && rest){
        pass = true;
    }
        return pass;
}

bool IntegerChecker(string x)
{
    x.pop_back();
    bool pass = false;
    int firstChar = 0, rst =1;
    
    if ((x[0] >= '1') && (x[0] <= '9')){
        firstChar = 1;
    }
    
    for (int i = 1; x[i] !='\0'; i++)
    {   
        if (isdigit(x[i]))
        {
            continue;
        }   
        else
        {
            rst = 0;
            break;
        }
    }

    if(firstChar && rst ){
        pass = true;
    }
    return pass;
}





