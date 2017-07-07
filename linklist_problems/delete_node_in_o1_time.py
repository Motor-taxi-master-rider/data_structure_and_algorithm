# -*- coding: utf-8 -*-

# 题目描述：给定链表的头指针和一个节点指针，在O(1)时间删除该节点。[Google面试题]
#
# 分析：本题与《编程之美》上的「从无头单链表中删除节点」类似。主要思想都是「狸猫换太子」，
# 即用下一个节点数据覆盖要删除的节点，然后删除下一个节点。但是如果节点是尾节点时，该方法就行不通了。

from linklist import SampleLinklist


def delete_specified_node(node):
    assert(node != None)
    if node.next != None:
        storeNode = node.next
        node.value = node.next.value
        node.next = node.next.next


def main():
    link = SampleLinklist().normal_linklist
    delete_specified_node(link.next.next.next)
    link.traversal()


if __name__ == '__main__':
    main()
