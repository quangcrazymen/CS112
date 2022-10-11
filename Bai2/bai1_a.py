def func(n):
    if n==0: return 10000
    return func(n-1)*1.0625

print(func(4))