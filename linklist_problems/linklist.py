# -*- coding: utf-8 -*-


class Linklist(object):
    def __init__(self, value, next):
        self.value = value
        self.next = next

    def traversal(self):
        """
        遍历该节点开始的链表
        :return:
        """
        print(self.value)
        if self.next:
            self.next.traversal()

    def __bool__(self):
        """
        用于之后的if Linklist判断
        :return:
        """
        return True

    def __len__(self):
        """
        :return: 无环链表的长度
        """
        count = 0
        node = self
        while node is not None:
            node = node.next
            count += 1
        return count


class SampleLinklist(object):
    def __init__(self):
        # 创建一个值为0-19的链表数组
        nodelist = [Linklist(i, None) for i in range(20)]
        # 0-6为无环单链表；7-11为有环单链表（入口为8）；
        # 12-14交于无环单链表(入口为5)；15-19交于有环链表（入口为9）；
        for key, value in enumerate(nodelist):
            if key != 6 and key != 11 and key != 14 and key != 19:
                value.next = nodelist[key + 1]
            elif key == 11:
                value.next = nodelist[8]
            elif key == 14:
                value.next = nodelist[5]
            elif key == 19:
                value.next = nodelist[9]

        #无环单链表
        self.normal_linklist = nodelist[0]
        #有环单链表（入口为8）
        self.loop_linklist = nodelist[7]
        #与normal_linklist交于5
        self.intersect_normal_linklist = (nodelist[0], nodelist[12])
        # 与nloop_linklist交于9
        self.intersect_loop_linklist = (nodelist[7], nodelist[15])
