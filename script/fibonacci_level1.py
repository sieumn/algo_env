# Ploblem : [피보나치 수 5] https://www.acmicpc.net/problem/10870

# Solver : Sieun Park
# Solved Date : 2021.03.01
# BigO: O(2^n)

def fibonacci_1(n):
    if n == 0: return 0
    elif n == 1: return 1
    else: return fibonacci_1(n-1)+fibonacci_1(n-2)

if __name__ == '__main__':
    n = int(input())
    print(fibonacci_1(n))