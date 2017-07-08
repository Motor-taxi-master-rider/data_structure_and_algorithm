# -*- coding: utf-8 -*-
# 题目描述：输入一个单向链表，判断链表是否有环。如果链表存在环，如何找到环的入口点？
#
# 分析：通过两个指针，分别从链表的头节点出发，一个每次向后移动一步，
# 另一个移动两步，两个指针移动速度不一样，如果存在环，那么两个指针一
# 定会在环里相遇。
# 按照 p2 每次两步，p1 每次一步的方式走，发现 p2 和 p1 重合，确定了单向链表
# 有环路了。接下来，让p2回到链表的头部，重新走，每次步长不是走2了，而是走1，那
# 么当 p1 和 p2 再次相遇的时候，就是环路的入口了。为什么？：假定起点到环入口点
# 的距离为 a，p1 和 p2 的相交点M与环入口点的距离为b，环路的周长为L，当 p1 和
# p2 第一次相遇的时候，假定 p1 走了 n 步。那么有：p1走的路径： a+b ＝ n；p2走
# 的路径： a+b+k*L = 2*n； p2 比 p1 多走了k圈环路，总路程是p1的2倍根据上述公式
# 可以得到 k*L=a+b=n显然，如果从相遇点M开始，p1 再走 n 步的话，还可以再回到相遇
# 点，同时p2从头开始走的话，经过n步，也会达到相遇点M。显然在这个步骤当中 p1 和 p2
# 只有前 a 步走的路径不同，所以当 p1 和 p2 再次重合的时候，必然是在链表的环路入口点上。

from linklist import SampleLinklist


def is_loop(header):
    if not header:
        return False
    fast = slow = header
    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next
        # 找到两步长交汇点
        if fast == slow:
            break
    if fast != slow:
        return None

    # 将fast发配回起点
    fast = header
    #当两节点再次相遇的时候则为环入口
    while not fast == slow:
        fast = fast.next
        slow = slow.next
    return fast

def main():
    link = SampleLinklist().loop_linklist
    node = is_loop(link)
    print(node.value)


if __name__ == '__main__':
    main()
