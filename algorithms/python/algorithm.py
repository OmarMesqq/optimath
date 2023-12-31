import timeit
from functools import partial

def ite(a, b):
    if b == 0:
        return 0
    original = a
    count = 1 
    while count < b: 
        a += original
        count += 1
    return a

def rec(a, b, depth=0):
    original = a
    if b == 0:
        return 0, depth
    if b == 1:
        return a, depth
    b -= 1
    result, depth = rec(a, b, depth + 1)
    return original + result, depth

def fib(n):
    if n <= 1: return n;
    return fib(n - 1) + fib(n - 2)

def sumSigma(k):
    summ = 0
    n = 0
    while n <= k:
        summ += 5*n
    return summ


def productPi(k):
    prod = 1
    n =1
    while n <= k:
        prod *= 4*n**2
    return prod



a = 4
b = 4 

res_rec, rec_depth = rec(a, b)
res_ite = ite(a,b)

tempo_ite = timeit.timeit(lambda: ite(a, b), number=1)
tempo_rec = timeit.timeit(lambda: rec(a, b), number=1)

print(f"Resultado iterativo de {a}x{b}: {res_ite}")
print(f"Resultado recursivo de {a}x{b}: {res_rec}")
print(f"Execução iterativa foi de {tempo_ite} segundos")
print(f"Execução recursiva foi de {tempo_rec} segundos")
print(f"Profundidade da recursão foi de {rec_depth}")
