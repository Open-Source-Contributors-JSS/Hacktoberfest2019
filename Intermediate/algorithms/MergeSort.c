#include<stdio.h>

void Merge(int l[], int r[], int a[], int n, int ls, int rs)
{
	int i=0, j=0, k=0;
	while(i < ls && j < rs)
	{
		if (l[i] <= r[j])
		{
			a[k] = l[i];
			i++;
		}
		else
		{
			a[k] = r[j];
			j++;
		}
		k++;
	}
	while(i < ls)
	{
		a[k] = l[i];
		i++;
		k++;
	}
	while(j < rs)
	{
		a[k] = r[j];
		j++;
		k++;
	}
}

void MS(int a[], int n)
{
	if (n < 2)
		return;
	int mid = ceil(n/2);
	int ls = mid;
	int rs = n-mid;
	int l[ls], r[rs];
	for (int i = 0; i < mid; ++i)
	{
		l[i] = a[i];
	}
	for (int i = mid; i < n ; ++i)
	{
		r[i-mid] = a[i];
	}
	MS(l, ls);
	MS(r, rs);
	Merge(l, r, a, n, ls, rs);
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	MS(a, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",a[i]);
	}
	return 0;
}