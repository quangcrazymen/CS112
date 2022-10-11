count = 0
def func(n):
    global count
    if n ==1:return 0
    count+=1
    count+=5
    return func(n-1)
func(5)
print(count)