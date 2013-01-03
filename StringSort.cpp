/*
 * Describe:先对两个字符串进行sort，然后再进行比较,
 * 这里排序使用了两种方法，一种是快排，一种是计数排序
 * author: andrewRong
 * */

#include <string>
#include <cassert>
#include <iostream>
#include <cstring>
using namespace std;
void Swap(char& left,char& right)
{
    char tmp = left;
    left = right;
    right = tmp;
}

int Partition(string& str,int low,int high)
{
    int meta = str[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
	if(str[j] <= meta)
	{
	    i++;
	    Swap(str[i],str[j]);
	}
    }
    
    Swap(str[i+1],str[high]);

    return i + 1;
}
/*
 * low可能小于0而high可能大于high,原因是因为快速排序出现了极端的现象
 * */
void QuickSort(string& str, int low,int high)
{
    if(low < high)
    {
	int middle = Partition(str,low,high);
	QuickSort(str,low,middle - 1);
	QuickSort(str,middle + 1, high);
    }
}

void CountSort(const string& str,string& sortedString)
{
    int help[26] = {0};

    memset(help,0,26 * sizeof(int));

    for(int i = 0; i < static_cast<int>(str.length()); i++)
    {
	char tmp = str[i] - 'A';
	help[static_cast<int>(tmp)]++;
    }

    for(int i = 1; i < 26; i++)
    {
	help[i] = help[i] + help[i - 1];
    }

    for(int i = 0; i < static_cast<int>(str.length()); i++)
    {
	int tmp = help[static_cast<int>(str[i] - 'A')] - 1;
	sortedString[tmp] = str[i];
	help[static_cast<int>(str[i] - 'A')]--;
    }
}

//一个注意点就是i与j不是同时进行++操作的，因为有短string可能有重复的字符出现的
bool StringContain(string longString,string shortString)
{
    string tmpLongString = longString;
    string tmpShortString = shortString;

    CountSort(tmpLongString,longString);
    CountSort(tmpShortString,shortString);

    
    int i = 0;
    int j = 0;

    for(; i < shortString.length(); i++)
    {
	for(; j < longString.length(); j++)
	{
	    if(shortString[i] == longString[j])
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
