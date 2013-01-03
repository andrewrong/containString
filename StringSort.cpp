/*
 * Describe:先对两个字符串进行sort，然后再进行比较,时间复杂度为O(nlgn + mlogm + m + n)
 * author: andrewRong
 * */

#include <string>
#include <cassert>
#include <iostream>

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

//一个注意点就是i与j不是同时进行++操作的，因为有短string可能有重复的字符出现的
bool StringContain(string longString,string shortString)
{
    QuickSort(longString,0,longString.length() - 1); 
    QuickSort(shortString,0,shortString.length() - 1); 
    
    cout<<longString<<" "<<shortString<<endl;
    
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
