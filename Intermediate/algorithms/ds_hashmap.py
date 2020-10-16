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

    def removeAt(self,k):
        check=self.first
        for _ in range(k-1):
            check=check.next
        if k==0:
            self.removeFirst()
        elif k==self.size-1:
            self.removeLast()
        else:
            check.next=check.next.next
        self.size-=1

    def remove(self,val):
        check=self.first
        index=0
        while check!=None:
            if check.value==val:
                self.removeAt(index)
            check=check.next
            index+=1
        self.size-=1

#_______________________________________________________________________________

class Hashmap():
    def __init__(self):
        self.values=[]
        self.count=0
        for _ in range(5):
            self.values.append(LinkedList())

    def hashing(self,key):
        num=(sum(map(ord,str(key))))
        return num%len(self.values)

    def put(self,key,val):
        if self.count>len(self.values):
            for _ in range(self.count):
                self.values.append(LinkedList())

        key1=self.hashing(key)

        if not key in [tup[0] for tup in self.values[key1].toList()]:
            self.values[key1].addLast((key,val))
        else:
            self.values[key1].remove((key,self.get(key)))
            self.values[key1].addLast((key,val))
        self.count+=1

    def get(self,key,default=None):
        key1=self.hashing(key)
        list=self.values[key1].toList()
        for item in list:
            if item[0]==key:
                if item[1]!=None:
                    return item[1]
        return default

    def remove(self,key):
        key1=self.hashing(key)
        self.values[key1].remove((key,self.get(key)))
        self.count-=1

# mapp=Hashmap()
# mapp.put(1,"sahsdefsui")
# mapp.put(8,"txfy")
# mapp.put(21,"sasrethui")
# mapp.put("sasrethui",21)
# mapp.put("sasrethui",32)
# mapp.remove(768)
# print(mapp.get("sasrethui"))
