# Ternary-Trees
Implementing Data Structure in C++: Ternary Trees

This program takes one argument, n, and reads n integersinto an empty ternary tree;
It then prints the tree in symmetric order, using parenthesis to showcase the children/parent relationship

the pearl program randGen.pl can be used to generate random numbers with a seed; 
to run this progrma with randGen.pl, pipe in the output of the pearl program into the ternary executable with
  randGen.pl 49 10000 | ternary n

Each node in a non-empty ternary tree is allowed to have either 1 or 2 values. If a node has 2 values, say a < b, then it is easy to use them to choose among three directions to descend below that node given a probe value p. There are three possibilities: p ≤ a, a < p ≤ b, b < p. But what if a node only has 1 value, say a? If you are inserting p, make p the other value, making sure that you sort the two values with the lower one first. In other words, only two-valued nodes can have children.

To test this idea, write a program called ternary that takes n as a parameter, reads in n integers (one per line; there may be duplicates), inserts them into an initially empty ternary tree, and then prints the tree in symmetric order (inorder), with parentheses showing the children of a node. That is, if a node contains values a and b, print it as

(left child) a (middle child) b (right child)
If any child is empty, just leave out the parentheses. For instance, if I insert the following 20 integers into an initially empty ternary tree:
4 6 4 18 8 2 14 7 15 5 19 12 15 5 9 0 17 2 2 19 
the output is
((0 (2) 2) 2 4) 4 (5 5) 6 ((7) 8 ((9 12) 14 (15) 15 (17)) 18 (19 19))

