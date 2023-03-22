n = int(input())

if n == 1:
    print(1)
else:
    for i in range(n):
        print(" " * (n - i - 1), end="")
        print(i + 1, end="")

        if i != 0:
            for j in range(1, (2 * i - 1) // 2 + 2):
                print((i + j + 1) % 10, end="")
            for j in range((2 * i - 1) // 2, 0, -1):
                print((i + j + 1) % 10, end="")
            print(i + 1, end="")
            if i != n - 1:
                print("")
        else:
            print("")
