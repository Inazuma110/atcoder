#!/home/inazuma/.pyenv/shims/python3
import random

n = random.randint(1, 10 ** 5)
k = random.randint(1, 10 ** 12)
print(n, k)

for i in range(n):
    print(random.randint(1, 10 ** 12), end=' ')
print()
