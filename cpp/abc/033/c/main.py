exps = list(input().split('+'))
count = 0

for term in exps:
    if '0' in term:
        count += 1

print(len(exps) - count)

