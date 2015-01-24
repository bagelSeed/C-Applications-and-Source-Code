#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    string first, second;
    int chCount[26];
    //initiallize char count
    for(int index = 0; index<26; index++)
    {
        chCount[index]=0;
    }

    cout << "Enter a string of line" << endl;
    getline(cin, first);
    cout << "enter a potential anagram" <<endl;
    getline(cin, second);

    int lenFirst = first.length();
    for(int i=0; i<lenFirst; i++)
    {
        char letter = tolower(first[i]);
        if(isalpha(letter))
        {
            chCount[letter-'a']++;
        }
    }

    int lenSecond = second.length();
    for(int i=0; i<lenSecond; i++)
    {
        char letter = tolower(second[i]);
        if(isalpha(letter))
        {
            chCount[letter-'a']--;
        }
    }

    bool isAnagram = true;
    for(int i=0; i<26;i++)
    {
        if(chCount[i]!=0)
        {
            isAnagram = false;
            break;
        }
    }

    if(isAnagram)
    {
        cout<<"the strings are anagram";
    }
    else
    {
        cout<<"the strings are not anagram";
    }

    return 0;
}
