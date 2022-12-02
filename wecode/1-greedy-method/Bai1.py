def removeKdigits(num, k):
 
    n = len(num)
    mystack = []
     
    # Store the final string in stack
    for c in num:
        while (len(mystack) > 0 and k > 0
               and mystack[-1] > c):
            mystack.pop()
            k -= 1
 
        if (len(mystack) > 0 or c != '0'):
            mystack.append(c)
 
    # Now remove the largest values from the top of the stack
    while (len(mystack) > 0 and k):
        k -= 1
        mystack.pop()
    if (len(mystack) == 0):
        return "0"

    while (len(mystack) > 0):
        num = num.replace(num[n - 1] , mystack[-1])
        mystack.pop()
        n -= 1
 
    return num[n:]
 
# main
def main():
    number = input()
    k = int(input())
    print(removeKdigits(number, k))

if __name__ == "__main__":
    main()
