import math
import pandas as pd


def func12_check(n):
    i = 1
    res = 0
    g = 2
    g_trong = 0
    while(i <= n):
        j = 1
        g += 1
        while(j <= i):
            res += i*j
            j = j+1
            g += 2
            g_trong += 2
        i += 2
        g += 1
    return g, g_trong


def func12(n):
    return 2*(((n+1)*math.ceil(n/2))/2)+n+2


for i in range(1, 20):
    # print(i)
    print(func12(i))
    print(func12_check(i))

print(func12_check(5))

formula1 = pd.Series([func12(i) for i in range(1, 21)])
real_result = pd.Series([func12_check(i)[0] for i in range(1, 21)])

data = {'Gán công thức': formula1, 'Kết quả thực': real_result}
df = pd.DataFrame(data)
df.to_excel('Bai12.xlsx')
