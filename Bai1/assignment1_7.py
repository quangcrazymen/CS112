def func6_check(n):
    i = 1
    count = 0
    g = 2
    ss = 0
    g_if = 0
    gan_if_trong = 0
    while(i<=4*n):
        ss += 1
        x=(n-i)*(i-3*n)
        y=i-2*n
        j=1
        g+=3
        while (j<=x):
            if(i>=2*y):
                count = count - 2
                gan_if_trong+=1
                g+=1
                ss+=1
            j+=1
            g+=1
        i+=1
        g+=1
    return g,ss,g_if,gan_if_trong

def func6(n):
    temp1 = 0
    temp2 = 0
    for i in range(n+1,3*n):
        temp1+=(n-i)*(i-3*n)
    # for i in range(n+1,3*n):
    #     temp2+=1
    return 2+ 16*n+ temp1*2

for i in range(12,15):
    print(func6(i))
    print(func6_check(i))
