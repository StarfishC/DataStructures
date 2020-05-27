"""
@File:    队列.py
@Author:  csh
@Date:    2020/05/27
"""


# ************************** 队列的顺序存储 *********************************//
class ArrQueue(object):
    """顺序队列
    """
    def __init__(self):
        """初始化一个队列
        """
        self.__queue = list()

    def isEmpty(self):
        """判断队列是否为空

        :return bool
        """
        return self.__queue == []

    def enQueue(self, item):
        """入队

        :param item 元素
        """
        self.__queue.append(item)

    def deQueue(self, item):
        """出队

        :return item
        """
        return self.__queue.pop(0)

    def size(self):
        """队列的大小

        :return int
        """
        return len(self.__queue)

    def peek(self):
        """获取队首元素

        :return item
        """
        item = self.__queue[0]
        return item

    def clear(self):
        """清空队列
        """
        self.__queue = []

# ***************************************************************************//

# ************************** 队列的链式存储 *********************************//
class Link(object):
    """队列节点对象
    """
    def __init__(self, data):
        self.__data = data
        self.__next = None

    @property
    def data(self):
        return self.__data

    @data.setter
    def data(self, newData):
        self.__data = data

    @property
    def next(self):
        return self.__next

    @next.setter
    def next(self, newNext):
        self.__next = newNext


class LinkQueue(object):
    """队列的链式存储"""
    def __init__(self):
        """初始化一个队列"""
        self.__front = None
        self.__rear = None
        self.__size = 0

    def isEmpty(self):
        """判断队列是否为空
        
        :return bool
        """
        return self.__front == None

    def enQueue(self, item):
        """入队

        :param item 元素值
        """
        tmp = Link(item)
        if self.__size == 0:
            self.__front = tmp
            self.__rear = tmp
        else:
            self.__rear.next = tmp
            self.__rear = tmp
        self.__size += 1

    def deQueue(self):
        """出队

        :return item 元素值
        """
        if self.isEmpty():
            print("队列为空，不能出栈")
            return None
        else:
            tmp = self.__front.data
            if self.__front == self.__rear:
                self.__front = None
                self.__rear = None
                self.__size -= 1
            else:
                self.__front = self.__front.next
                self.__size -= 1
            return tmp

    def peek(self):
        """获取队首元素

        :return item 元素值
        """
        if self.isEmpty():
            print("队列为空，栈顶无元素")
            return None
        else:
            return self.__front.data

    def clear(self):
        """清空队列"""
        self.__front = None
        self.__rear = None
        self.__size = 0

# ***************************************************************************//
