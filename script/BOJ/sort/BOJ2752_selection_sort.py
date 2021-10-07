# https://www.acmicpc.net/problem/2752
# [Required] Use the Selection Sort to solve it.

# Solver : Sieun Park
# Solved Date : 2021.02.28
# BigO: O(n2)

#selection_sort
def selection_sort(n_list):
    for i in range(len(n_list)-1):
        min_index = i
        for j in range(i+1, len(n_list)):
            if n_list[j] < n_list[min_index]: min_index = j
        if i != min_index: n_list[i], n_list[min_index] = n_list[min_index], n_list[i]
    return n_list

if __name__ == '__main__':
    n_list = list(map(int,input().split()))
    print(' '.join(map(str,selection_sort(n_list))))
