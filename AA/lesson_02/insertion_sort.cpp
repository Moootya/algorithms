#include <iostream> //
#include <ctime> // 
#include <iomanip> // 

using namespace std;

void insertion_sort(int *, int); // прототип

int main(int argc, char* argv[]) 
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива: ";

	int size_array;
	cin >> size_array;
	
	int *sorted_array = new int [size_array]; // одномерный динамический массив
	

	for (int i=0; i < size_array; i++)
	{
		sorted_array[i] = rand() % 100; // заполнение массива случайными числами
		cout << setw(2) << sorted_array[i] << "  "; // Вывод массива на экран
	}	
	cout << "n";

	insertion_sort(sorted_array, size_array);  // Функция сортировки

	for (int i=0; i < size_array; i++)
	{
		cout << setw(2) << sorted_array[i] << "  "; // Вывод отсортированного массива 
	}
	cout << "n";

	delete [] sorted_array; // Освобождение памяти

	return 0;
}

void insertion_sort(int *array_ptr, int len)
{
	int temp, // 
	    item; //
	
	for (int i=1; i < len; i++)
	{
		temp = array_ptr[i]; // Текущий элемент массива
		item = i - 1;  // Предыдущий элемент массива

		while (item >= 0 && array_ptr[item] > temp)
		{
			array_ptr[item + 1] = array_ptr[item];
			array_ptr[item] = temp;
			item--;
			
		}	
	}
       	
}	

