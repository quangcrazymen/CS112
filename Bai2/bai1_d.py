count = 0
def func(n):
    global count
    if n==0:
        return 1
    s= 0
    for i in range (1,n+1):
        count+=1
        s = s+i*i*func(n-i)
    return s
func(5)
print(count)