import sympy as sp
from sympy import symbols,expand, factor
from sympy import *
x,y = symbols('x y')
expr = x + 2*y
x=8
print(x +2*y)
print(expr)
print(expr-2*y)
print(sp.sqrt(8))
x, t,z,nu = symbols('x t z nu')
# Calculate derivative of ..
init_printing(use_unicode=True)
diff(sin(x)**exp(x),x)