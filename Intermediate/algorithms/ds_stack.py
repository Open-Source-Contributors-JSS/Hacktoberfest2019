class Node():
    def __init__(self,value=None,next=None):
        self.value=value
        self.next=next

class LinkedList():
    def __init__(self):
        self.first=None
        self.last=None
        self.size=0
    def addFirst(self,val):
        node=Node(val)
        if self.size==0:
            self.first=node
            self.last=node
        else:
            self.first=Node(val,self.first)
        self.size+=1
    def removeFirst(self):
        if self.size>1:
            self.first=self.first.next
            self.size-=1
        elif self.size==1:
            self.first=None
            self.last=None
            self.size-=1
        else:
            print("Error: Nothing to Remove")
    def top(self):
        if self.size==0:
            return None
        else: return self.first.value
    def addLast(self,val):
        if self.size>0:
            node=Node(val)
            self.last.next=node
            self.last=node
        else:
            node=Node(val)
            self.first=node
            self.last=node
        self.size+=1
    def removeLast(self):
        if self.size>1:
            check=self.first
            while check!=None:
                if check.next==self.last:
                    self.last=check
                    check.next=None
                    break
                check=check.next
            self.size-=1
        elif self.size==1:
            self.first=None
            self.last=None
            self.size-=1
        else:
            print("Error: Nothing to Remove")
    def indexOf(self,val):
        index=0
        check=self.first
        while check!=None:
            if val==check.value:
                return index
            check=check.next
            index+=1
        return -1
    def contains(self,val):
        check=self.first
        while check!=None:
            if val==check.value:
                return True
            check=check.next
        return False
    def __len__(self):
        return self.size
    def toList(self):
        list=[]
        check=self.first
        while check!=None:
            list.append(check.value)
            check=check.next
        return list
    def reverse(self):
        if self.size==0: return
        self.last=self.first
        first=None
        second=self.first
        while second!=None:
            save=second.next
            second.next=first
            first=second
            second=save
        self.first=first
    def kfromend(self,k):
        first=self.first
        second=self.first
        for _ in range(k):
            second=second.next
        while second!=None:
            first=first.next
            second=second.next
        return first.value

class Stack(LinkedList):
    def push(self,val):
        self.addFirst(val)
    def pop(self):
        check=self.first.value
        self.removeFirst()
        return check
    def peek(self):
        return self.top()
    def isEmpty(self):
        return self.size==0

def checker(str):
    stack=Stack()
    d={")":"(","]":"[",">":"<"}
    for l in str:
        if l in d.values():
            stack.push(l)
        if l in d.keys():
            if d[l]==stack.peek():
                stack.pop()
                continue
            else:
                return False
    return True
print(checker("([1]+<2/3>)"))
