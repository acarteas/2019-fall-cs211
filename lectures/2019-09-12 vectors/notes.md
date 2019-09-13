# Vectors
Recall from yesterday,
* A vector is a dynamically expanding array
* (common feature with many data structures) Vectors distinguish between phsyical size and logical size
	* Physical size: total number of allocated memory blocks
	* Logical size: total number of *used* blocks
* When logical size equals physical size, we need to create a new array to house our data
	* Cost: O(N)
* Desing concern: How can we efficiently minimize the frequency of resizes?
	* Tradeoff between allocating too much memory and resizing
	* General consensus these days is that whenever you resize a vector, the new physical size will be 2x the previous physical size
	* To conserve memory a good vector will also shrink when it is less than half full
