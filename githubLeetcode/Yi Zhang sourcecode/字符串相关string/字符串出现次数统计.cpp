
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


//�ǳ�Ա����find������ʱ�临�Ӷȵģ������������㴫�����������ڵ�Ԫ�أ�
//�õ��ں�������ж��ǲ�����ȡ�
//��set�ĳ�Ա����find��lognʱ�临�Ӷȵģ�������set�ڲ������ݽṹ
//��һ����˵�Ǻ��������Ѱ��Ԫ�أ�������set�ڲ��ıȽ�����
//�����û����ʽ�����Ƚ����Ļ���Ĭ�Ͼ���С�ں������
//
//���ԣ�������������õ���һ���Ľ����
//����㶨��ĵ��ںź�С�ں��ǲ�һ�µĻ��������Ҫͨ�����ںŲ��ҵĻ���
//�÷ǳ�Ա������find
//set,map���find������operator<�Ϳ����ˣ�
//�Ƚ������ʵ����a<b �ͣ�(a<b)2������������ˣ�
//so,ֻҪд<�����ˣ������ǵ���Ĭ�ϵ�==


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

