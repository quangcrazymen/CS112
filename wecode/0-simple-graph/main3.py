import numpy as np
# import io,os
# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# a = input()
a=input()
[v,e,n]=a.split()

adjMatrix=np.zeros((int(v),int(v)))
for i in range(0,int(e)):
    [vertex,adjVertex]=input().split()
    adjMatrix[int(vertex)-1,int(adjVertex)-1]=int(adjVertex)

print(adjMatrix)
for i in range(0,int(n)):
    oper=input().split()
    if(len(oper)==3):
        [op,ver,adjVer]=oper
        if(adjMatrix[int(ver)-1,int(adjVer)-1]==adjVertex):
            print("TRUE")
        else:
            print("FALSE")
    if(len(oper)==2):
        [op,ver]=oper
        print(" ".join(str(adjMatrix[int(ver)-1])))
# print(a)