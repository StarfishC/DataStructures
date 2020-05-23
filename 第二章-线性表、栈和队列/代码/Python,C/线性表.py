"""
@File:    线性表.py
@Author:  csh
@Date:    2020/05/21
"""


# 线性表的顺序存储可以用列表进行


# 线性表的链式存储
class Node(object):
    """节点"""
    def __init__(self, value):
        """初始化一个节点

        :param value 节点元素
        """
        self.__data = value
        self.__next = None

    def setData(self, newValue):
        """设置当前节点元素

        :param newValue 节点元素
        """
        self.__data = newValue

    def getData(self):
        """获取当前节点的元素值

        :return data 节点元素
        """
        return self.__data

    def setNext(self, nextNode):
        """设置下一个节点对象

        :param nextNode Node对象
        """
        self.__next = nextNode

    def getNext(self):
        """获取当前节点的下一个节点对象

        :return Node对象
        """
        return self.__next


class UnOrderedList(object):
    """无序链表"""
    def __init__(self):
        """初始化一个头尾节点"""
        self.__head = None

    def setPos(self, p):
        """返回第p个节点对象

        :return Node对象
        """
        count = 1;
        if p <= 0:
            return None
        temp = self.__head
        while count < p and temp != None:
            count += 1
            temp = temp.getNext()
        return temp

    def isEmpty(self):
        """判断链表是否为空

        return bool
        """
        return self.__head == None

    def length(self):
        """链表的长度

        :return int
        """
        temp = self.__head
        count = 0
        while temp != None:
            count += 1
            temp = temp.getNext()
        return count

    def append(self, value):
        """添加一个元素

        :param value 节点元素
        """
        temp = Node(value)
        temp.setNext(self.__head)
        self.__head = temp

    def insert(self, num, item):
        """第num个位置插入节点元素

        :param num int
        :param item Node对象
        """
        if num <= 0 or num > self.length()+1:
            print("Insertion point is illegal")
            return
        previous = self.setPos(num-1)
        temp = Node(item)
        if previous == None:
            # 此时num-1=0，即插入到头节点
            temp.setNext(self.__head)
            self.__head = temp
        else:
            current = previous.getNext()
            temp.setNext(current)
            previous.setNext(temp)

    def remove(self, p):
        """移除位置为p的元素

        :param p int
        """
        if p <= 0 or p > self.length():
            print("Removal point is illegal")
            return
        if p == 1:
            self.__head = self.__head.getNext()
        else:
            previous = self.setPos(p-1)
            current = previous.getNext()
            previous.setNext(current.getNext())

    def getPos(self, value):
        """查找value元素是否存在

        :param value 元素值
        :return bool
        """
        current = self.__head
        found = False
        while current != None and not found:
            if current.getData() == value:
                found = True
            else:
                current = current.getNext()
        return found

    def getValue(self, p):
        """获取位置为p的元素值

        :param p int
        :return data 元素值
        """
        current = self.setPos(p)
        if current == None:
            print("Location is illegal")
        return current.getData()

    def showAll(self):
        """显示所有元素值
        """
        tmp = self.__head
        while tmp != None:
            print(tmp.getData())
            tmp = tmp.getNext()


class OrderedList(object):
    """有序链表"""
    def __init__(self):
        """初始化头节点"""
        self.__head = None

    def isEmpty(self):
        """判断链表是否为空

        :return bool
        """
        return self.__head == None

    def length(self):
        """链表的长度
        
        :return int
        """
        count = 0
        temp = self.__head
        while temp != None:
            count += 1
            temp = temp.getNext()
        return count

    def append(self, value):
        """添加一个元素

        :param value 元素值
        """
        current = self.__head
        previous = None
        stop = False
        while current != None and not stop:
            if current.getData() > value:
                stop = True
            else:
                previous = current
                current = current.getNext()
        temp = Node(value)
        if previous == None:
            # 当前没有元素
            temp.setNext(self.__head)
            self.__head = temp
        else:
            temp.setNext(current)
            previous.setNext(temp)

    def remove(self, item):
        """移除原始值为item的节点

        :param item 要移除的节点的元素值
        """
        current = self.__head
        previous = None
        found = False
        while not found:
            if current.getData() == item:
                found = True
            else:
                previous = current
                current = current.getNext()
        if previous == None:
            self.__head = current.getNext()
        else:
            previous.setNext(current.getNext())

    def find(self, value):
        """查找元素值是否存在

        :param value 节点元素值
        :return bool
        """
        current = self.__head
        found = False
        stop = False
        while current != None and not found and not stop:
            if current.getData() == value:
                found = True
            else:
                if current.getData() > value:
                    stop = True
                else:
                    current = current.getNext()
        return found

    def showAll(self):
        current = self.__head
        while current != None:
            print(current.getData(), end=" ")
            current = current.getNext()
        print()


