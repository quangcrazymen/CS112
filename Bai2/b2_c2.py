# count = 0
# def func(n):
#     global count
#     if(n==1):
#         count+=1
#         return 1
#     else:
#         count+=1
#         return func(n-1) + n

# print(func(10))
# print(count)

count = 0
count_1=0
count_2=0
count_3=0
def func(n):
    global count
    if(n==0): return 1
    s=0
    for i in range(1,n+1):
        s=s+i*i*func(n-i)
        count+=1
    return s

import math
def waste(n):
    global count_1
    if(n==0): return 0
    for i in range(1,n+1):
        for j in range(1,i+1):
            print(i,j,n)
    for i in range(1,4):
        waste(math.floor(n/2))
        count_1+=1

        

def Draw(n):
    global count_2
    if(n<1): return 0
    for i in range(1,n+1):
        for j in range (1,n+1):
            print('*')
    count_2+=1
    Draw(n-3)

def Zeta(n):
    if(n==0): alpha = 6
    else:
        k=0
        Ret = 0
        while(k<=n-1):
            Ret = Ret + Zeta(k)
            k+=1
        alpha = Ret
    
print(func(6))
# waste(11)
Draw(10)
print(count)
# print(count_1)
print(count_2)