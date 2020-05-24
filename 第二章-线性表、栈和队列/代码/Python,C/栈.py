"""
@File:    栈.py
@Author:  csh
@Date:    2020/05/24
"""


#************************* 栈的顺序存储  *************************#
class ArrStack(object):
    """栈的顺序存储"""
    def __init__(self):
        """创建一个栈"""
        self.__stack = list()

    def isEmpty(self):
        """判断是否栈空

        :return bool
        """
        return self.__stack == []
    
    def push(self, item):
        """元素入栈

        :param item 元素
        """
        self.__stack.append(item)

    def pop(self):
        """元素出栈
        
        :return item 元素
        """
        return self.__stack.pop()

    def size(self):
        """栈的大小

        :return int
        """
        return len(self.__stack)

    def peek(self):
        """取出栈顶元素

        :return item 元素
        """
        return self.__stack[-1]

    def clear(self):
        """清空栈所有元素
        """
        self.__stack = list()

#*****************************************************************#


#************************* 栈的顺序存储  *************************#
class Link(object):
    """节点类"""
    def __init__(self, data):
        self.__data = data
        self.__next = None
    
    @property
    def next(self):
        return self.__next

    @next.setter
    def next(self, newNext):
        self.__next = newNext

    @property
    def data(self):
        return self.__data

    @data.setter
    def data(self, data):
        self.__data = newData;


class LinkStack(object):
    """链式栈
    """
    def __init__(self):
        """初始化一个栈
        """
        self.__top = None
        self.__num = 0

    def isEmpty(self):
        """判断是否栈空

        :return bool
        """
        return self.__num == 0

    def size(self):
        """栈的大小

        :return int
        """
        return self.__num

    def push(self, item):
        """入栈

        :param item Link类
        """
        tmp = Link(item)
        tmp.next = self.__top
        self.__top = tmp
        self.__num += 1

    def pop(self):
        """元素出栈

        :return item 元素值
        """
        if self.isEmpty():
            print("栈空，不能出栈")
            return None
        else:
            item = self.__top.data
            self.__top = self.__top.next
            self.__num -= 1
            return item

    def peek(self):
        """返回栈顶元素

        :return item 元素值
        """
        if self.isEmpty():
            print("栈空，栈顶无元素")
            return None
        else:
            return self.__top.data

    def clear(self):
        """清空栈所有元素
        """
        self.__top = None
        self.__num = 0
#*****************************************************************#
