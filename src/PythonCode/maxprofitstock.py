def max_stock(array):
	min_value = array[0]
	max_profit = 0
	for i in range(1, len(array)):
		min_value = min(min_value, array[i])
		max_profit = max(max_profit, array[i]-min_value)

	return max_profit

a = [6,5,4,3,2]
print (max_stock(a))