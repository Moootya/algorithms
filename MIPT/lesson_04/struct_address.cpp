#include <iostream>

// Объявление новой структуры
struct StructAddress
{
    int a;
    int b;
};

// Функция для изменения структуры
// На вход получает адрес структуры
void modify_struct(StructAddress *p)
{
    // Равносильное разыменовывание адреса структуры и получение самой структуры для изменения данных
    p->a += 1;
    (*p).b += 10;
}

int main(void)
{
    using namespace std;

    // Объявление новой структуры
    StructAddress struct1;

    // Считывание данных из ввода в новую структуру
    cin >> struct1.a >> struct1.b;

    // Создание еще одной структуры
    StructAddress struct2;

    // Присваение данных структуры новой структуре
    struct2 = struct1;

    // Вызов функции, в которую передается адрес структруы для изменения
    modify_struct(&struct1);

    cout << "Struct 1: " << struct1.a << " " << struct1.b << endl;
    cout << "Struct 2: " << struct2.a << " " << struct2.b << endl;

    return 0;
}