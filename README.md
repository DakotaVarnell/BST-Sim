# BST-Sim
-A program in C++ that simulates a binary search tree using an array



NOTES
#############################################################################
We will be utilizing a one dimensional array named BST[] that can contain a 
maximum of 100 nodes as specified by the hard coded value, could easily be 
modified to accept dynamic user input. We begin by setting our root node to
-1 which functionally sets it to NULL. The functions are implemented in our
main and the values are hard coded in but could easily be modified to 
accomodate for dynamic user input. 
############################################################################



FUNCTION DESCRIPTION
###########################################################################

Search
---------------------------------------------------------------------------
We set our found boolean to false to give us a default value that allows the 
search to begin. We then assign our variable p to the current root index. 
We implement a while loop that will continue iterating while found is not
equal to 1/true. It wil then display the index and the value stored at said
index. If the value at index p is equal to our x value we found the value w
we were looking for, so we set our found condition to 1/true. We then will 
return the index stored in p. If the value at index p is not equal to x we 
will then begin by determining if the data at p is greater than or less than 
x. If it is greater we will send our search down the right side of the BST 
by multiplying p by 2. If the value at p is less than x we will send our 
search down the left side of our BST by mulitplying p by 2 then adding 1. 
Even p values are representative of the right side of the BST, Odd p values
are representative of the left side of the BST. 
---------------------------------------------------------------------------


Max
---------------------------------------------------------------------------
We begin by setting our p value equal to our root, and our parent to 1, 
and again our found boolean to false. We use a while loop to iterate while 
found is not equal to true. We then set the parent equal to the right side of
our BST, because our greatest value will always be on the right. We then 
compare every value on the right side of our BST to each other to find the 
end of our BST which is the maximum value. Once we find that last rightmost
value we will have found our max and return it to our main. 
---------------------------------------------------------------------------


Min
---------------------------------------------------------------------------
We then set all of our values to the same values that we used in the Max 
function. The difference between these two functions is that we will be 
going down the left side of our BST to find our minimum value. We begin with
another while loop that will continue iterating until we find our minimum value. 
We then check if our value at p is greater than the parent value and if our 
parent data is equal to 0, if those conditions are true we've found our min and
change our values accordingly. Otherwise we continue down the left side of our 
BST by multiplying our p value by 2. We then display all values and return the 
min to our main. 
----------------------------------------------------------------------------



Print BST
----------------------------------------------------------------------------
We iterate through a for loop starting at index 1 and use a conditional to
only display the values whose data is not equal to 0. 
----------------------------------------------------------------------------


Insert
----------------------------------------------------------------------------
We begin by checking if our BST is empty and if so, the value at index 1 is 
equal to the x value passed into the function. Else, we will use a while loop
to iterate until we've found our value, we then compare whether or not the passed
in value is greater than or less than the values before it, and if so we will 
continue through the BST until we find the proper placement for the passed in
value. If any of the previous conditions are found to be true, our while loop
will stop. 
-----------------------------------------------------------------------------


Remove
-----------------------------------------------------------------------------
We begin by setting all our variables to the values they were set to within
the min/max functions. We then use another while loop to iterate until found
is equal to true. We check if the value at index p is equal to the passed
in argument to be deleted. If so we have found our element to be deleted, we 
then set it's data equal to 0 to symbolize it's deletion. We wil check three 
other cases. We will then check to see if the node we plan on deleting has 
any parent or child nodes, if so we will change their "pointers" accordingly. 
Once we find our value to delete we will stop our while statement and make sure
that our parent and child nodes have been accounted for. This is the most basic
function of the remove function, if you would like a more line-by-line and 
detailed explanation, check the actual code for comments, where the explanation
is more concise. 
-------------------------------------------------------------------------------





###########################################################################
