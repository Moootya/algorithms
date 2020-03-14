#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void merge(int arr[], int l, int m, int r)
{

	int n_L = m - l + 1;

	int n_R = r - m;

	int L[n_L], R[n_R];

	for (int i = 0; i < n_L; i++)
	{
		L[i] = arr[l+1]; // Копирование массива
	}
	for (int j = 0; j < n_R; j++)
	{
		R[j] = arr[m + 1 + j];
	}

	int i=0, j=0, k=l;
	
	while (i < n_L && j < n_R)
	{
		if (L[i] <= R[i])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n_L)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

	while (j < n_R)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void merge_sort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r-1) / 2;

		merge_sort(arr, l, m);
		merge_sort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

void print_arr(int A[], int size_arr)
{
	for (int i = 0; i < size_arr; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}	

int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	print_arr(arr, arr_size);

	merge_sort(arr, 0, arr_size);

	printf("\nSorted array is \n");

	print_arr(arr, arr_size);

	return 0;
		
}
