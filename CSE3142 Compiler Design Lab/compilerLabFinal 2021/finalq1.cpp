#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<vector>
#include<String>


using namespace std;
vector <string> parts;

void partition(string str);
void checker(string part);
bool isCharacterVariable(string x);
bool isIntegerVariable(string x);
bool isBinaryNumber(string x);
bool isIntegerNumber(string x);

int main(){

    fstream myFile;
    char c;
    string line;

    /*myFile.open("input.txt ", ios::in);
    if(myFile.is_open()){
        getline(myFile,line,'\0');
        myFile.close();

      }
      else{
        cout<<"ERROR! "<<endl;
      }*/
    /*  fstream myFile;
      myFile.open("input.txt");

    while(!myFile.eof()){
        myFile.get(c);
    }
    if(isalnum(c)){
            line[i++] = c;
        }*/


    freopen("input.txt", "r", stdin);
    getline(cin, line);
    cout << line << endl;
    partition(line);
    
}

void partition(string str){

    string portion="";
    int len = str.length();
    
    for(int i = 0 ; i<len;i++ )  
    {   /*
        if(str[i]==','){
            continue;
        }else{
            
        }
        */
        portion+=str[i];

        if(str[i] == ' '||i == len- 1){
            
            parts.push_back(portion);
            portion = "";
        }
        
    } 

    for(int i = 0; i < parts.size(); i++){
        parts[i].pop_back();
        checker(parts[i]);
    }

        
  for(int i = 0; i < parts.size(); i++){
      //  parts[i].pop_back();
        cout << parts[i]<<"|";
    }
        
        
}

void checker(string part){

    if(isCharacterVariable(part))
    {
        cout<<part<< "\tCharacter variable"<<endl;
    }
    else if(isIntegerVariable(part))
    {
        cout<<part<< "\t\tInteger Variable"<<endl;
    }
   else if (isBinaryNumber(part))
    {
        cout <<part<< "\t\tBinary Variable\n";
    }
    else if (isIntegerNumber(part))
    {
        cout <<part<< "\t\tInteger Number"<<endl;
    }
    else if (part == ",")
    {
        cout <<part<< "\t\tUndefined"<<endl;
    }

    else cout <<part<< "\t\tUndefined"<<endl;
}

bool isCharacterVariable(string x)
{   

    int firstFour=0, rest=1;
    bool pass = false;
    int len = x.length();

    if (len< 4)
    {
        return false;
    }

    for(int i=3;i<len;i++){
        x[i]=tolower(x[i]);
    }

    if (x[0] == 'c' && x[1] == 'h' && x[2] == '_' && ((x[3] >= 'a' && x[3] <= 'z')||(x[3] >= '0' && x[3] <= '9')))
    {
        firstFour = 1;
    }
 //   x.pop_back();
  //  cout<<"char: "<<x<<'|'<<endl;
    for (int i = 4; i <len-1; i++) {
        if (!(x[i] >= 'a' && x[i] <= 'z') && !(x[i] >= '0' && x[i] <= '9')) {
            rest = 0;
            break;
        }
    }

    
    if(firstFour && rest){
        pass = true;
    }
    
    return pass;

}

bool isIntegerVariable(string c)
{
  //  cout<<"c: "<<c<<endl;

  //  c.pop_back();
    int firstThree=0, rest=1;
    bool pass = false;

    int len = c.length();

    if (len< 3)
    {
        return false;
    }
    for(int i=3;i<len;i++){
        c[i]=tolower(c[i]);
    }
 
    if(c[0]>='i' && c[0] <= 'n' && c[1] == '_' && ((c[2] >= 'a' && c[2] <= 'z')||(c[2] >= '0' && c[2] <= '9'))){
        firstThree =1;
    }
  //  cout<<"firstThree"<<firstThree<<endl;

  //  c.pop_back();
   // cout<<"char: "<<c<<'|'<<endl;

    for (int i = 3; i < len-1; i++) {
        if (!(c[i] >= 'a' && c[i] <= 'z') && !(c[i] >= '0' && c[i] <= '9')) {
            rest = 0;
            break;
        }
    }

    if(firstThree && rest){
        pass = true;
    }
    return pass;
}

bool isBinaryNumber(string x)
{
  //  x.pop_back();
  

    int len = x.length();

    int firstTwo=0, rest=1;
    bool pass = false;


    if (len< 2 && !(x[0] == '0'))
    {
        return false;
    }
    
    if (x[0] == '0' && (x[1] == '0' || x[1]== '1'))
    {
        firstTwo = 1; 
    }

    for (int i = 2; i< len-2; i++)
    {
        if (x[i] != '0' and x[i] != '1')
        {
            rest= 0;
        }
    }

    if(firstTwo && rest){
        pass = true;
    }
    return pass;
}

bool isIntegerNumber(string x)
{
//    x.pop_back();

   // cout<<"The integer num: "<<x<<'|'<<endl;
    bool pass = false;

    int len = x.length();

    int firstChar = 0, rest =1;

    if(len<1 && !((x[0] >= '1') && (x[0] <= '9'))){
        return false;
    }

    if ((x[0] >= '1') && (x[0] <= '9')){
        firstChar = 1;
     //   cout<<"first no: "<<x[0]<<'|'<<endl;
    }
    
    for (int i = 1; i<len-2; i++)
    {   
        if (!(x[i] >= '1' && x[i] <= '9'))
        {
            rest = 0;
        //    cout<<"numbers no: "<<x[i]<<'|'<<endl;
        }   
    }

    if(firstChar && rest ){
        pass = true;
    }

    return pass;
}
