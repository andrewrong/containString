#include <iostream>
#include <string>
#include <cassert>
#include <fstream>

using namespace std;

bool StringContain(string longString,string shortString);

int main()
{
    string filename = "./test.txt";
    ifstream infile(filename.c_str(),ios_base::in);
    
    if(!infile)
    {
	cerr<<"your file is not exist"<<endl;
	return -1;
    }

    int testNum = 0;
    string longString,shortString;
    infile>>testNum;

    for(int i = 0; i < testNum; i++)
    {
	infile >> longString >> shortString;

	if(StringContain(longString,shortString))
	{
	    cout<<"true"<<endl;
	}
	else
	{
	    cout<<"false"<<endl;
	}
    }

    return 0;
}
