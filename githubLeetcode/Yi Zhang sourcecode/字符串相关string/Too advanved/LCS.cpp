//�����⡿ �����ַ����е�������ַ�������
//
//�����������ַ����е���������ָ�Ӹ����ַ�����������أ���һ��������ȥ�����ɸ��ַ�������һ��Ҳ��ȥ���������γɵ��ַ����С���������ַ�����X=��x0��x1������xm-1��������Y=��y0��y1������yk-1����X�������У�����X��һ���ϸ�����±�����<i0��i1������ik-1>��ʹ�ö����е�j=0��1������k-1����xij=yj�����磬X=��ABCBDAB����Y=��BCDB����X��һ�������С�
//
//���������������������ηֽ�������⣬��A=��a0��a1������am-1����B=��b0��b1������bm-1������Z=��z0��z1������zk-1��Ϊ���ǵ�����������С�����֤�����������ʣ�
//
//��1�� ���am-1=bn-1����zk-1=am-1=bn-1���ҡ�z0��z1������zk-2���ǡ�a0��a1������am-2���͡�b0��b1������bn-2����һ������������У�
//
//��2�� ���am-1!=bn-1������zk-1!=am-1���̺���z0��z1������zk-1���ǡ�a0��a1������am-2���͡�b0��b1������bn-1����һ������������У�
//
//��3�� ���am-1!=bn-1������zk-1!=bn-1���̺���z0��z1������zk-1���ǡ�a0��a1������am-1���͡�b0��b1������bn-2����һ������������С�
//
//����������A��B�Ĺ���������ʱ������am-1=bn-1�����һ�����һ�������⣬�ҡ�a0��a1������am-2���͡�b0��b1������bm-2����һ������������У����am-1!=bn-1����Ҫ������������⣬�ҳ���a0��a1������am-2���͡�b0��b1������bn-1����һ������������к��ҳ���a0��a1������am-1���͡�b0��b1������bn-2����һ������������У���ȡ�����нϳ�����ΪA��B������������С�

//��⣺
//
//����һ����ά����c[][]����c[i][j]��¼X[i]��Y[j] ��LCS �ĳ��ȣ�b[i][j]��¼c[i][j]��ͨ����һ���������ֵ��õģ��Ծ��������ķ���
//�������Ե����Ͻ��е��Ƽ��㣬��ô�ڼ���c[i,j]֮ǰ��c[i-1][j-1]��c[i-1][j]��c[i][j-1]���Ѽ����������ʱ���Ǹ���X[i] = Y[j]����X[i] != Y[j]���Ϳ��Լ����c[i][j]��
//
//�㷨������
//����ÿ�ε����������ϻ����󣨻���������ͬʱ���ƶ�һ������������(m + n)�ξͻ�����i = 0��j = 0���������ʱ��ʼ���ء�����ʱ��ݹ����ʱ�����෴��������ͬ�����㷨ʱ�临�Ӷ�Ϊ��(m + n)��

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
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <cassert>
#include <strstream>
#include <new>

using namespace std;


#define MAXLEN 100

void LCSLength(char *x, char *y, int m, int n, int c[][MAXLEN], int b[][MAXLEN])
{
    int i, j;

    for(i = 0; i <= m; i++)
        c[i][0] = 0;
    for(j = 1; j <= n; j++)
        c[0][j] = 0;
    for(i = 1; i<= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 0;
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = -1;
            }
        }
    }
}

void PrintLCS(int b[][MAXLEN], char *x, int i, int j)
{
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 0)
    {
        PrintLCS(b, x, i-1, j-1);
        printf("%c ", x[i-1]);
    }
    else if(b[i][j] == 1)
        PrintLCS(b, x, i-1, j);
    else
        PrintLCS(b, x, i, j-1);
}

int main(int argc, char **argv)
{
    char x[MAXLEN] = {"ABCBDAB"};
    char y[MAXLEN] = {"BDCABA"};
    int b[MAXLEN][MAXLEN];
    int c[MAXLEN][MAXLEN];
    int m, n;

    m = strlen(x);
    n = strlen(y);

    LCSLength(x, y, m, n, c, b);
    PrintLCS(b, x, m, n);
    cout<<"--"<<endl;
    return 0;
}
