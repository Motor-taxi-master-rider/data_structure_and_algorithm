# -*- coding: utf-8 -*-
# 题目描述：输入一个单向链表，输出该链表中倒数第k个节点，链表的倒数第0个节点为链表的尾指针。

# 分析：设置两个指针 p1、p2，首先 p1 和 p2 都指向 head，然后 p2 向前走 k 步，这样 p1 和
# p2 之间就间隔 k 个节点，最后 p1 和 p2 同时向前移动，直至 p2 走到链表末尾。

from linklist import SampleLinklist


def find_last_nth(header, n):
    if not header or n < 0:
        return None
    # 将fast和slow指针设至链表起点
    fast = slow = header
    # 将fast走n个节点
    while fast.next and n > 0:
        fast = fast.next
        n -= 1
    # n大于链表长度的情况
    if n > 0:
        return None
    while fast.next:
        fast = fast.next
        slow = slow.next
    return slow


def main():
    link = SampleLinklist().normal_linklist
    node = find_last_nth(link.next, 9)
    node.traversal()


if __name__ == '__main__':
    main()
