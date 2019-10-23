#First Recurring Character in O(n)

def rec(st):
    d={}
    for c in st:
        if c in d:
            return c
        d[c]='1'
    return None
st=str(input())
print(rec(st))
