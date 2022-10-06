import pandas as pd

def func11_check(n):
    i =1
    ret = 0
    s=0
    count = 3
    ss = 0	
    while (i<=n):
        ss+=1
        j=1;								
        s= s+1/i
        count +=2
        while (j<=s):	
            ss+=1					
            ret = ret + i*j;
            j = j+1
            count+=2;
        ss += 1
        i = i+1;
        count+=1
    ss+=1
    return count,ss

import math						
def func11(n):
    return (math.floor(3 + 3*n+ (n*math.log(n) + n*0.5772)*2),
            math.floor(2*n + 1 + n*math.log(n) + n*0.5772))

def func11_elimanate_const(n):
    return (math.floor(3 + 3*n+ (n*math.log(n) *2)),
            math.floor(2*n + 1 + n*math.log(n)))

print(func11(20))
print(func11_elimanate_const(20))
print(func11_check(1))
# Gan
formula1 = pd.Series([func11(i)[0] for i in range(1,21)])
formula2 = pd.Series([func11_elimanate_const(i)[0] for i in range(1,21)])
real_result = pd.Series([func11_check(i)[0] for i in range(1,21)])
# So sanh
ss_formula1 = pd.Series([func11(i)[1] for i in range(1,21)])
ss_formula2 = pd.Series([func11_elimanate_const(i)[1] for i in range(1,21)])
ss_real_result = pd.Series([func11_check(i)[1] for i in range(1,21)])

index = [i for i in range(1,21)]
data = {'Gán công thức 1':formula1,'Gán công thức 2':formula2,'số phép gán thực':real_result,
        'So sánh công thức 1':ss_formula1,'So sánh công thức 2':ss_formula2,'số phép so sánh thực':ss_real_result}
df = pd.DataFrame(data)
# in ra file excel
# df.to_excel('Bai_11.xlsx')
print(df.head())
#print(formula1)
# print(formula2)
# print(real_result)
