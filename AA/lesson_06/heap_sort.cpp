#include <iostream>


void max_heapify(int arr[], int heap_size, int i)
    /*
        arr -  массив
        heap_size - размер пирамиды
        i - индекс родителя
        Рекуррентно делает корректировку, подводя массив под свойство неубывающей пирамиды
    */
{
    using namespace std;

    // Инициализация потенциального родительского элемента
    int largest = i;

    // Получение левого и правого дочерних элементов
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;

    // Проверка, не больше ли левый дочерний родительского жлемента
    if (left < heap_size and arr[i] < arr[left])
    {
        largest = left;
    };

    // Проверка, не больше ли правый дочерний потенциального родительского элемента
    if (right < heap_size and arr[largest] < arr[right])
    {
        largest = right;
    };

    // Если родитель не равен i, то рекурсивно проверить правильность дочерних элементов для нового родителя
    if (largest != i)
    {
        // Обмен занчений между двумя элементами
        swap(arr[i], arr[largest]);

        // Рекурсивно проверить дочерние элементы для нового родительского элемента
        max_heapify(arr, heap_size, largest);
    };
}


void build_heap(int arr[], int heap_size)
// Непосрдственное формирование пирамиды из массива
{
    using namespace std;

    // Формирование невозрастающей пирамиды
    for (int i = heap_size / 2 - 1; i >= 0; i--)
    {
        max_heapify(arr, heap_size, i);
    };
}


void heap_sort(int arr[], int heap_size)
// Непосредственная сортировка
{
    using namespace std;

    // Сформировать пирамидальный массив
    build_heap(arr, heap_size);

    for (int i = heap_size - 1; i >= 0; i--)
    {
        // Обменять крайний левый элемент и последний
        swap(arr[i], arr[0]);

        // Провести корректировку с новыми корнем пирамиды и убрать последний элемент из учета
        max_heapify(arr, i, 0);
    };
}


/* Вспомогательная функция для вывода на экран массива размера n*/
void print_array(int arr[], int n)
{
    using namespace std;

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    };

    cout << "\n";
}


int main(void)
{
    using namespace std;

    // Инициализация целочисленного массива
    int arr[] = {12, 11, 13, 5, 6, 7};

    // Определение длины массива, задействованного в пирамиде
    int heap_size = sizeof(arr) / sizeof(arr[0]);

    // Непосредственная сортировка
    heap_sort(arr, heap_size);

    // Вывод отсортированного массива
    print_array(arr, heap_size);

    return 0;
}