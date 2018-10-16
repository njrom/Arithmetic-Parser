
## Recursive Descent Parser

#### Todo's 
- [x] Build a Tree Printer for debugging
- [x] Populate category Functions

### Productions for recursive-descent parser
\<E\>  →  \<T\>\<A\>  
\<A\> → + \<T\>\<A\> | - \<T\>\<A\> | ε   
\<T\> →  \<F\>\<M\>  
\<M\> → *\<F\>\<M\> | / \<F\>\<M\> | ε   
\<F\> → \<E\> | \<N\>  
\<N\> → \<D\>\<P\>  
\<P\> → (\<N\>) | ε  
\<D\> → 0|1|2|3|4|5|6|7|8|9  


## Table-Driven Parser

#### Todo's
-[x] Implement Stack 
-[ ] Code Parcing algorithm
-[ ] Build Calculator to evalulate parse tree 

### Productions for Table-Driven parser:

\<E\> → \<T\>\<A\>  
\<A\> → +\<T\>\<A\>|-\<T\>\<A\>|ε  
\<T\> → \<F\>\<M\>   
\<M\> → *\<F\>\<B\>|/\<F\>\<B\>|ε   
\<F\> → \<E\>|\<Number\>  
