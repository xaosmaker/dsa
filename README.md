# Journay to DSA

## Arrays
the arrays always is a continues block of memory
the 2d and the 3d array is the same the compilere make one block

in array i use pointer arithmetics `*(p + i)` it's for learning purposes. 

`*(p + i)` is difficult to read fast and this `[]` is better for reading

#### Arrays formulas

[c] = column

[r] = row

L[0] = start of the array

* array[c] = L[0] + c * sizeof(data)
* array[r][c] = L[0] + (c.len * r + c ) * sizeof(data)


## Recursion

a function calling itself.

* `base contition` is the condition that stop the function
it is necessary or else we may have a  stack overflow.

