ΚΙΤΣΙΟΣ ΠΑΝΑΓΙΩΤΗΣ

03116007

ΠΡΟΗΓΜΕΝΑ ΘΕΜΑΤΑ ΑΛΓΟΡΙΘΜΩΝ 2019-2020 ΕΑΡΙΝΟ

1η ΣΕΙΡΑ ΑΣΚΗΣΕΩΝ

My apologies for English!
 
# Contents

<!-- MarkdownTOC  autolink="true" -->

- [Exercise One - Linear Programming](#exercise-one---linear-programming)
	- [Transforming And Solving The Initial Problem](#transforming-and-solving-the-initial-problem)
	- [The dual problem](#the-dual-problem)
- [Exercise Three - Binary Search](#exercise-three---binary-search)
	- [Core Idea](#core-idea)
	- [Setting Up The Binary Search](#setting-up-the-binary-search)
	- [The Oracle](#the-oracle)
	- [Obtaining The First Solution](#obtaining-the-first-solution)
	- [Complexity](#complexity)
- [Exercise Four - Farka's Lemma](#exercise-four---farkas-lemma)
- [Exercise five - Vertex Cover](#exercise-five---vertex-cover)
	- [Validity](#validity)
	- [Upper Bound](#upper-bound)
	- [Lower Bound On Optimal](#lower-bound-on-optimal)
- [Exercise Six - Vertex cover](#exercise-six---vertex-cover)
	- [Part a](#part-a)
	- [Part b - The approximation algorithm](#part-b---the-approximation-algorithm)
		- [Validity](#validity-1)
		- [Approximation Ratio](#approximation-ratio)
		- [Tight example](#tight-example)
- [Exercise Seven -  Lower Bound](#exercise-seven---lower-bound)
- [Exercise Eight - f Approximation Set Cover](#exercise-eight---f-approximation-set-cover)
	- [Cardinality](#cardinality)
	- [Weighted](#weighted)
		- [degrees weighted function Lemma](#degrees-weighted-function-lemma)
		- [The Algorithm](#the-algorithm)
		- [Validity](#validity-2)
		- [Approximation](#approximation)
		- [Tight Example](#tight-example-1)
- [Exercise Nine - Metric Tsp Path Upper Bound](#exercise-nine---metric-tsp-path-upper-bound)

<!-- /MarkdownTOC -->

# Exercise One - Linear Programming

## Transforming And Solving The Initial Problem

using the second equation we can write the objective function as follows

```python
3*x1+x2+x3+x4 = x2+5*x3-1
```

Because -1 is a constant, we can temporarily "ignore" it and simply add it to the final optimization result. By applying seeming replacements to the rest of the linear program indeed if we set `u=x2` and `v=x3` we can arrive at

```python
min u+5v

u+3*v = 2
4*v-1>=0
v<=3
u,v>=0
```

so basically in the `U-V` space we are dealing with a line segment with `(1/4)<=v<=(2/3)` with the direction of optimization being that of the negative gradient of the objective function, that is `(-1,-5)`

As a consequence the optimal solution must be for `v=1/4,u=5/4` with an optimal cost of `5/2`

Going back to the original problem, we see that such solution is possible only if `x1=x4=0,x2=5/4,x3=1/4` with optimal cost of `3/2`

## The dual problem 

The corresponding dual problem can be formulated as follows

```python
max -3*y1-1*y2-3*y3

3*y1 + 3*y2 <= 3
-1*y1 <= 1
-7*y1 -4*y2 -1*y3 <= 1
y1 + y2 <= 1

y1,y2!=0
y3>=0
```

Due to complementary slackness conditions, for the optimal solution for the dual

- because the third constraint in the primary problem is loose, it follows that `y3=0`

- Because the second and third variable the primal problem are nonzero, the sacred and third constraints in the dual problem must be tight, so it must hold

```python
-1*y1 = 1
-7*y1 -4*y2 -1*y3 = 1
```


which yields the following solution

```python
y1 = -1
y2 = 3/2
y3 = 0
```

With the cost of `-3*(-1)-1*(3/2)-3*0 = 3-(3/2) = 3/2` the same of the primal, which is why we should expect if both solutions are optimal!

# Exercise Three - Binary Search

## Core Idea

in order to address this minimization problem,instead of trying to directly compute the optimal value, we are going to slowly close in on it by determining if it is below a certain threshold and using binary search 

## Setting Up The Binary Search

Suppose that we are automagically provided with

- an Oracle that can tell us if for a given value `v` there exists some feasible solution `x` with the cost of `v`

- a initial value `m` for which we are sure a solution exists

Because the objective function is continues  and  the region of feasible solutions is a bounded polytope, its image through the objective function must also be continuous interval! in other words, for every `v` in the range `[optimal,m]`,there must be an X that lies within the feasible region and whose objective value is `v`

this enables us to set up a binary search because if at some iteration we know the optimal value lies between `[vl,vh]` and that vh is a feasible value,if we query the Oracle with v inside the interval, if the answer is

- yes, the optimal solution must lie between `[vl,v]`  and `v` satisfies the same property as `vh`

- no, the optimal solution must lie between `[v,vh]`, as otherwise v would lie within the region `[optimal,vh]` and there would be a contradiction!( notice how important the feasibility property for the upper bound is!)


so basically if we are provided with a starting interval satisfying the above conditions, and it follows trivially that `[L,m]` is one such, we can recursively narrow it down using binary search and make the room for error small as we want,e.g. because `L<=optimal`in order to get one `1+e` approximation , we simply continue on until our interval has a length of `Le`and we are done:)

## The Oracle

fortunately, in order to determine the answer of the Oracle for an input value V, we simply need to check if the following system is feasible

```python
Ax <= b
c2_T*x + d2 > 0

c1_T*x + d1 == v*(c2_T*x + d2)
```

which we can easily do by solving the linear program subject to those constraints and with an objective function of 0<sup>T</sup>x

## Obtaining The First Solution

since our problem has an optimal solution it must be feasible as a consequence the following linear program must also be feasible!

```python
min c1_T*x + d1

Subject to

Ax <= b
c2_T*x + d2 > 0
```

and because we knew that the visible region is bounded, this linear program cannot be unbounded and must have an optimal value. We can compute and use this solution `x0` corresponding to this optimal value as a starting point by computing `m = (c1_T*x0 + d1)/(c2_T*x0 + d2)`

of course if this value is greater than `U`,we use that instead!

## Complexity

Scenes we start with an interval of size `O(U-L)` and end up with something less than `O(Le)` our time complexity is going to be `O(log(1/e))` calls to the subroutine for linear programming!








# Exercise Four - Farka's Lemma

consider the linear program P

max 0<sup>T</sup>x

Subject to

```python
Ax<=b
x<>0
```

and its dual D

min b<sup>T</sup>y

with `y>=0`  and A<sup>T</sup>y = 0


the B is feasible then it has an optimal solution with a cost of zero! Since `y=0` is a feasible solution for D, D is either unbounded or has an optimal solution

- if `Ax<=b` has a solution, then P is feasible and has an optimal solution of cost zero. as a consequence the optimally caused 4D is also going to be zero, and thought there can be no nonnegative y, for which it will hold A<sup>T</sup>y = 0 and b<sup>T</sup>y<0!

- on the reverse,if A<sup>T</sup>y = 0 and b<sup>T</sup>y<0, it follows that the DU will problem is clearly not unbounded and thought must have an optimal solution! as a consequence the first problem must also have an optimal solution  and the system of equations `Ax<=b` must be feasible!

# Exercise five - Vertex Cover

## Validity

Because the algorithm only terminates when all the ages have been covered by one of the vertices we have picked, to prove that it yields a valid vertex cover we simply need to show that he terminates. But these follows easily because

- There is a finding number of edges in the graph

- In every step, at least one edge of the graph gets covered, as we pick at least one of its two endpoints

## Upper Bound 

Let S be the cover we produced and led does define the quantities

```python
C = sum{e in E}(c(e))
```

and 

```python
D = sum{v in V}(w(v)-t(v))
```

At the end of the algorithm. Because every time we increase the price of an edge by d, we decrease the cost of two vertices by the same amount, it must hold

```python
D = 2*C 
```

And because for every vertex in the cover must hold `t(v)=0`, these means that

```python
D = sum{v in S}(w(v)-t(v)) + sum{v not in S}(w(v)-t(v)) >= sum{v in S}(w(v)) = w(S)
```

And as a consequence it must follow

```python
Cost of our solution  = w(S) <= 2*C
```

## Lower Bound On Optimal

consider the linear program P

```python
min sum{v in V}(w(v)*x_v)

Subject to

x_v + x_u >= 1 , for every edge (u,v)
x>=0
```

and its dual D

```python
max sum{e in E}(y_e)

Subject to

sum{e in outgoing(v)}(y_e) <= w(v),for every vertex v
y>=0
```

we observe the following

- The optimal solution to the vertex cover problem is a feasible solution for P,( in fact we can express vertex cover as an integer programming version of P,with `x` taking only values 0 or 1)

- the `c(e)` values produced by our algorithm are feasible solution for the dual problem! indeed, whenever we assign a value d to any edge, we also subtract the same value from `t(v)` of both the its points, and `t(v)>=0` at all times!


As a consequence due to the weak duality theorem it must hold

```python
Cost of optimal vertex cover >= sum{e in E}(c(e)) == C
```

The two approximation follows easily, if we also take into account the upper band we found in the previous section!

# Exercise Six - Vertex cover


## Part a

If the photograph is a tree, then we can solve Vertex cover optimally in linear time using dynamic programming

We arbitrarily root the tree from vertex r  and consider a two dimensional state space 

```
d[u,b] = cost of Optima Vertex cover for the subtree with root u  and u belonging to the output cover for that subtree if and only b==true
```

It easily follows


```

d[u,false] = sum{v: v child of u}(d[v,true])

d[u,true] = 1 + sum{v: v child of u}(max(d[v,true],d[v,false]))
```

And we simply solve `max(d[r,true],d[r,false])` via DFS( for each state we also keep track of which children are included in their vertex cover,which can be done with linear space with respect to E)

## Part b - The approximation algorithm

### Validity

firstly we must show that the output of this algorithm is indeed a valid vertex cover. Suppose there exists an edge (u,v) in our original graph and we do not cover it( a.k.a. neither of the two vertices are included in our output). As a consequence,both u and v must be leafs in the DFS tree! but this is not possible because the DFS algorithm would use our uncovered edge to visit v once it visited u! so our output is correct!

### Approximation Ratio





### Tight example 

Consider a chain of length `n=2*k+1`, then our solution is going to pick `n-2` nodes, when the optimal solution is just `k`. For instance if `n=7`, and we denote by `X` the nodes in the cover and by `O` the rest of the nodes

- Our algorithm produces the result

```python
O - X - X - X - X - X - O
```

- where is the optimal solution is

```python
O - X - O - X - O - X - O
```

as a consequence the approximation ratio  is `(2*k-1)/k` the limit of which when K goes to infinite is `2`!


# Exercise Seven -  Lower Bound

we are first going to start by proving that for any set S, the greedy algorithm is going to cover all of its elements with the cost of utmost `H(|S|)*cost(S)` or equivalently `sum{e belongs S}(price(e)) <= H(|S|)*cost(S)`

but this follows easily from the observation that the set S covers all of its elements with the cost of `cost(S)` and if we numerate `e_1,e_2,..,e_k`it's elements that it must hold

```python
price(e_i)<=cost(S)/(k-i+1)
```

and if sum all those values we get

```python
cost(S)*sum{1<=i<=k}(1/(k-i+1)) = H(|S|)*cost(S)
```


now with this in mind,let `OS = {S1,S2,...,Sk}` the sets comprising the optimal solution. The greedy algorithm can cover them with the cost of most

```python
sum{s in OS}(H(|s|)*cost(s)) <=sum{s in OS}(M*cost(s)) = M * sum{s in OS}(cost(s)) = M * OPT
```

where 

```python
M = max{s in OS}(H(|s|)) = H(max{s in OS}(|s|)) <= H(max{s in every S}(|s|))  = H(|S_max|)
```

And as a consequence our solution is within most `H(|S_max|)*OPT`

These upper bound is also tight with the same counterexample as for `H(n)` , that is a single set S0 covering all `n=|S0|` of the elements with the cost of `1+e` and an additional `n` sets each covering a single element of the universe with costs `1/n`,`1/n-1` and so on.



# Exercise Eight - f Approximation Set Cover

## Cardinality

When we were faced with the cardinality vertex Carver problem, we devised a greedy algorithm as follows

```python
Find a maximal matching in G and output the set of matched vertices. 
```

we face as well as the observation that we can reduce vertex to set cover, with edges corresponding to elements of the universe and every vertex being mapped to a set of elements corresponding to the edges let's have it as one of their two endpoints, we can devise the following algorithm

```python
find a maximal set C of elements {u1,u2,...,uk} of U,such that there is no set s that contains more than one of them , and output all sets containing them 
``` 

No element can be left uncovered by the set of sets picked - otherwise such an element could have been added to C, contradicting its maximality. for the same reasons as with Vertex cover, it must hold 

```python
|C|<=Optimal
```

because the optimal solution needs at least on the unique set for any of the elements in C!
take into account that the algorithm picked

```python
number = f1 + f2 + ... +  fk <= f_max * |C|
```

where fi stands for the frequency of i-th element, the f approximation follows


to prove the tightness of these approximation, we need to generalize that tight example with a bipartite graphs that was used for vertex cover

consider the following infinite family of instances where we have  `f` groups of `n` sets and n<sup>f</sup> elements in the universe, with each element being covered by a single set from every group and no two elements being covered by the exact same combination of `f` sets!

In such a case, the optimal solution is to simply output any of the groups of sets, but the greedy algorithm is going to output everything, that is `f` times as many as necessary!

## Weighted

to address their weighted version we are going to utilize the same degree weighted idea for vertex cover, but the degree of the vertices is going to be replaced by the number of elements in every set

### degrees weighted function Lemma

Firstly we are going to generalize the Lemma for the degree weighted functions. Indeed for any degree weighted function `w` mapping sets to integers , let `b` be the constant such that `w(v) = b*deg(v)`, and let C be an
optimal set cover in U. Since C covers all the elements,

```python
sum{c in C}(degree(c)) >= |U|
```

as a consequence since the total weight of all sets through the degree-weight functionis going to be

```python
sum{c in S}(degree(c)*b) = sum{u in U}(b*frequency(u)) <= b * f * |U|
```

`w(S) <= f*OPTIMAL`

### The Algorithm

The algorithm proceeds in layers or iterations, in each of which

- we remove all empty sets, we call them `D_i`

- we compute the largest degree weight function over the remaining sets, a.k.a. we compute the largest constant would not make us overshoot the actual weights `c = min(w(s)/degree(s))`

- We add all the sets that are tight( those that have a residual weight function `w'(s) = w(s) - t(s)` value of zero) into the cover. we call them `W_i`

- remove all the elements that are covered by `W_i` from all of the sets and continue their repetitions using the residual weight function, until we are out of sets

### Validity

because

- at the end of the algorithm there are no elements left

- elements get removed only when one of the sets from `W_i` covers them

If we can show that the algorithm terminates, then we are done!

But the algorithm has to terminate because

- in every iteration at least one set is picked and as a consequence at least one element gets covered

- there is only a finite number of elements in the universe

the algorithm has to terminate, yielding valid correct set cover!


### Approximation

now for every set `s` in our cover `C` there must be `J` such that `s belongs W_j`  and its weight can be decomposed in the following manner
 
```python
w(s) = sum{i<=j}(t_i(s))
```

and for every set that is not included in our cover `C` there must be `j` `s belongs D_j` and a lower bound on its weight is 

```python
w(s) >= sum{i<=j}(t_i(s))
```

observing that the intersection of the optimal solution with the available sets at every layer has to be a valid set cover for that layer, from the previous lemma we obtain `t_i(intersection(C,U_i)) <= f*t_i(intersection(Optimal,U_i))` and finally

```python
w(C) = sum{i}(t_i(intersection(C,U_i))) <= f*sum{i}(t_i(intersection(Optimal,U_i))) <= f*w(Optimal)
```

### Tight Example

we are going to reuse the same example we used for the cardinality version but this time with unit weights and we are done!


# Exercise Nine - Metric Tsp Path Upper Bound

Now this is interesting, because even though both approximation ratios are functions of c<sub>s,t</sub>, because one of them is increasing and the other is decreasing and were taking their minimum, their combined approximation ratio is a constant number!

In particular if we have due functions `a,b of x` wish a increase and b decreasing and it holds `a(y)==b(y)` for some y , then if we define `d(x) = min(a(x),b(x))` it would hold

```python
max(d(x)) = d(y)
```

we can clearly see these because if

- `x<y` then `a(x)<a(y)<b(x)`and as a consequence `d(x)<d(y)`

- `x>y` then `a(x)>a(y)>b(x)`and as a consequence `d(x)<d(y)`

in our case, solving `2*optimal-c==(3/2)*optimal+(1/2)*c` yield `c=(1/3)*optimal` for an approximation ratio of `(5/3)*optimal`

In essence, when one of the algorithms is performing very poorly,the other is performing better!

