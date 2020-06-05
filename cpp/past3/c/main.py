import numpy as np


tmp = '''.###..#..###.###.#.#.###.###.###.###.###.
.#.#.##....#...#.#.#.#...#.....#.#.#.#.#.
.#.#..#..###.###.###.###.###...#.###.###.
.#.#..#..#.....#...#...#.#.#...#.#.#...#.
.###.###.###.###...#.###.###...#.###.###.
'''

tmp = tmp.split('\n')
tmp = [[i for i in tmp[j]] for j in range(5)]
tmp = np.array(tmp)

tmp2 = ['' for i in range(10)]

for i in range(10):
    tmp2[i] = tmp[:, 4*i:4*i+4]
    tmp2[i] = np.array(tmp2[i])

tmp2 = np.array(tmp2)


n = int(input())
l = ["" for i in range(5)]
for i in range(5):
    l[i] = input()
    l[i] = [j for j in l[i]]

l = np.array(l)
res = ''
for i in range(n):
    tmp = l[:, 4*i:4*i+4]
    for j in range(10):
      if np.all(tmp == tmp2[j]):
        res += str(j)

print(res)
