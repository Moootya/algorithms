#include <iostream>
#include <climits>  // Информация о максимальных и минимальных значениях системы

// Объявление прототипов функций для вызова в main
int max_two(int, int);
int max_three(int, int, int);
int find_max_crossing_subarray(int [], int, int, int);
int find_max_subarray(int [], int, int);


int main(void)
{
    using namespace std;

    int arr[] = {2, 3, 4, 5, 7}; // Заполнение массива
    int len_arr = sizeof(arr) / sizeof(arr[0]); // Размерность массива
    int max_sum = find_max_subarray(arr, 0, len_arr-1);

    cout << "Max sum: " << max_sum << endl;

    return 0;
}


int find_max_subarray(int arr[], int left, int right)
{
    if (left == right)
    {
        return arr[left];
    }
    else
    {
        int mid = (left + right) / 2;

        int left_sum = find_max_subarray(arr, left, mid);
        int right_sum = find_max_subarray(arr, mid+1, right);
        int cross_sum = find_max_crossing_subarray(arr, left, mid, right);

        return max_three(left_sum, right_sum, cross_sum);
    }

}


int find_max_crossing_subarray(int arr[], int left, int mid, int right)
{
    int left_sum = INT_MIN;
    int sum_ = 0;

    for (int i = mid; i >= left; i--)
    {
        sum_ += arr[i];

        if (sum_ > left_sum)
        {
            left_sum = sum_;
        }
    }

    sum_ = 0;
    int right_sum = INT_MIN;

    for (int j = mid+1; j <= right; j++)
    {
        sum_ += arr[j];

        if (sum_ > right_sum)
        {
            right_sum = sum_;
        }
    }

    return left_sum + right_sum;
}


// find max of 2 int
int max_two(int a, int b)
{
    // Тернарный оператор ? :
    // Сначала идет условие (a > b)
    // Если оно true, то выполнится конструкция до ":"
    // Иначе, конструкция после ":"
    return (a > b)? a : b;
}


// find max of 3 int
int max_three(int a, int b, int c)
{
    return max_two(max_two(a, b), c);
}