#Define a double linked list

class Node(object):
    def __init__(self, data, prev, next):
        self.data= data
        self.prev = prev
        self.next = next

class DoubleList(object):
    head = None
    tail = None

    def append(self, data):
        new_node = Node(data, None, None)

        if self.head is None:
            self.head = self.tail = new_node
        else:
            new_node.prev = self.tail
            new_node.next = None
            self.tail.next = new_node
            self.tail = new_node


    def show(self):
        print("Printing list data")
        curr_node = self.head
        while curr_node is not None:
            print(curr_node.data)
            curr_node = curr_node.next


# The idea is find the middle of the list, this element will be the root
# then recurse on the left part and right part to find the left and right children
def ddlist_to_bst(list):
    head = list.head
    tail = head
    while tail.next is not None:
        tail = tail.next
    return ddlist_rec(head, tail)

def ddlist_rec(head, tail):
    mid = find_mid(head,tail)
    print mid.data

    if mid == head:
        return mid

    mid.prev = ddlist_rec(head, mid.prev)
    mid.next = ddlist_rec(mid.next, tail)

    return mid

def find_mid(head, tail):
    if head == tail:
        return head

    slow = head
    fast = head
    while fast is not None and \
          fast.next is not None and \
          fast.next.next is not None and \
          fast.next.next.data <= tail.data:
        slow = slow.next
        fast = fast.next
        if fast == tail:
            break
        fast = fast.next
    return slow



def get_sorted_ddlist(n):
    d = DoubleList()
    for i in range(n):
        d.append(i)
    return d


def printTree(l):
    if l is None :
        return
    print l.data
    printTree(l.prev)
    printTree(l.next)


l = get_sorted_ddlist(20)
l.show()

print "Tree is (inorden)"

t = ddlist_to_bst(l)
#printTree(t)