#include <iostream>


// На вход принимает класс вектора из основных библиотек
int partition(int arr[], int left, int right)
{
    // Установка опорного элемента
    int pivot = arr[right];

    // Установка начального значения для подмассима с элементами, меньшими опрного
    int i = left - 1;

    // Объявление цикла с проходом всех элементов, пока j меньше последнего элемента
    for (int j = left; j < right - 1; ++j)
    {
        // Если элемент из общего массива равен или меньше опрному, то заменить его с элементов на месте i
        if (arr[j] <= pivot)
        {
            // Прибаление индекса для значений подмассива, в котором все элементы меньше опорного
            i++;

            // Обмен двух элементов массива
            std::swap(arr[i], arr[j]);
        };
    };
    // Замена опорного элемента на элемент, стоящий между двумя подмассивами
    std::swap(arr[i+1], arr[right]);

    // Получение индекса опорного элемента
    return i + 1;
}


void quick_sort(int arr[], int left, int right)
{
    // Если есть элементы для сортировки
    if (left < right)
    {
        // Получение индекса опорного элемента
        int index_pivot = partition(arr, left, right);

        quick_sort(arr, left, index_pivot-1);

        quick_sort(arr, index_pivot, right);
    };
}


void print_array(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    };
    std::cout << "\n";
}


int main(void)
{
    using namespace std;

    const int len_arr = 8;

    // Заполнение массива целочисленными значениями
    int arr[] = {2, 8, 7, 1, 3, 5, 6, 4};

    // Печать массива до сортировки
    print_array(arr, len_arr);

//    partition(arr, 0, len_arr - 1);

    quick_sort(arr, 0, len_arr - 1);

    // Печать после сортировки
    print_array(arr, len_arr);

    return 0;
}