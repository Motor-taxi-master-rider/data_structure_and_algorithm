# -*- coding: utf-8 -*-
# 题目描述：给出两个链表的头指针，判断其是否相交
#
# 分析：如果有环且两个链表相交，则两个链表都有共同一个环，即环上的任意一个节点都存在于两个链表上。
# 因此，就可以判断一链表上俩指针相遇的那个节点，在不在另一条链表上。

from linklist import SampleLinklist
from whether_linklist_has_loop import is_loop


def is_intersect(header1, header2):
    if not header1 or not header2:
        return False
    if not is_loop(header1) and not is_loop(header2):
        # 两个无环链表的尾节点是否相等决定了它们是否相交
        while header1:
            header1 = header1.next
        while header2:
            header2 = header2.next
        return True if header1 == header2 else False
    elif not is_loop(header1) or not is_loop(header2):
        return False
    else:
        # 两个带环链表的入口必然在它们的环内
        intersect1 = is_loop(header1)
        intersect2 = is_loop(header2)
        node = intersect2.next
        # 如果任意链表环中有另一列表的节点则相交
        while node != intersect2:
            if node == intersect1:
                return True
            node = node.next
        return False


def main():
    node = is_intersect(*SampleLinklist().intersect_loop_linklist)
    print(node)


if __name__ == '__main__':
    main()
