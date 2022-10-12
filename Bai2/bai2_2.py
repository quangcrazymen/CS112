count = 0
n=100
def func(n):
    global count
    if n ==1:return 1
    count+=1
    count+=n
    return func(n-1)
func(100)
print(count)
print((n**2+n)/2)