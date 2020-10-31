# MIT License
# Copyright (c) 2020 sarthaka1310


LIMIT = 10 ** 6


# Prints hailstone sequence with n as start till min(total stopping time, LIMIT)
# (refer https://en.wikipedia.org/wiki/Collatz_conjecture#Statement_of_the_problem)
def hailstone(n: int, k: int = 1):
    if n == 1:
        print("1\nTotal stopping time: ", str(k))
        return

    n = 3 * n + 1 if n % 2 else n // 2
    print(n)
    if k == LIMIT:
        print("Too many iterations")
    else:
        hailstone(n, k + 1)


test_cases = [4, 5, 6, 13, 54, 193, 7]

for case in test_cases:
    hailstone(case)
    print()
