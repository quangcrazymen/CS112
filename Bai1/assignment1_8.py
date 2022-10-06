def func8_check(n):
    i = 1
    count = 0
    gan_if_1 = 0
    gan_if_2 = 0
    gan_while=0
    gan = 2
    ss=0
    while(i<=3*n):
        ss +=1
        x = 2*n - i
        y = i - n
        j = 1
        gan += 3
        while(j<=x):
            ss+=1
            if(j>=n):
                count-=1
                gan_if_1+=1
                gan += 1
            j = j+1
            gan+=1
            gan_while+=1
        ss+=1
        if(y>0):
            ss+=1
            if(x>0):
                ss+=1
                count+=1
                gan_if_2+=1
                gan+=1
            ss+=1
        ss+=1
        i+=1
        gan+=1
    ss+=1
    return gan,ss,gan_if_1,gan_while

def func8(n):
    return 1 + 13*n + (5*(n**2)-n)/2 
for i in range (0,15):
    print(func8(i))
    print(func8_check(i))