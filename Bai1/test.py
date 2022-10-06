# check if sum lg(i) = nlg(n)
import math
n = 10000

def fractal(n):
    p =1
    for i in range(1,n+1):
        p*=i
    return p

def sumOfLog(n):
    sum = 0
    for i in range (1,n+1):
        sum += math.log2(i) + 1
    return sum

print("use for loop {}".format(sumOfLog(n)))
print("use estimation: {}".format(math.log2(fractal(n))+ n) )
print(fractal(3))
#[HƯỚNG DẪN BÀI TẬP] HW#01. Bài 4. Công thức tổng của các log
#Ở bài 4 em có tính ra được số vòng lặp của vòng while trong với công thức như trên, mình phá sigma ra thì xấp xỉ được như trên không ạ?