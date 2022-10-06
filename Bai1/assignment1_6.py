def func6_check(n):
    i = 1
    count = 0
    g = 2
    ss = 0
    g_if = 0
    while(i<=4*n):
        ss += 1
        x=(n-i)*(i-3*n)
        y=i-2*n
        j=1
        g+=3
        while (j<=x):
            ss+=1
            count -=2
            j+=2
            g+=2
        if(x>0):
            ss+=1
            if(y>0):
                ss+=1
                count+=1
                g+=1
                ss+=1
                g_if+=1
            ss+=1
        i+=1
        g+=1
        ss +=1
    ss+=1
    return g,ss,g_if

def f1_test_check(n):
    sum = 0
    for i in range(n+1,3*n):
        sum += i
    return sum

def func6(n):
    temp1 = 0
    temp2 = 0
    for i in range(n+1,3*n):
        temp1+=(n-i)*(i-3*n)
    for i in range(n+1,3*n):
        temp2+=1
    return 1 + 17*n+ temp1 +(temp2/2)
    

# for i in range (1,21):
#     print("func6_formula: {}".format(func6(i)))
#     print("func6_check: {}".format(func6_check(i)))
#     print("func6_formula_2: {}".format(17*i+1+(f1_test_check(i)/2)))
    
print(func6(12))
print(func6_check(12))

# def f1_test(n):
#     return (4*n*(2*n-1))/2

# for i in range (1,21):
#     print(f1_test(i))
#     print(f1_test_check(i))