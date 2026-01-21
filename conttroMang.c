#include<stdio.h>
#include<stdlib.h>

void nhap(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d]: ", i);
		scanf("%d", (a + i)); 
	}
}
void xuat(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%5d", *(a + i));
	}
}
void taoMang(int** a, int* n)
{ 
	do
	{
		printf("Nhap n (>0): ");
		scanf("%d", n);
	} while (*n <= 0);
	*a = (int*)malloc((*n) * sizeof(int));
	if (*a == NULL)
	{
		printf("Khong du bo nho!\n");
		exit(0);
	}
	nhap(*a, *n);
}
int max(int* a, int n)
{
	int maax = *a;
	for (int i = 0; i < n; i++)
	{
		if(*(a+i) > maax)
			maax = *(a + i);
	}
	return maax;
}
int tong(int* a, int n)
{
	int tong =0 ;
	for (int i = 0; i < n; i++)
	{
		tong = tong + *(a + i);
	}
	return tong;
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void sapXep(int* a, int n)
{
	int tong = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if(*(a + i) > *(a + j))
				swap((a + i), (a + j));
		}
	}
}
int main()
{
    int n;
    int *a = NULL;

    taoMang(&a, &n);

    printf("Mang vua nhap:\n");
    xuat(a, n);

    printf("\nMax = %d", max(a, n));
    printf("\nTong = %d", tong(a, n));

    sapXep(a, n);
    printf("\nMang sau sap xep:\n");
    xuat(a, n);

    free(a);
    a = NULL;

    return 0;
}
