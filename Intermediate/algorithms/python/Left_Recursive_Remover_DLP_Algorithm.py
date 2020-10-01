# It removes Left recursive only at level 1
n = int(input("Enter No of Production rules for Grammar : "))
transD = {}
nonTerminals=[]
for x in range(n):
    s = input("Enter the " + str(x+1) + " th production: ")
    rules = []
    split = s.split("->")
    for i in split[1].split("|"):
        rules.append(i)
    transD[split[0]]=rules
    nonTerminals.append(split[0])
# print(transD)
# print(nonTerminals)
for i in nonTerminals:
    l=list(transD[i])
    newNonTerminal=i+"'"
    recPart=[]
    nonRecPart=[]
    for j in l:
        if j[0]==i:
            recPart.append(j)
        else:
            nonRecPart.append(j)
    print(i+"->",end="")
    for j in nonRecPart:
        if(nonRecPart.index(j)==(len(nonRecPart)-1)):
            print(j+newNonTerminal,end="")
        else:
            print(j+newNonTerminal+"|",end="")
    print("\b")
    print(newNonTerminal+"->",end="")
    for j in recPart:
        print(j[1::]+newNonTerminal+"|",end="")
    print("\u03B5")  





