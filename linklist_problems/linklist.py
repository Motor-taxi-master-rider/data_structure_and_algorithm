# -*- coding: utf-8 -*-


class Linklist(object):
    def __init__(self, value, next):
        self.value = value
        self.next = next

    def traversal(self):
        print(self.value)
        if self.next:
            self.next.traversal()


class SampleLinklist(object):
    def __init__(self):
        self.normal_linklist = Linklist(
            1, Linklist(2, Linklist(3, Linklist(4, Linklist(5, Linklist(6, Linklist(7, None)))))))
