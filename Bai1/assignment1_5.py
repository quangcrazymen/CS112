import math
def func5_check(n):
    sum = 0
    i = 1
    count = 2
    while (i <= n):
        j=n-i
        count+=1
        while(j<=2*i):
            sum+=i*j
            j = j+2
            count+=2
        k = i
        count+=1
        while(k>0):
            sum = sum +1
            k=int(k/2)
            count+=2
        i = i+1
        count+=1
    return count

def func5(n):
    temp1 = 0
    temp2 = 0
    # begin = math.ceil(n/3)
    # print(begin)
    for i in range(1,n+1):
        if(i<math.floor((n/3))):
            temp1+=0
        else:
            temp1+=3*i - n
    for i in range(1,n+1):
        temp2+=math.floor(math.log2(i)) + 1
    return 2+(3*n)+(2*temp1)+(2*temp2)

print(func5(10))
print(func5_check(10))
