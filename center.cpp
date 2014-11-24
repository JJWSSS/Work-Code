#include <iostream>
#include <stdlib.h>
using namespace std;
void Floyd(int n,int **c);
void Floyd(int n,int **c)
{
    int i,k,j;
    for (k=1;k<n;k++)
    {
        for (i=1;i<n;i++)
        {
            for (j=1;j<n;j++)
            {
                if (c[i][k]+c[k][j]<c[i][j])
                {
                    c[i][j]=c[i][k]+c[k][j];
                }
            }
        }
    }
}
int main()
{
    int i,j,n,**c,*d,minnum,p;
    cout << "顶点个数:";
    cin >> n;
    n++;
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
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			cout << "请输入" << i << "到" << j << "的邻接状况:";
			cin >> c[i][j];
		}
	}
	Floyd(n,c);
	d = new int [n];
	for (i=1;i<n;i++)
    {
        d[i]=c[1][i];
        for (j=1;j<n;j++)
        {
            if (d[i]<c[j][i]) {d[i]=c[j][i];}
        }
    }
    p=1;
    minnum=d[1];
    for (i=1;i<n;i++)
    {
        if (minnum>d[i])
        {
            minnum=d[i];
            p=i;
        }
    }
    cout << "中心点是" << p << "    "  <<minnum;
    for (i = 0; i < n; i++)   //内存释放
	{
		delete[] c[i];
	}
	delete[] c;
	delete[] d;
	return 0;
}
