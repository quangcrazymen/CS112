def func9_check(n):
    i = 1
    res = 0
    count = 2
    while (i<=n):
        j=1
        k=1
        count += 2
        while (j<=i):
            res = res + i*j;
            k = k+2	
            j = j+k
            count += 3	
        i = i+1
        count +=1
    return count

# for i in range(1,51):
#     print("BAI 9: {} : {}".format(i,func9(i)))
import math
def func9(n):
    temp = 0
    for i in range (1,n+1):
        temp = temp + math.floor(math.sqrt(i))
    return 2+ 3*n + 3*temp

def func9_2(n):
    return 2 + 3*n+ (2)*(n**(3/2))
print(func9(180))
print(func9_2(180))
print(func9_check(180))
