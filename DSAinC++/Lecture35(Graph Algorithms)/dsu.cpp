// dsu
/*
data set union,
basically in this data structure, we will divide elements in the group,

it's helpful in the problem solving, cause we can store two different connected components

some important termilogies


1) Leader/parent of the group
-- we will iterate in a connected component and make any element the representative/parent/leader of the group
this will help in identifying the data set or our connected component



how to use?



what functions dsu need to support??



- union (a,b) (a function) adds the group where element b belongs to the group where element a belongs and vice versa
explanation

say union(1,5)

now say, there are two groups,

(1,2,3) say leader is 1         and (4,5,12) say leader is 4
 so, this union function, will add the group of  5  to the grooup where 1 belongs

so this how the group will look like
(1,2,3,,4,5,12)

so this function, first need to identify the groups to which 1 or 5 belongs and then add them together.
this is similar like sets in our 11th class


now, as group of 5 is being added to group of 1,
then leader of this new
(1,2,3,4,5,12) will be 1,
as the group is being added to the group of 1




- find(x) or get(x)

this will be used to find, x belongs to which group?
simple it will iterate with the leaders of each group, and then iterate through each member of the group
and then it will return the leader of the group with which x belongs to.


for example, there are 3 groups
(1,2,4) leader : 1        (5,6,3) leader : 5      (10,11,34) leader : 11



now say we call find(6)

so it will iterate through all the 1,5 and 11
and this fucntion will return 5, as 6 belongs to the group whose leader is 5






Now, implementation

approach 1 : add all the elements of a particular group in a set, unordered maybe
and then create an array of set,
but this has a drawback, when we have to union, this will take too much tc





approach 2 : Use arrays
we will use indexes to represent the element
say array name is parent
so i is the element
and parent[i] represent which group does ith element belongs to

this is really easy and very fast
how?

say this is the array right now

0 1 2 3 4 5 6 7 8 9 10          -> these indexes represent numbers
0 1 2 3 4 5 6 7 8 9 10          -> this is the element at ith index, initially every element is present in it's own group,

say we got a call of, union(2,4) which means merge the group which has 4 to the group which has 2
so, first we will go the index 4, parent[4] = 4, so the value at index 4 is 4, which is leader of index 4
so i will now iterate through the entire array, and wherever there is written parent[i=4]= 4, i will make it 2

thus now the array will be

0 1 2 3 4 5 6 7 8 9 10
0 1 2 3 2 5 6 7 8 9 10

so now, element 2 and element 4 both are in the group of 2

let's now do union(0,1)

so go to index 1, and get his parent which is 1 again
now iterate through array whereever 1 is present make it 0

0 1 2 3 4 5 6 7 8 9 10
0 0 2 3 2 5 6 7 8 9 10

so now, the element 0 and 1 belongs to 0, the elements 2 and 4 belongs to parent 2

now we get a call union(1,4), thus merge the group of 4 to the group of 1

so go to the index 4, we get the value at index 4 as 2, thus 4 belongs to index 4

now, we will iterate through the array, and whereever there is 2, we will make it parent[1], parent[1] is 0, so we will make that 0

0 1 2 3 4 5 6 7 8 9 10
0 0 0 3 0 5 6 7 8 9 10

so now, 0 1 2 4 belongs to group 0

see we have easily union the two groups with this approach





*/

// implementing approach 2

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class dsu
{
public : 
    vector<int> ds;
    unordered_map<int,int> mp;
    dsu()
    {
        ds.resize(1000);
        for (int i = 0; i < 1000; i++) ds[i] = i;
    }
    int find(int val) {return ds[val];}
    void unite (int a, int b)
    {
        int x = find(a);
        mp[x]++;
        int y = find(b);
        mp[y]++;
        for (int i = 0; i < ds.size(); i++)
        {
            if (mp[x] < mp[y] && ds[i] == x) ds[i] = y;
            else  if (mp[x] >= mp[y] && ds[i] == y) ds[i] = x;
        }
    }
    void display(int n){
        for(int i = 0; i< n ; i++ ) cout<<ds[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    dsu a;
    a.unite(4, 10);
    cout << a.find(10)<<endl;
    a.display(12);
}
//0 1 2 3 4 5 6 7 8 9 4 11 


//this is not that good approach