# -*- coding: utf-8 -*-
# 题目描述：求链表的中间节点，如果链表的长度为偶数，返回中间两个节点的任意一个，若为奇数，则返回中间节点。
#
# 分析：此题的解决思路和第3题「求链表的倒数第 k 个节点」很相似。可以先求链表的长度，
# 然后计算出中间节点所在链表顺序的位置。但是如果要求只能扫描一遍链表，如何解决呢？
# 最高效的解法和第3题一样，通过两个指针来完成。用两个指针从链表头节点开始，一个指针每次向后移动两步，
# 一个每次移动一步，直到快指针移到到尾节点，那么慢指针即是所求。

from linklist import SampleLinklist


def find_mid(header):
    if not header:
        return None
    # 将fast和slow指针设至链表起点
    fast = slow = header
    while  fast and fast.next:
        #fast速度为slow两倍
        fast=fast.next.next
        slow=slow.next
    return slow


def main():
    link = SampleLinklist().normal_linklist
    node = find_mid(link)
    node.traversal()


if __name__ == '__main__':
    main()
