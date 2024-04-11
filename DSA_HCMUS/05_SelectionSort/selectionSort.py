import random
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

#Hàm sắp xếp selectionSort
def selectionSort(arr):
    global comps
    global swaps
    comps = 0; swaps = 0
    n = len(arr)
    for i in range(n - 1):
        min_idx = i
        for j in range(i + 1, n):
            comps+=1
            if arr[j] <= arr[min_idx]:
                min_idx = j
        if min_idx != i:
            swaps += 1
            arr[i], arr[min_idx] = arr[min_idx], arr[i]




def solve(loop, n):
    print('\n--------------------K = {}--------------------'.format(loop))
    swaps_frequence = [0]*21
    global comps
    global swaps
    comps_total = 0
    swaps_total = 0
    for i in range(loop):
        arr = [random.randint(-100, 100) for _ in range(20)] #random mảng
        selectionSort(arr) #gọi hàm sắp xếp
        comps_total += comps
        swaps_total += swaps
        swaps_frequence[swaps] += 1
    #Vẽ dataFrame
    x = np.arange(n + 1)
    y = swaps_frequence
    my_data = pd.DataFrame(np.array(y).reshape(1,21), ['Frequency'], np.array(x))
    print(my_data)
    print('\nMean Comps = {}\nMean Swaps = {}'.format(comps_total / loop, swaps_total / loop))
    #Plot đồ thị
    fig = plt.figure()
    axes1 = fig.add_axes([0, 0, 1, 1])
    axes1.plot(x, y, color = 'red', lw = 2, ls = '--')
    axes1.set_xlabel('Swaps')
    axes1.set_ylabel('Swaps Frequency')
    axes1.set_title('K = {}'.format(loop))
    fig.show()





# Main
k = [20, 30, 50, 100, 1000, 10000]
n = 20
for i in k:
    solve(i, n)
    choice = input('Enter để tiếp tục! Hoặc bất kì ký tự nào để thoát: ')
print('Kết thúc!')
