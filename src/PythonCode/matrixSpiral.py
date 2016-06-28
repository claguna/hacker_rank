import numpy
import math
m = numpy.matrix([
	[1, 2, 3],
	[4, 5, 6],
	[7, 8, 9]
	])

def spiral_aux(matrix,offset):
	n = len(matrix)
	m = len(matrix[0])
	if offset == n - offset -1:
		print matrix[offset, offset]
		return

	for j in range(offset, n-offset):
		print (matrix[offset, j])

	for i in range(offset+1, n-offset-1):
		print (matrix[i,n-offset-1])

	for j in range(n-offset-1, offset, -1):
		print (matrix[n-offset-1, j])

	for i in range(n-offset-1, offset, -1):
		print (matrix[i,offset])



print m

#spiral_aux(m,0)

for offset in range(0, int(math.ceil(0.5*len(m)))):
	spiral_aux(m,offset)
	print "-----------"