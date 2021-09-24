import itertools

n = 4
m = 4
num_good_perms = 0

for perm in itertools.product([True, False], repeat=n*m):
    good_perm = True
    for i in range(n - 1):
        for j in range(m - 1):
            num_trues = 0
            for x, y in [(i, j), (i + 1, j), (i, j + 1), (i + 1, j + 1)]:
                if perm[x * m + y]:
                    num_trues += 1
            if num_trues != 2:
                good_perm = False
    if good_perm:
        mapped_perm = [[1 if perm[x*m+y] else 0 for y in range(m)] for x in range(n)]
        print(mapped_perm)
        num_good_perms += 1

print("good perms", num_good_perms)
