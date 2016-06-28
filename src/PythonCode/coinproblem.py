import numpy as np

def knapsack_coins(currencies, dollars):
    m = np.matrix(len(currencies),dollars)
    for i in range(len(dollars)):
        if i mod currencies[1] == 0:
            m[1,i] = 1
        else:
            m[1,i] = 0
        
    for i in range(2, len(currencies)):
        for w in range(dollars):
            if w == currencies[i]:
                m[i,w] = 1+m[i-1, w]
            elif w < currencies[i]:
                m[i,w] = m[i-1][w]
            else:
                m[i,w] = m[i-1, w] + m[i, w-currencies[i]]

    return m[len(currencies-1), dollars]





