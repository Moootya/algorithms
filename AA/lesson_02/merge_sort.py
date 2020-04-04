import math

# https://docs.google.com/presentation/d/1A8a3-2WkfFQarcu_52oLs706Z5XVDVX3FP9Jm9hqjxk/edit?usp=sharing
# arr[l..r] подмассив для сортировки
# l and r левые и правые индексы массива соответственно
# Массив будет разбиваться, пока его элементы не будут равны одному элементу или пустому множеству


def merge_sort(arr, l, r):
    # Если левый индекс меньше правого, значит есть что фильтровать
    if l < r:
        # найти центральный индекс подмассива
        m = (l + r) // 2

        # Сортировка левой половины массива
        merge_sort(arr, l, m)

        # Сортировка правой половины массива
        merge_sort(arr, m + 1, r)

        # Объединение двух половин массива
        merge(arr, l, m, r)


def merge(arr, l, m, r):
    # Длина левой половины массива
    # [2,4,5,7,1,2,3,6]
    # Длина левого подмассива 4
    n_l = m - l + 1

    # Длина правой половины массива
    # Длина правого подмассива 4
    n_R = r - m

    # Создание новых пустых массивов для левой и правой половины L[0..n_l] and R[0..n_R]
    L = [0] * (n_l + 1)  # +1 для ограничителя. [0,0,0,0, inf]
    R = [0] * (n_R + 1)  # +1 для ограничителя. [0,0,0,0, inf]

    # Копирование левой половины в L[0..n_l-1]
    for i in range(0, n_l):
        L[i] = arr[l + i]

    # Копирование правой половины в R[0..n_R-1]
    for j in range(0, n_R):
        R[j] = arr[m + 1 + j]

    # последние значения левого и правого массивов будут помечены сигналом в виде бесконечности
    L[n_l] = math.inf  # [2,4,5,7, inf]
    R[n_R] = math.inf  # [1,2,3,6, inf]

    # Перебор левого и правого массива
    # В результат добавить меньший элемент массива
    i = 0
    j = 0

    for k in range(l, r + 1):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1

A = [2, 3, 5, 1, 5, 9, 7, 2, 8]

merge_sort(A, 0, len(A) - 1)

print(A)    # output: [1, 2, 2, 3, 5, 5, 7, 8, 9]