# Ploblem : [하노이 탑 이동 순서] https://www.acmicpc.net/problem/11729

# Solver : Sieun Park
# Solved Date : 2021.03.09
# BigO: O(3^n)

# Feel free to use.
pos_1 = 0b100
pos_2 = 0b010
pos_3 = 0b001
count = 0

# Feel free to use.
def trans_pos (pos):
    if pos == pos_1:
        return 1
    elif pos == pos_2:
        return 2
    elif pos == pos_3:
        return 3
    return 0 # Error!

# Feel free to change anything.
def hanoi(f, t, n):
    global count
    if n==1:
        count+=1
        return [[f, t]]
    else:
        return hanoi(f, nor(f,t), n-1) + hanoi(f, t, 1) + hanoi(nor(f,t), t, n-1)

def nor(a,b):
    return 0b111 ^ (a | b)

if __name__ == '__main__':
    n = int(input())
    moves = hanoi(pos_1, pos_3, n)
    print(count)
    for m in moves:
        print('{} {}'.format(trans_pos(m[0]), trans_pos(m[1])))