#include<bits/stdc++.h>
#include <cstring>
using namespace std;

void splitString(string str)
{
    int now=0;
	string letter, digit, special,vowel,consonant,str1,str2,word;



	for (int i=0; i<str.length(); i++)
	{
		if (isdigit(str[i]))
			digit.push_back(str[i]);
		else if((str[i] >= 'A' && str[i] <= 'Z') ||
				(str[i] >= 'a' && str[i] <= 'z'))
			letter.push_back(str[i]);
		else
			special.push_back(str[i]);
	}

	for (int i=0; i<letter.length(); i++)
	{
	if (letter[i] == 'A' || letter[i] == 'E'||letter[i] == 'I' || letter[i] == 'O'||letter[i] == 'U' || letter[i] == 'a'||letter[i] == 'e' || letter[i] == 'i'||letter[i] == 'o' || letter[i] == 'u')
        vowel.push_back(letter[i]);
    else
        consonant.push_back(letter[i]);
	}
	cout <<"No.of Letter = "<< letter.length() << endl;
	cout <<"No.of digit = "<< digit.length() << endl;
	cout <<"No.of special = "<< special.length() << endl;
	cout <<"Letter = "<< letter << endl;
	cout <<"Digit = "<< digit << endl;
	cout <<"Special = "<< special << endl;
	cout <<"No.of vowel = "<< vowel.length() << endl;
	cout <<"No.of consonant = "<< consonant.length() << endl;
	cout <<"Vowel = "<< vowel << endl;
	cout <<"Consonant = "<< consonant << endl;

	// Used to split string around spaces.
    istringstream ss(str);

    // Traverse through all words
    // while loop till we get
    // strings to store in string word
    while (ss >> word)
    {
        now++;
        // print the read word
        cout << word << "\n";
        now++;
    if (word[0] == 'A' || word[0] == 'E'||word[0] == 'I' || word[0] == 'O'||word[0] == 'U' || word[0] == 'a'||word[0] == 'e' || word[0] == 'i'||word[0] == 'o' || word[0] == 'u')
        str1.append(word);
    else
        str2.append(word);
	}
	cout <<"No. of Word = "<< now << endl;
	cout<<"Vowel Word: "<<str1<<endl;
	cout<<"Consonant Word: "<<str2<<endl;
    }



int main()
{
	string str = "Md. Tareq Zaman erka, Part-3, 2011";
	splitString(str);
	return 0;
}
