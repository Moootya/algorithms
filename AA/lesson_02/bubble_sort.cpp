#include <iostream>


int main(void)
{
    // Целочисленный массив из
    int arr[7] = {
//      7, 6, 5, 4, 3, 2, 1
        4, 3, 7, 0, 1, 9, 5
//        1, 2, 3, 4, 5, 6, 7
    };


    int length_arr = 7;

    for (int i = 0; i < length_arr - 1; ++i)
    {
        for (int j = 0; j < length_arr - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int b = arr[j]; // Дополнительная переменная
                // Меняем местами два элемента
                arr[j] = arr[j + 1]; // Заполняем текущий элемент следующим, если он меньше
                arr[j + 1] = b;
            }
        }
    }

    for (int i = 0; i < length_arr; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;

}