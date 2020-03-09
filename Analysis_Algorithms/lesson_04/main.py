from pprint import pprint


def square_matrix(a, b):
    """
    # Алгоритм Штрассена; o(n**3)
    :param a: Первая матрица
    :param b: Вторая матрица
    :return: Произведение матриц
    """
    n = len(a)
    c = [[0] * n for _ in range(n)]  # Резервирование необходимого места для выходной матрицы

    for i in range(n):  # Проход по индексам строк

        for j in range(n):  # Проход по индексам столбцом

            for k in range(n):
                c[i][j] = c[i][j] + a[i][k] * b[k][j]
    return c


def square_matrix_rec(a, b):
    """
    :param a:
    :param b:
    :return:
    """
    n = len(a)
    print(n)
    c = [[0] * n for _ in range(n)]

    if n == 1:
        c[0][0] = a[0][0] * b[0][0]
        return c

    else:
        c[0][0] = square_matrix_rec([a[0:(n//2)][(n//2):0]], [b[0(n//2)][(n//2)0]]) + square_matrix_rec([a[0][1]], [b[1][0]])

        c[0][1] = square_matrix_rec([a[0][0]], [b[0][1]]) + square_matrix_rec([a[0][1]], [b[1][1]])

        c[1][0] = square_matrix_rec([a[1][0]], [b[0][0]]) + square_matrix_rec([a[1][1]], [b[1][0]])

        c[1][1] = square_matrix_rec([a[1][0]], [b[0][1]]) + square_matrix_rec([a[1][1]], [b[1][1]])











if __name__ == '__main__':

    # Test 1
    m1 = [
        [2, 2],
        [3, 3]
    ]
    m2 = [
        [2, 2],
        [3, 3]
    ]
    assert square_matrix(m1, m2) == [[10, 10], [15, 15]]

    # Test 2
    m1 = [
        [2, 2],
        [3, 3]
    ]
    m2 = [
        [2, 2],
        [3, 3]
    ]
    # assert square_matrix_rec(m1, m2) == [[10, 10], [15, 15]]
    print(square_matrix_rec(m1, m2))
