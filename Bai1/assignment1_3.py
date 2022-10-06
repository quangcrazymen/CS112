import math
def func3_check(n):
    sum = 0
    i = 1
    count = 2
    while (i<=n):
        j = n-i*i
        count+=1
        while (j<=i*i):
            sum+=i*j
            j+=1
            count+=2
        i+=1
        count+=1
    return count

def func3(n):
    temp = 0
    begin = math.ceil(math.sqrt(n/2))
    print(begin)
    for i in range(begin,n+1):
        temp += 2*(i**2)-n+1
    return 2 + 2*n + 2*temp

print(func3(10))
print(func3_check(10))


