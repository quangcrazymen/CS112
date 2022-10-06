from turtle import color
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

def func4(x,n):
    i = 1
    z = 0
    count = 2
    ss = 0
    while (i<=n):
        ss+=1
        j =1
        t =1
        count+=2
        while(j<=i):
            ss+=1
            t=t*x
            j=2*j
            count+=2
        ss+=1
        z=z+i*t
        i+=1
        count+=2
    ss+=1
    return z,count,ss

x = np.linspace(1,1000,1000)
fx = np.array([])
for i in range (1,1001):
    (z,count,ss)  = func4(np.random.randint(1,100),i)
    fx = np.append(fx,count)
    
print(fx.shape)
print(x.shape)
df = pd.DataFrame({'x':x,'fx':fx})
print(df.head())

# Actual number of operations
print("Actual number of asignment operation: {}".format(df.iloc[99]['fx']))
poly_reg = PolynomialFeatures(degree =2)
X_poly = poly_reg.fit_transform(x.reshape(1000,1))
lin_reg = LinearRegression()
lin_reg.fit(X_poly,fx)

print("Predicted value: {}".format(lin_reg.predict(poly_reg.fit_transform([[100.0]]))))
print("Predicted value using coefficient and intercept: {}".format(lin_reg.coef_[1]*100+lin_reg.coef_[2]*(100**2)+lin_reg.intercept_))

# https://www.geeksforgeeks.org/how-to-extract-the-intercept-from-a-linear-regression-model-in-r/#:~:text=The%20simple%20linear%20regression%20model,the%20intercept%3B%20labeled%20as%20constant.
print("coeficient is: ")
print(lin_reg.coef_)
print("intercept is: ")
print(lin_reg.intercept_)

plt.scatter(x,fx,color='red')
X_grid = np.arange(min(x), max(x), 0.1)
X_grid = X_grid.reshape((len(X_grid), 1))
plt.plot(X_grid,lin_reg.predict(poly_reg.fit_transform(X_grid)),color = "blue")
plt.show()