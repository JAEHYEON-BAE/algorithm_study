import sys
def algorithm(x):
    x = sorted(x, key = lambda a: (len(a), a))
    return x

n = int(sys.stdin.readline())
x = set()
for _ in range(n):
    x.add(str(sys.stdin.readline().strip()))
for w in (algorithm(x)):
    print(w)