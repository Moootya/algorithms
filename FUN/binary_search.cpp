#include <iostream>

// Бинарный поиск. Если значения не существует, то вернет -1
// В противном случае первое вхождение
int binary_search(int arr[], int left_index, int right_index, int search_element)
{
    // Если правый индекс больше или равен левому
    // Значит есть где искать
    if (right_index >= left_index)
    {
        // Получение середины массива
        int mid = left_index + (right_index - left_index) / 2;

        // Если мы попали в элемент с первого раза
        if (arr[mid] == search_element)
        {
            return mid;
        }

        // Если искомый элемент меньше, то продолжить искать в левом подмассиве
        if (arr[mid] > search_element)
        {
            return binary_search(arr, left_index, mid - 1, search_element);
        }

        // Если искомый элемент больше центрольного, то искать его в правом подмассиве
        return binary_search(arr, mid + 1, right_index, search_element);

    }

    return -1;
}


int main(void)
{
    using namespace std;

    int arr[] = { 2, 3, 4, 10, 40, 99 };
    int x = 919;

    // Размер массива
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binary_search(arr, 0, n - 1, x);

    (result == -1) ? cout << "Element is not present in array" << endl
                   : cout << "Element is present at index " << result << endl;
    return 0;
}



























//