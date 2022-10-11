count = 0
def func(n):
    global count
    if n ==1:return 1
    count+=1
    count+=n
    return func(n-1)
func(100)
print(count)