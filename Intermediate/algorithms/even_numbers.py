#!usr/bin/env python3

"""
Even Numbers Functional

This is a simple example of using functions in Python without using
while or for loops to solve a simple problem of finding even numbers.
"""

def even_numbers(list_of_num):
    return list(filter(lambda x: x % 2 is 0, list_of_num))


test_list = [10, 9, 8, 22, 46, 37, 99, 2293928, 25, 2, 3, 4]
result = even_numbers(test_list)
print(result) # [10, 8, 22, 46, 2293928, 2, 4]