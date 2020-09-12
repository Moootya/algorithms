import random


class Node:

    def __init__(self, data = None):
        self.left = None
        self.right = None
        self.data = data

    def print_tree(self):
        if self.left is not None:
            self.left.print_tree()
        print(self.data, end=' ')
        if self.right is not None:
            self.right.print_tree()

    def search(self, key):
        """
        Поиск узла по ключу key
        :param key:
        :return:
        """

        # Если нет данных
        if not self.data or key == self.data:
            return self

        elif key < self.data:
            return self.left.search(key)

        return self.right.search(key)

    def insert(self, data) -> None:
        """
        Вставка узла в бинарное дерево поиска
        :param data: Данные для вставки
        :return: None
        """
        if self.data is not None:

            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)

            elif data >= self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)

        else:
            self.data = data

    def node_min(self):
        if not self.left and self.data:
            return self
        return self.left.node_min()

    def node_max(self):
        if not self.right and self.data:
            return self
        return self.right.node_right()


nums = [random.randrange(0, 100000) for i in range(random.randrange(0, 20))]

root = Node()
for num in nums:
    root.insert(num)

root.print_tree()













