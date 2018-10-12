## Productions for recursive-descent parser
\<E\>  -->  \<T\>\<AS\>  
\<AS\> --> + \<T\>\<AS\> | - \<T\>\<AS\> | ε   
\<T\> -->  \<F\>\<MD\>
\<MD\> --> *\<F\>\<MD\> | / \<F\>\<MD\> | ε   
\<F\> --> \<E\> | \<N\>  
\<N\> --> \<D\>\<PN\>  
\<PN\> --> \<N\> | ε  
\<D\> --> 0|1|2|3|4|5|6|7|8|9  


## Project TODO List

### Recursive Descent Parser
- [ ] Build a Tree Printer for debugging
- [] Populate category Functions
