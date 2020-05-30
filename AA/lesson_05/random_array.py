import random


def randomize_in_place(a: list):
    """
    :param a: Список для сортировки
    :return: Сортирует массив на "месте"
    """

    n = len(a)

    for i in range(n):
        a[i], a[random.randrange(i, n)] = a[random.randrange(i, n)], a[i]





if __name__ == '__main__':
    a = [1, 2, 3, 4]
    print(a)

    randomize_in_place(a)

    print(a)











#