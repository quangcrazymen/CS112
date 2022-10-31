import math

n=1001
def fractal(n):
    result = 1
    for i in range(1,n+1):
        result=result*i
    return result

def C(n,k):
    return fractal(n)/(fractal(n-k)*fractal(k))

print(fractal(3))
print(C(n,100))
print(n**100)
print(1/n)
print((10**1000)*n)
print(1000*math.log(1000))

print(n**100>C(n,100))
