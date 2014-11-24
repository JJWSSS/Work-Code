#include <iostream>
#include <stdlib.h>
using namespace std;
#define MX 10000
void stateChange(int src, int obj, int **c,int n);
void stateChange(int src, int obj, int **c,int n)//状态转换函数
{
	int s,*D,i,t,*v,min,j,*p,num,*q,x,y;
	p = new int[n];
	q = new int[n];
	D = new int[n];
	v = new int[n];
	for (t = 0; t < n; t++)
	{
		v[t] = t;
		if (t != src) { p[t] = src; }
		else {
			p[t] = -1;}
	}
	t = 0;
	s = src;
	//cout << "run2!" << endl;
	for (i = 0; i < n; i++)
	{
		if (i != src) { D[i] = c[src][i]; }
	}
	for (j = 0; j < n; j++)
	{
		if (v[j] == s) { v[j] = -1; }
		/*for (p = 0; p <= 0; p++)
		{
		if (v[j] = S[p]) { v[j] = -1; }
		}*/
	}
	for (i = 1; i <= n - 1; i++)
	{
		min = 10001;
		for (j = 0; j < n; j++)
		{
			if (v[j] != -1 && D[j] < min)
			{
				min = D[j];
				num = j;
			}
		}
		v[num] = -1;
		for (j = 0; j < n; j++)
		{
			if (v[j] != -1 && (D[j] > D[num]+c[num][j] ))
			{
				D[j] = D[num] + c[num][j];
				p[j] = num;
			}
		}
	}
	//cout << "run3!" << endl;
	/*for (y = 0; y < n; y++)
	{
		cout << p[y] << endl;
	}*/
	/*for (i=0;i<n;i++)
    {
        if (i!=src)
        {
            cout << src << "到" << i << "个顶点的距离为" << D[i] <<endl;
        }
    }*/
	y = 0;
	x = obj;
	for (;;)
	{
		if (p[x] == src) { break; }
		q[y] = p[x];
		x = p[x];
		y++;
	}
	//cout << "run4!" << endl;
	if (y == 0) { cout << src  << "运行到"  << obj << endl; }
	else
	{
		cout << src << "运行到" << q[y-1] << endl;
		for (i = y - 1; i > 0; i--)
		{
			cout << q[i] << "运行到" << q[i-1] << endl;;
		}
		cout << q[0] << "运行到" << obj << endl;;
	}
	for (i=0;i<n;i++)
    {
        if (i!=src)
        {
            cout << "D[" << i << ']' << "\t"  << D[i] << endl;
        }
    }
	delete []p;
	delete []q;
	delete []v;
	delete []D;
}
int main()
{
	int src, obj,i,j, **c,n;
	cout <<"请输入源状态:";//源状态输入
	cin >> src;
	cout << "请输入目标状态:";//目标状态输入
	cin >> obj;
	cout << "请输入工况个数:";//工况个数输入
	cin >> n;
	c = new int *[n];
	if (c == NULL)//动态内存分配
	{
		cout <<"Fail" << endl;
		exit(0);
	}
	for (i = 0; i < n; i++)
	{
		c[i] = new int[n];
		if (c[i] == NULL)
		{
			cout << "Fail" << endl;
			exit(0);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "请输入" << i << "到" << j << "的邻接状况:";
			cin >> c[i][j];
		}
	}
	//cout << "run1!" << endl;
	stateChange(src, obj, c,n);
	for (i = 0; i < n; i++)   //内存释放
	{
		delete[] c[i];
	}
	delete[] c;
	//system("pause");
	return 0;
}
