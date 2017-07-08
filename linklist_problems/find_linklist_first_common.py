# -*- coding: utf-8 -*-
# 题目描述：如果两个单链表相交，怎么求出他们相交的第一个节点呢？
#
# 分析：当两链表无环时，则可采用对齐的思想。计算两个链表的长度 L1 , L2，
# 分别用两个指针 p1 , p2 指向两个链表的头，然后将较长链表的 p1（假设为 p1）
# 向后移动L2 - L1个节点，然后再同时向后移动p1 , p2，直到 p1 = p2。
# 相遇的点就是相交的第一个节点。
# 当两链表有环时，如果个环入口相等，则可看成以环入口为尾节点的无环情况。
# 如果不等，则首公共节点为两个入口较近的那个。
#

from linklist import SampleLinklist


def find_intersect_first_common(header1, header2):
    len1 = len(header1)
    len2 = len(header2)
    if len1 > len2:
        for i in range(len1 - len2):
            header1 = header1.next
    else:
        for i in range(len2 - len1):
            header2 = header2.next
    while header1:
        if header1 == header2:
            return header1
        header1 = header1.next
        header2 = header2.next
    return None


def main():
    node = find_intersect_first_common(*SampleLinklist().intersect_normal_linklist)
    node.traversal()


if __name__ == '__main__':
    main()
