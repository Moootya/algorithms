# Поиск максимального подмассива
import math


def find_max_subarray(arr, left, right):
    """
    :param arr: Массив в котором будет выполнен поиск
    :param left: С какого индекса будет выпеолнен поиск
    :param right: В каком месте нужно будет закончить поиск
    :return:
    """
    # Базовый случай, когда только один элемент в массиве
    if left == right:
        return left, right, arr[left]

    else:
        # Получение среднего значения массива
        mid = (left + right) // 2

        # Разбить левый подмассив
        left_low, left_high, left_sum = find_max_subarray(arr, left, mid)

        # Разбить правый подмассив
        right_low, right_high, right_sum = find_max_subarray(arr, mid+1, right)

        # Начало комбинирования
        # Определение максимального подмассива, который пересекает среднюю точку
        # Этот этап не является Рекурсивной задачей.
        cross_low, cross_high, cross_sum = find_max_crossing_subarray(arr, left, mid, right)

        # Если сумма левого подмассива больше суммы правого и одновременно больше среднего
        if left_sum >= right_sum and left_sum >= cross_sum:
            return left_low, left_high, left_sum

        # Если сумма правого больше суммы левого и сумма правого больше среднего
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return right_low, right_high, right_sum

        # Если ни одно условие не выполняется, то наибольшим является средний
        else:
            return cross_low, cross_high, cross_sum


def find_max_crossing_subarray(arr, left, mid, right):
    """
    :param arr: Исходный массив
    :param left: Левый индекс
    :param mid: Средний индекс
    :param right: Правый индекс
    :return: Кортеж с индексами, определяющие пересекающий среднюю точку максимальный подмассив. и их сумму
    :return: Скорость работы - тэтта от (n). Так как можно подсчитать точное количество итераций.
    """

    max_left, max_right = 0, 0

    # Начало поиска максимального подмассива в левой половине
    # Максимальная сумма в виде бесконечности
    left_sum, _sum = -math.inf, 0

    # Обойти в обратном порядке массив
    for i in range(mid, left-1, -1):
        # Складывать справо налево элементы подмассива
        _sum += arr[i]

        # Если сумма подмассивов больше итоговой суммы левого подмассива
        if _sum > left_sum:
            # Заменить старую сумму новой суммой
            left_sum = _sum
            # Запомнить левый индекс максимального подмассива
            max_left = i

    # Начало поиска максимального подмассива в правой половине
    right_sum, _sum = -math.inf, 0

    for j in range(mid+1, right+1):
        _sum += arr[j]
        if _sum > right_sum:
            right_sum = _sum
            max_right = j

    # Вернуть левый индекс, правый индекс и сумму подмассивов
    return max_left, max_right, left_sum + right_sum


if __name__ == '__main__':
    arr = [-1, -2, -3, 1, 1, -9]
    result = find_max_subarray(arr, 0, len(arr)-1)
    print(result)
