import sys

l = list(map(int, input().split()))
max_so_far = -sys.maxsize - 1
max_ending_here = 0
for i in range(0, len(l)):
    max_ending_here += l[i]
    if max_ending_here < 0:
        max_ending_here = 0
    max_so_far = max(max_so_far, max_ending_here)
print(max_so_far)
