## Project TODO List

### Recursive Descent Parser
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


Table Based Grammar:

\<E\> → \<T\>\<A\>  
\<A\> → +\<T\>\<A\>|-\<T\>\<A\>|ε  
\<T\> → \<F\>\<M\>   
\<M\> → *\<F\>\<B\>|/\<F\>\<B\>|ε   
\<F\> → \<E\>|\<Number\>  
