# Ploblem : [피보나치 수 4] https://www.acmicpc.net/problem/10826

# Solver : Sieun Park
# Solved Date : 2020.03.02
# BigO: O(n)


def fibonacci_2(n):
    if n == 0: return 0
    elif n == 1: return 1
    else:
        t1, t2 = 0, 1
        for i in range(1,n):
            t1, t2 = t2, t1 + t2
        return t2

if __name__ == '__main__':
    n = int(input())
    print(fibonacci_2(n))