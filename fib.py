import time
import math

def fibonacci_form(n):
    sqrt5 = math.sqrt(5)
    phi = (1 + sqrt5) / 2
    psi = (1 - sqrt5) / 2
    return int((phi**n - psi**n) / sqrt5 + 0.5)

n = 10000
start = time.time()
value = fibonacci_form(n)
print(f"第 {n} 项为 {value}\n耗时: {time.time() - start}")