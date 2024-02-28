#include<bits/stdc++.h>
/*
#include<stdio.h>
#include<iostream>
#include<map>
#include<iterator>
#include<set>
*/
using namespace std;

// Input
// @ = Eps
// # = id

/*
S->Bb
S->Cd
B->aB
B->@
C->cC
C->@
*/

/*
S->ABCDE
A->a
A->@
B->b
B->@
C->c
D->d
D->@
E->e
E->@
*/

map<char, vector<string>> grammar;
map<char, set<char>> first;
map<char, set<char>> follow = {{'S', {'$'}}}; // change the starting variable as per required
map<char, string> usedCharacters = {{'@', "Eps"}, {'#', "id"}};

void grammarInput();
void computeFirst();
void computeFollow();
bool isVariable(char x);

int main()
{
    grammarInput();
    computeFirst();
    computeFollow();
}

void grammarInput()
{
    char variable, x;
    string rule;
    freopen("i.txt", "r", stdin);
   
    int no;
   // cout<<"Enter grammar count: ";
    cin >>no;


    while (no--)
    {
        cin >> variable >> x >> x >> rule;
        grammar[variable].push_back(rule);
    }
    
    // Print grammar
    cout << "__________Grammar:\n";
    for (auto x: grammar)
    {
        for (string rule: x.second)
        {
            cout << x.first << " -> " << rule << "\n";
        }
    }
}

void computeFirst()
{
    for (auto g: grammar)
    {
        for (string x: g.second)
        {
            if (x[0] >= 'A' and x[0] <= 'Z') continue;
            first[g.first].insert(x[0]); //direct terminals 
           // cout<<" g.first "<< g.first << " first[g.first] " << first.begin()->first<<endl;
        }

      /*  
      cout<<"Elements if the map for first"<<endl;
        map<char, set<char>>::iterator it = first.begin();

        for(it;it!=first.end();++it){
            cout<< it->first << " " ;
            set<char>::iterator itr = it->second.begin();

            for(itr; itr!= it->second.end();++itr){
               cout<< *itr << " ";
            }
            cout<<endl;

        }*/
    }
  //  for (int i = 1; i <= 1; i++)
 //   {
        for (auto g: grammar)
        {
            for (string x: g.second)//rules iterate
            {
                bool next = false, eps;
                for (char v: x)
                {
                    if (v >= 'A' and v <= 'Z')
                    {
                        eps = false;
                        for (auto f: first[v])
                        {
                            if (f == '@') eps = true;
                            first[g.first].insert(f);

                          /*   map<char, set<char>>::iterator it = first.begin();

                                for(it;it!=first.end();++it){
                                    cout<< "Checker: "<< it->first << " " ;
                                }*/

                                
                            if (f == '@' and v != x.back()) 
                            {
                                first[g.first].erase('@');
                            }
                        }

                        if (eps) next = true;
                        else next = false;
                    }
                    else first[g.first].insert(v);
                    if (!next) break; 
                }
            }
        }
  //  }
    // Print first
    cout << "__________First:\n";
    for (auto x: first)
    {
        cout << x.first << " = ";
        for (char ch: x.second)
        {
            if (usedCharacters.find(ch) == usedCharacters.end())
            {
                cout << ch << " ";
            }
            else cout << usedCharacters[ch] << " ";
        }
        cout << "\n";
    }
}

void computeFollow()
{
    for (auto g: grammar)
    {
        for (string rule: g.second)
        {
            for (int i = 0; rule[i]; i++)
            {
                if (isVariable(rule[i]) and i < rule.size() - 1)
                {
                    if (!isVariable(rule[i + 1]))
                    {
                        follow[rule[i]].insert(rule[i + 1]);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        for (auto g: grammar)
        {
            for (string rule: g.second)
            {
                for (int v = 0; rule[v]; v++)
                {
                    if (isVariable(rule[v]))
                    for (int f = v + 1; rule[f]; f++)
                    {
                        if (!isVariable(rule[f]))
                        {
                            follow[rule[v]].insert(rule[f]); //insert into follow
                            break;
                        }
                        if (isVariable(rule[f]))
                        {
                            for (char x: first[rule[f]])
                            {
                                follow[rule[v]].insert(x);
                            }
                            if (!first[rule[f]].count('@')) break;
                            if (first[rule[f]].count('@') and f + 1 == rule.size())
                            {
                                for (char x: follow[g.first])
                                {
                                    follow[rule[v]].insert(x);
                                }
                            }
                        }
                    }
                    // Follow of LHS if it is a last variable of rule
                    if (v + 1 == rule.size() and isVariable(rule[v]))
                    {
                        for (char x: follow[g.first])
                        {
                            follow[rule[v]].insert(x);
                        }
                    }
                }
            }
        }
    }
    // Print follow
    cout << "__________Follow:\n";
    for (auto x: follow)
    {
        cout << x.first << " = ";
        x.second.erase('@');
        for (char ch: x.second)
        {
            if (usedCharacters.find(ch) == usedCharacters.end())
            {
                cout << ch << " ";
            }
            else cout << usedCharacters[ch] << " ";
        }
        cout << "\n";
    }
}

bool isVariable(char x)
{
    return (x >= 'A' and x <= 'Z');
}