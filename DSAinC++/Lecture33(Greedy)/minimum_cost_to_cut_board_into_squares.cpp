#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// question is really amazing, understand the question first
/*
Here, you are given a board, the length of the board is M and the width of the board is N,
you have to cut the board into m*n pieces, you are also given a cutting edge cost in the form
of two arrays X[] and Y[], means when
you cut a particular edge from the board, you will be charged a cost, you have to minimise this cost
as well as you have to cut the board into m*n pieces




Solution :
think, like you made a vertical cut into the board,
how many pieces of the board are right now??
two pieces, one in left and one in right,
say the cost of cutting this particular edge (vertically) is x,

now, when we will try to make a horizontal cut in the board, we will have to cut the board
two times, (as previously there were two pieces of board due to vertical cut),
so whatever is the cost of cutting the edge, will get double, this time

now, after this horizontal cut, how many pieces of the board are there?
4 pieces right?
now think about it,
now if I make a horizontal cut right now,
still i will have to cut the two boards,(thus horizontal cuts(in numbers of board) are influenced by vertical cuts)
and similarly vertical cuts
but, in this situation if I make a vertical cut, I will have to cut the board twice

and so on

*/
bool cmp(int &a, int &b)
{
    return a > b;
}

int minCostToCutTheBoard(int M, int N, vector<int> &X, vector<int> Y)
{

    sort(X.begin(), X.end(), cmp);
    sort(Y.begin(), Y.end(), cmp);

    int v = 1; // will count the no of vertical cuts
    int h = 1; // will count the no of horizontal cuts
    int cost = 0;
    int j = 0;
    int i = 0;
    while (i < X.size() && j < Y.size())
    {
        if (X[i] > Y[j])
        {
            v++;
            cost += X[i++] * h;
        }
        else
        {
            h++;
            cost += Y[j++] * v;
        }
    }
    while (i < X.size())
    {
        cost += X[i++] * h;
    }

    while (j < Y.size())
    {
        cost += Y[j++] * v;
    }
    return cost;
}

int main()
{

    // TC(nlogn + mlogn)
    vector<int> X = {2, 1, 3, 1, 4};
    vector<int> Y = {4, 1, 2};
    int M = 6;
    int N = 4;
    cout << minCostToCutTheBoard(M, N, X, Y);
    return 0;
}