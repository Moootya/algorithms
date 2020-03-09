
"""
https://www.youtube.com/watch?v=rEPggzaPoUw

Редакционное расстояние между строками (Расстояние Левенштейна)

string1 = 'Колокол', A, len(n)
string2 = 'Молоко', B, len(m)

Допустимые ошибки:
    - Перепутали символы
    - Лишний символ
    - Потеряли нужный символ

Сколько нужно минимальных ошибок для получения sting2 из sting1

Fij - минимальная редакционная правка между срезами строк A[:i], B[:j]
Ответ - Fnm


      |  F(i-1)(j-1), если A[i] == B[j]
Fij = |  1 + min( F(i-1)j, Fi(j-1), F(i-1)(j-1) )
      |  F(0)j == j, F(i)0 = i, F(00) == 0

"""
from pprint import pprint

def levelstein(a, b):
    """
    :param a: Первая строка по вертикали
    :param b: Вторая строка по горизонтали
    :return: Минимальное расстрояние в виде правок между двумя словами
    """

    # Массив для вычисления с крайнимим случаями
    F = [[(i+j) if i*j == 0 else 0 for j in range(len(b) + 1)] for i in range(len(a) + 1)]
    pprint(F)

    for i in range(1, len(a) + 1):
        # print(F)

        for j in range(1, len(b) + 1):
            # print(F)

            if a[i-1] == b[j-1]:
                F[i][j] = F[i-1][j-1]
                # print(F)

            else:
                F[i][j] = 1 + min(F[i-1][j], F[i][j-1], F[i-1][j-1])
                # print(F)
    pprint(F)
    return F[-1][-1]



pprint(levelstein('abcdf', 'abcd'))













#




