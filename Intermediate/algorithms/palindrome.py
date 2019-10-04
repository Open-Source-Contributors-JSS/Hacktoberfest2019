def isPalindrome(word):
    if (word == word[::-1]):
        return 1
    else:
        return 0

if __name__ == "__main__":
    word = input("Word:")
    if (isPalindrome(word)):
        print("Is a palindrome word")
    else:
        print("Is not a palindrome word")