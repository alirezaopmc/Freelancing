class Node:
    def __init__(self, value):
        self.value = value
        self.prev = None
        self.next = None
    
    def set_next(self, next_node):
        self.next = next_node
    
    def set_prev(self, prev_node):
        self.next = prev_node

class MyStack:
    def __init__(self):
        self.top: Node = None
    
    def push(self, value):
        node = Node(value)

        if self.top:
            node.prev = self.top
            self.top.next = node
            self.top = self.top.next
        else:
            self.top = node
    
    def pop(self):
        if self.top:
            top_value = self.top.value
            self.top = self.top.prev
            return top_value
        else:
            return 'error'


    
ms = MyStack()
n = int(input())

for i in range(n):
    s = input()
    if s == 'pop':
        print(ms.pop())
    else:
        ms.push(int(s.split(' ')[1]))