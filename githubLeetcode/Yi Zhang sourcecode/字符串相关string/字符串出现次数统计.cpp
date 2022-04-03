
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <cassert>
#include <strstream>
#include <new>
using namespace std;


//非成员函数find是线性时间复杂度的，他挨个遍历你传给他的区间内的元素，
//用等于号运算符判断是不是相等。
//而set的成员函数find是logn时间复杂度的，他利用set内部的数据结构
//（一般来说是红黑树）来寻找元素，依据是set内部的比较器，
//如果你没有显式给他比较器的话，默认就是小于号运算符
//
//所以：这两个函数会得到不一样的结果，
//如果你定义的等于号和小于号是不一致的话。如果你要通过等于号查找的话，
//用非成员函数的find
//set,map里的find背后是operator<就可以了，
//比较相等其实调用a<b 和！(a<b)2个操作就完成了，
//so,只要写<就行了，而不是调用默认的==


//Read a file of this format:
//
//japan
//usa
//japan
//russia
//usa
//japan
//japan
//australia
//
//Print the output in the following format:
//<countSetry> : <countSet>
//So for above file output would be:
//
//japan : 4
//usa : 2
//australia : 1
//russia : 1
//
//Note that since australia and russia both have countSet as 1,
//the name are sorted, 'a' before 'r'. Do it in the most efficient way.


class myClass
{

public:
	string nation;
	int times;
	myClass(string s):nation(s),times(0){}
	bool operator<(const myClass& rhs) const
	{
		if(times>rhs.times)	return true;
		if(times<rhs.times)	return false;
		if(nation<rhs.nation) return true;
		return false;
	}
	bool operator==(const myClass& rhs) const
	{
		return nation==rhs.nation;
	}
};
int main()
{

	set<myClass> countSet;

	string str;
	ifstream inf("in.txt");
	while(getline(inf,str))
	{
		myClass tmp(str);
		set<myClass>::iterator tmpIt;
		if((tmpIt=find(countSet.begin(),countSet.end(),tmp))==countSet.end()){
			tmp.times=1;
			countSet.insert(tmp);
		}
		else
		{
			tmp.times=tmpIt->times+1;
			countSet.erase(tmpIt);
			countSet.insert(tmp);
		}
		for(set<myClass>::iterator it=countSet.begin();it!=countSet.end();it++)
		{
			cout<<it->nation<<it->times<<endl;
		}
		cout<<"---"<<endl<<endl;
	}

	for(set<myClass>::iterator it=countSet.begin();it!=countSet.end();it++)
	{
		cout<<it->nation<<it->times<<endl;

	}




}

