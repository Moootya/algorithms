#include <iostream>

// Декларирование структуры, которая может быть заполнена данными
// S - это новый тип
struct S_t {
    int first; // Поле структуры
    int second;
};

// Функция возвращает новую структуру
S_t blabla(int b)
{
    // Объявление новой структуры с именем result
    S_t result; // Локальный экземпляр структуры

    result.first = b*b;
    result.second = b*b*b;

    return result;
}

int main(void)
{
    using namespace std;

    int b = 4;

    // Получение новой структуры из функции
    S_t s = blabla(b);


    cout << "Struct first: " << s.first << endl;
    cout << "Struct second: " << s.second << endl;

    return 0;
}


