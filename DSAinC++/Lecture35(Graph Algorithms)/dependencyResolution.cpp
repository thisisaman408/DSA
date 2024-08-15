/*

a very simple problem in which for example say
pytorch

to install pytorch we need pip to install pip we need C compiler and so on

sometimes it can be really large

for ex say for A we need n other files
now to install each n file we need another k files

so can you imagine? This is taking a form of graph..!

also it is a directed graph..

also
say

if for A we need B for B we need C for C we need A

this dependency problem is insolvable, also known as dead lock

so this dependency graph should be acyclic


so we need directed acyclic graph
also known as DAG (Directed acyclic graphs)

Dependency Problem is also a kind of DAG.


A question is there in google interviews, like

n equilities are given, 
i have to figure whether these inequilities are solvable or not??

it is a problem of dependeny problem
for example

a < b, b < v, e < f, g < e, a < d , g < t etc etc

we can imagine this in terms of dependence problem

if a < b, thus a <- b, thus b depends on a, to install b first we need a,

now make a graph of these values
if they make a DAG thus these problems are solvable else not!


to prove that they make a DAG

we use topological sort!!!!!!!!!




*/