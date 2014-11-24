#include <iostream>
#include <stdlib.h>
using namespace std;
void swap(int &x, int &y);
int FindPivot(int i, int j,int *A);
int Partition(int i, int j, int pivot,int *A,int num);
void QuickSort(int i, int j,int *A,int num);
void swap(int &x, int &y)
{
	int t;
	t = x;
	x = y;
	y = t;
}
int FindPivot(int i, int j,int *A)
{
	int firstkey, k;
	firstkey = A[i];
	for (k = i + 1; k <= j; k++)
	{
		if (A[k] > firstkey){ return k; }
		else if (A[k] < firstkey){ return i; }
	}
	return -1;
}
int Partition(int i, int j, int pivot, int *A,int num)
{
	int l, r;
	l = i;
	r = j;
	do
	{
		swap(A[l], A[r]);
		while (A[l] < pivot){ l++; }
		while (A[r] >= pivot){ r--; }
		cout << pivot << "          ";
		for (int i = 0; i < num; i++)
		{
			cout << A[i] << "    ";
		}
		cout << endl;
	} while (l <= r);
	return l;
}
void QuickSort(int i, int j, int *A,int num)
{
	int pivot, pivotindex, k;
	pivotindex = FindPivot(i, j, A);
	if (pivotindex != -1)
	{
		pivot = A[pivotindex];
		k = Partition(i, j, pivot, A,num);
		QuickSort(i, k-1, A,num);
		QuickSort(k, j, A,num);
	}
}
int main()
{
	int num,*A;
	cout << "please input the number of int arry:";
	cin >> num;
	A = new int[num];
	for (int i = 0; i < num; i++)
	{
		cin >> A[i];
	}
	QuickSort(0, num - 1, A,num);
	cout << "result is:" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << A[i] << endl;
	}
	delete[] A;
	system("Pause");
	return 0;
}