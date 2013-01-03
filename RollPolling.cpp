/*
 * Describe:使用轮询的方法来知道短string的字符是不是都
 * 在长string中的
 * author: andrewRong
 * */
#include <string>

using namespace std;

bool StringContain(string longString,string shortString)
{
    for(int i = 0; i < shortString.length();i++)
    {
	for(int j = 0; j < longString.length();j++)
	{
	    if(longString[j] == shortString[i])
	    {
		break;
	    }
	}

	if(j == longString.length())
	{
	    return false;
	}
    }

    return true;
}
