import random
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

def insertSort(arr):
    global comps
    global shifts
    comps = 0; shifts = 0
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while(j >= 0 and arr[j] > key):
            comps += 1
            shifts += 1
            arr[j + 1] = arr[j]
            j-=1
        arr[j + 1] = key
        if(j >= 0):
            comps += 1
    




def solve(loop, n):
    print('\n--------------------K = {}--------------------'.format(loop))
    swaps_frequence = [0]*21
    global comps
    global shifts
    comps_total = 0
    swaps_total = 0
    for i in range(loop):
        arr = [random.randint(-100, 100) for _ in range(20)]
        insertSort(arr)
        comps_total += comps
        swaps_total += shifts
        swaps_frequence[shifts] += 1
    x = np.arange(n + 1)
    y = swaps_frequence
    my_data = pd.DataFrame(np.array(y).reshape(1,21 ), ['Frequency'], np.array(x))
    print(my_data)
    print('\nMean Comps = {}\nMean shifts = {}'.format(comps_total / loop, swaps_total / loop))

    fig = plt.figure()
    axes1 = fig.add_axes([0, 0, 1, 1])
    axes1.plot(x, y, color = 'red', lw = 2, ls = '--')
    axes1.set_xlabel('shifts')
    axes1.set_ylabel('shifts Frequency')
    axes1.set_title('K = {}'.format(loop))
    fig.show()


k = [20, 30, 50, 100, 1000, 10000]
n = 20
for i in k:
    solve(i, n)
