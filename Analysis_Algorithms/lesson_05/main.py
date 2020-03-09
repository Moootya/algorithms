from random import randrange


def hire_assistant(n):
    """
    :param n:
    :return:
    """
    best = 0  # Фикция

    for assistant in range(1, n+1):
        if assistant > best:
            best = assistant

    return best


print(randrange(0, 1+1))