/*
An array is given which is representing the dimensions of a matrix, r*c, in array arr (say)
the dimension of ith matrix is [arr[i-1]*arr[i]];

your task is to find the most efficient way to to multiply these matrices together such that the total

number of element multiplication is minimum.

Here, how to calculate the no of multiplication in a matrix??


consider a matrix

A(3*3) = 1 2 3
         4 5 6
         7 8 9
B(3*2) = 10 11
         12 13
         14 15

i want to multiply them, 1*10 + 2*12 + 3*14       1*11 + 2* 13 + 3*15
                         4*10 + 5*12 + 6*14       4*11 + 5*13 + 6*15
                         7*10 + 8*12 + 9*14       7*11 + 8*13 + 9*15


how many multiplications, did we do?? 18, yes?

now, actually there is a formula for it, which is,
for example, there are two matrices say, which are going to be multipled
example n*m and m*k, ofcourse the columns of first and rows of second must be say for being eligile for matrix multiplication, 
here, if we just do n*m*k, this will give is the no of multiplication are done in this multiplication

in our above example, it is 3*3, and 3*2, so 3*3*2 = 18, so we do not have to calculate it, we can do it by this only

so now the task of this question is, we have to mulitply these matrices in such order, such that, this elemental multiplication is minimum. 

Got it??

Now first give it a try,

*/