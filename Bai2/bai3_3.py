import math
count = 0
n= 100
def func(n):
    global count
    if n==1: return 1
    count+=1
    count+=n**3
    return func(int(n/2))+func(int(n/2))+func(int(n/2))+func(int(n/2))+func(int(n/2))+func(int(n/2))+func(int(n/2))+func(int(n/2))
    # return func(int(n/2))
func(n)
print(count)
print(n**3*(1+math.log2(n)))