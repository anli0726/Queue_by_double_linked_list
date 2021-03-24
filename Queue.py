# implemented by doulbe linked list
# O(1) dequeue/enqueue

class DoubleLinkedNode:
    def __init__(self, item):
        self.item = item
        self.prev = None
        self.next = None

class Queue:
    def __init__(self):
        self._size = 0
        self.head = None
        self.tail = None
    
    def enqueue(self, item): # move tial
        node = DoubleLinkedNode(item)
        if self.tail is None: # no item in the queue
            self.tail = node
            self.head = self.tail
        else: # already have items in the queue
           self.tail.next = node # link the last item to the new node
           node.prev = self.tail # link the new node to the last node
           self.tail = self.tail.next # move the tail pointer to the current last node
        self._size += 1
    
    def dequeue(self):
        if self.head is None: # no item in the queue
            return None
        item = self.head.item # get the return item
        self.head = self.head.next # move the head pointer to the current head
        self.head.prev = None # link the head should not have previous node
        self._size -= 1
        return item 
    
    def size(self):
        return self._size

    def top(self):
        return self.head.item

    def empty(self):
        return self._size == 0
    

if __name__ == "__main__":
    q = arrayQueue()
    print(f"q.empty() = {q.empty()}")
    for i in range(4):
        q.enqueue(i)
    print(f"q.empty() = {q.empty()}")
    print(f"q.size() = {q.size()}")    
    print(f"q.top() = {q.top()}")

    first_item = q.dequeue()
    print(f"first_item = {first_item}")
    print(f"q.empty() = {q.empty()}")
    print(f"q.size() = {q.size()}")    
    print(f"q.top() = {q.top()}")
    