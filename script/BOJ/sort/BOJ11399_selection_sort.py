# Ploblem : https://www.acmicpc.net/problem/11399
# [Required] Use the Selection Sort to solve it.

# Solver : Sieun Park
# Solved Date : 2021.02.28
# BigO: O(n2)

def sol(n_list):
    #selection_sort
    for i in range(len(n_list)-1):
        min_index = i
        for j in range(i+1,len(n_list)):
            if n_list[j] < n_list[min_index]: min_index = j
        if i != min_index: n_list[i], n_list[min_index] = n_list[min_index], n_list[i] #swap
    
    #calculate total time
    total_time = 0
    for i in range(len(n_list)):
        total_time += sum(n_list[:i+1])
    return total_time

if __name__ == '__main__':
    n = int(input())
    n_list = list(map(int,input().split()))
    print(sol(n_list))
