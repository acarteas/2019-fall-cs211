# Milestone 6
It is common for programs to support saving and opening binary files (e.g. DOC, PDF, etc.).  In this milestone, you will use hash tables and priority queues to create a custom binary files.  The algorithm employed by this milestone is inspired by Huffman Coding Trees, which the book covers in Section 5.4.  While it is not a requirement for you to read that section, you may get more out of the milestone if you do read its contents.

## Binary Format
As mentioned previously, our binary format is based on Huffman Coding Trees, which is frequently used to compress files.  Indeed, Huffman Coding Trees are used to create ZIP files.  Huffman Coding Trees work by replacing common strings with shorter strings, thereby saving space.  Typically, this shorter sequence is represented using a binary number.  Thus, the most common string in a file would receive the designation "0", the 2nd most popular "10", 3rd "11", 4th "100", 5th "101" and so on (*HINT* to get these numbers, try applying code that converts decimal to binary.  Even better, write your own!).  Here's how to perform it on this milestone:

1.	Record the frequency of each word in a your editor.  Ignore empty lines and spaces.  *OPTIONAL:* Rather than doing a word frequency distribution, do a character frequency distribution instead.
2.	Use the frequency recorded in step #1 to build a Max-Heap.  
3.	Removing items from the heap in order of importance, assign each word a unique "binary" string value.  
4.	Write to the output file the "binary" representation of the file.
5.	Write the "binary" mapping to a separate file.

## Example
Using the algorithm above on the string "berries apples berries apples pears apples" (42 chars)

1.	The frequencies of the words are berries: 2, apples: 3, pears: 1
2.	The removal sequence from the heap would thus be: apples, berries, pears
3.	The "binary" string assigned to each word would therefore be apples: "0", berries: "1", pears: "00".
4.	The final compressed string would therefore be "1 0 1 0 00 0" (12 chars) for a compression ratio of 71%.

## Decompression Algorithm (bonus points)
For bonus points, you can try implementing the decompression algorithm, which is merely the inverse of the compression algorithm:

1.	Load mapping file: Load each mapped item (e.g. apples: 0) into a hash table.
2.	Load compressed file: For each string in the file, find the correct mapping (e.g. 0 -> apples), replace compressed version with uncompressed version

## File Format
To maintain consistency across student submissions, please ensure that the encoded files have the following names: &lt;file_name&gt;.compressed.txt and &lt;file_name&gt;.codes.txt.  Thus, if the user types in "happy" as their save file name, your program would generate the files "happy.compressed.txt" and "happy.codes.txt."  

## Grading
This assignment is worth 100 points.  Your grade will be based on the following:
* Regular, appropriately sized github checkins (no single-line checkins, no 1000+ line checkins)
* Lab progress checkins
* Tracking progress on your github project board and github issue tracker
* Maintaining a design diary for this assignment
* Completing the project / making reasonable progress

## Due Date
This assignment is due midnight, November 15, 2019.  You will turn in your project by checking your code into github.  Next, create an GIF walkthrough of your program using [LICEcap](https://forum.lumberhacks.org/viewtopic.php?f=10&t=9).  Upload this image to your repository and put a link to the image in your reflection. 
