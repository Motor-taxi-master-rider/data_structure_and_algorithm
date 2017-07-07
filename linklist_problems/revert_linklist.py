# -*- coding: utf-8 -*-
# 题目描述：输入一个单向链表，输出逆序反转后的链表
#
# 分析：链表的转置是一个很常见、很基础的数据结构题了，非递归的算法很简单，用三个临时指针 pre、head、nex
# t 在链表上循环一遍即可。递归算法也是比较简单的，但是如果思路不清晰估计一时半会儿也写不出来吧。

from linklist import SampleLinklist


def revert_linklist(node):
    if not node or not node.next:
        # 返回链表尾节点为，既反转后链表头结点
        return node
    # 暂存头结点
    header = revert_linklist(node.next)
    node.next.next = node
    node.next = None
    return header


def main():
    link = SampleLinklist().normal_linklist
    header = revert_linklist(link)
    header.traversal()


if __name__ == '__main__':
    main()
