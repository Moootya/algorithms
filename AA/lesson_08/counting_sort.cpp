#include <iostream>
#include <vector>


void print(int a[], int sz) {
	for (int i = 0; i < sz;  i++ )
    {
        std::cout << a[i] << " ";
    } 
	std::cout << std::endl;
}


/*
    arr[] - array with int
    size - array - size
*/
void counting_sort(int arr[], int size)
{
    int idx = 0;

    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < size; i++)
    {
        min = (arr[i] < min) ? arr[i] : min;
        max = (arr[i] > max) ? arr[i] : max;
    }

    const int k = max - min + 1;

    // Dinamic array
    int *output = new int[k];
    for(int i = 0; i < k; i++)
    {
        output[i] = 0;
    }

    for(int i = 0; i < size; i++)
    {
        output[arr[i] - min]++;
    }

    for(int i = min; i <= max; i++)
    {
        for(int j = 0; j < output[i - min]; j++)
        {
            arr[idx++] = i;
        }
    }
    
    print(arr, size);

    delete [] output;

}



int main(void)
{
    int a[] = {5,9,3,9,10,9,2,4,13,10};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	print(a,sz);
	std::cout << "----------------------\n" ;
	counting_sort(a, sz);

    return 0;
}