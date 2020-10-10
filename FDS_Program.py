def getMarks(marks):
    print("\nNote : Marks should be out of 100")
    print("Student who remains Absent for the test please enter -1 for them:\n")
    num = int(input("Enter Number of Students in SE COMP2 :"))
    for i in range(0,num):
        print("Enter the marks of roll no",i+1, "in FDS :",end="")
        m = input()
        marks.append(m)

def display(marks):
    print("\n")
    print("-----Marks of Students In FDS Subject------")
    i=0
    for m in marks:
        print("Roll no",i+1,":" ,m)
        i+=1

def avgScore(marks):
    count=sum=avg=0
    n=len(marks)
    for i in marks:
        if int(i)== -1:
            count=count+1
        else:
            sum=sum+int(i)
    avg = sum/(n-count)
    print("\n The Average score of class is => ",avg)
   

def absentees(marks):
    count=0
    for i in marks:
        if int(i)== -1:
            count=count+1
    print("\n Number of Absentees =>",count)

def highLow_score(marks):
    low=99
    high=0
    cnt=0
    for i in marks:
        if int(i)==-1:
            cnt+=1
        elif int(i)>high:
            high=int(i)
    print("\nThe highest score of the class is =>",high)
    for i in marks:
        if int(i)==-1:
            cnt+=1
        elif int(i)<low:
            low=int(i)
    print("\nThe lowest score of the class is =>",low)

def high_freq(marks):
    k=1
    res = marks[0]
    for i in marks:
        if i != -1:
            freq = marks.count(i)
            if freq>k:
                k=freq
                res = i
    
    print("\nMarks with highest Frequency")
    print("Marks:",res,"Freq :",k,"\n")


def main():
    marks = []
    
    while True:
        print("\n\t\t1.Accept the marks of FDS subject")
        print("\t\t2.Display the marks")
        print("\t\t3.Average score of the class")
        print("\t\t4.Highest and lowest score of the class")
        print("\t\t5.Number of Absentees")
        print("\t\t6.Highest Frequency of the class")
        print("\t\t7.Exit")

        c = int(input("Enter choice :"))
        
        if c == 1:
            getMarks(marks)
        elif c== 2:
            display(marks)
        elif c==3:
            avgScore(marks)
        elif c==4:
            highLow_score(marks)
        elif c==5:
            absentees(marks)
        elif c==6:
            high_freq(marks)
        elif c==7:
            print("======Exit=====")
        else:
            print("\nEnter Valid Choice!\n")
main() 
