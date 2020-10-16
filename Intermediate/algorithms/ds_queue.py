class queue():

    def __init__(self):
        self.first=None
        self.next=None
        self.size=0

    def isEmpty(self):
        if self.size==0:
            return True
        else: return False


    def add(self,val):
        if self.first==None:
            self.first=val
        elif self.next==None:
            self.next=queue()
            self.next.add(val)
        else: self.next.add(val)
        self.size+=1

    def move(self,times=1):
        for a in range(times):
            if self.next!=None:
                self.first=self.next.first
                self.next.move()
                self.size-=1


    def add_multiple(self,list):
        for val in list:
            self.add(val)




n=queue()
n.add(21)
n.add_multiple([32,43,54,78])
print(n.size)
print(n.first)
n.move(4)
# n.move()
# n.move()
print(n.first)
print(n.size)
