#!/home/inazuma/.pyenv/shims/python3.8
import random

n = random.randint(1, 10**4)
t = random.randint(2, 10**9)
print(n, t)
l = set([i for i in range(10**6)])
l = random.sample(l, n)

for i in l:
    print(i)
