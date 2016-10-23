"""
    Is Unique
    Implement an algorithm o determine if a string has all unique characters.
    What if you cannot use additional data structures?
"""


def is_unique(word):
    return len(word) == len(set(word))


if __name__ == '__main__':
