/*
 * Describe:使用hashtable来做
 * author: andrewRong
 * */
#include <string>
#include <map>
#include <iterator>
#include <utility>

using namespace std;
#if 0
//这是我第一次想到的，就是使用C++的map容器,这个程序的效率能不能达到O(m+n)???
bool StringContain(string longString,string shortString)
{
    map<char,int> hash;

    int i = 0;

    for(i = 0; i < static_cast<int>(longString.length()); i++)
    {
	hash[longString[i]] = 1;
    }
    
    for(i = 0; i < static_cast<int>(shortString.length()); i++)
    {
	if(hash[shortString[i]] != 1)
	{
	    break;
	}
    }

    if(i != static_cast<int>(shortString.length()))
    {
	return false;
    }
    else
    {
	return true;
    }
}
#endif

bool StringContainA(string longString,string shortString)
{
    map<char,int> hash;
    pair<map<char,int>::iterator,bool> insertPair;
    int i = 0;

    for(i = 0; i < static_cast<int>(longString.length()); i++)
    {
	hash[longString[i]] = 1;
    }

    for(i = 0; i < static_cast<int>(shortString.length()); i++)
    {
	insertPair = hash.insert(pair<char,int>(shortString[i],1));

	if(insertPair.second == true)
	{
	    break;
	}
    }

    if(i != static_cast<int>(shortString.length()))
    {
	return false;
    }
    else
    {
	return true;
    }
}

bool StringContain(string longString,string shortString)
{
    int hashtable[26] = {0};
    int i = 0;

    for(i = 0; i < static_cast<int>(longString.length()); i++)
    {
	hashtable[static_cast<int>(longString[i] - 'A')] = 1;
    }

    for(i = 0; i < static_cast<int>(shortString.length()); i++)
    {
	if(!hashtable[static_cast<int>(shortString[i] - 'A')])
	{
	    break;
	}
    
    }

    if(i != static_cast<int>(shortString.length()))
    {
	return false;
    }
    
    return true;
}
