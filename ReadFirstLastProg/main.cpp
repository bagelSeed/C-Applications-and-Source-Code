#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile;
    string filename = "words.txt";

    while(true)
    {
        infile.open(filename.c_str(), ifstream::in);
        if(!infile.is_open())
        {
            cout<<"file cannot open "<<filename<<endl;
            cout<<"please enter another filename"<<endl;
            getline(cin, filename);
        }
        else
        {
            break;
        }
    }

    int count = 0;

    while(infile.good())
    {
        string line;
        getline(infile, line);
        if(line[0]=='a' || line[line.length()-1] == 'a')
        {
            count++;
            cout<<"word "<<count<<" is "<< line<<endl;
        }
    }

    infile.close();

    return 0;
}
