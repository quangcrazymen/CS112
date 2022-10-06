# Bai 1:
from re import X
import math

def sum1():
    sum = 0
    for i in range(1,1000,2):
        sum=sum+i
    return sum
def sum2():
    sum = 0
    for i in range(1,11):
        sum=sum+2**i
    return sum

def sum3(n):
    sum = 0
    for i in range(3,n+2):
        sum = sum+ i
    return sum

def sum4(n):
    sum = 0
    for i in range(0,n):
        sum = sum + i*(i+1)
    return sum

def sum5(n):
    sum =0
    for i in range(1,n+1):
        for j in range(1,n+1):
            sum+= i*j
    return sum

# test if the result would change after having changed the ORDER of sum
def sum6_1(m,n):
    sum = 0
    for i in range(1,m+1):
        for j in range(0,n+1):
            for k in range(0,101):
                sum += i+j
    return sum

def sum6_2(m,n):
    sum = 0
    for k in range(0,101):
        for j in range(0,n+1):
            for i in range(1,m+1):
                sum += i+j
    return sum

def sum6_3(m,n):
    sum = 0
    for k in range(0,101):
        for i in range(1,m+1):
            for j in range(0,n+1):
                sum += i+j
    return sum

def sum6_4(m,n):
    sum = 0
    for i in range(1,m+1):
        for j in range(0,n+1):
            sum+=i+j
    return sum

def sum6_4_1(m,n):
    sum = 0
    for j in range(0,n+1):
        for i in range(1,m+1):
            sum+=i+j
    return sum

def sum6_4_check(m,n):
    return (101/2)*((n+1)*(m**2+m)+(n**2+n)*m)
print("check")
print(sum6_4(5,7))
print(sum6_4_1(5,7))

print(sum1())
print(sum2())
print(sum3(20))
print(sum4(20))
print("g: {}".format(sum5(20)))
print("j1: {}".format(sum6_1(11,20)))
print("j2: {}".format(sum6_2(11,20)))
print("j3: {}".format(sum6_3(11,20)))
print("j4: {}".format(sum6_4_check(11,20)))


# Bai 2:
def func1(n):
    count = 2
    s =0
    i=1
    ss=0
    while(i<=n):
        ss+=1
        j=1
        while(j<=i**2):
            ss+=1
            s=s+1
            j+=1
            count+=2
        ss+=1
        i+=1
        count+=2
    ss+=1
    return count,ss

print(func1(7))

# def test(n):
#     sum = 0
#     for i in range (3,n+1):
#         sum = sum + i
#     return sum

# print(test(20))

# def test2(n):
#     sum=0
#     for i in range (2*n+1,3*n+1):
#         sum = sum + (i-2*n)
#     return sum

# print(test2(20))
# print((1+20)*((20*3-41+1)/2))

def func2(n):
    sum = 0
    for i in range (1,n+1):
        sum = sum + 3**(i+1)
    return sum

print(func2(10))

def func10(n):
    a = []
    sum = 0
    i=1
    idx = -1;
    while (i<=n):
        j=1
        while(j<=n):
            if((i==j) and (i+j==n+1)):
                idx = i
            sum = sum + a[i][j]
            j+=1
        i+=1
    if(idx != -1):
        sum = sum - a[idx][idx]

# BAI 4:
def fractal(n):
    p =1
    for i in range(1,n+1):
        p*=i
    return p

def func4(x,n):
    i = 1
    z = 0
    count = 2
    ss = 0
    while (i<=n):
        ss+=1
        j =1
        t =1
        count+=2
        while(j<=i):
            ss+=1
            t=t*x
            j=2*j
            count+=2
        ss+=1
        z=z+i*t
        i+=1
        count+=2
    ss+=1
    return z,count,ss

def func4_check(n):
    return 2*math.floor(math.log2(fractal(n))) + 6*n + 2

for i in range(1,15):
    print("BAI 4: {} : {}".format(i,func4(102,i)))
    print("BAI 4 - Check: {}".format(func4_check(i)))
    
print("BAI 4 : {}".format(func4(45,6)))



