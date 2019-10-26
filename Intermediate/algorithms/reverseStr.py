'''
    Function to show a reversed string recursively
'''

def rev(s):
    if len(s) == 0:
        return s
    else:
        return rev(s[1:]) + s[0]

print(rev('reverse'))