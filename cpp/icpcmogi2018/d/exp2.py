cl = [sum([9*2**j for j in range(i)])*9 for i in range(55)]
print(cl)
# for i in range(100):
#     tmp = sum([9*2**j for j in range(i)])*9
#     if tmp >= 10**18:
#         break
#     print(i, tmp)