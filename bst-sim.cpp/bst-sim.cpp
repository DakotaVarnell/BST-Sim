//Dakota Varnell
//Binary Search Tree Simulator using an array
//07/21/2021


#include <iostream>
#include <iomanip>

using namespace std;

//array to simulate BST
int BST[100];//size 100 because worst case scenario for insertion is 0(n^2) which is (10^2) = 100
int root = 1;

//Function Defintions
int search(int x)//function to search for a value through the BST
{
	bool found = false;//bool to determine whether or not the value has been found
	int p = root;//assigns variable p to the root index of 1


	cout << "Path Traveled: \n";//displays the title of the function 

	while (found != true)//loop that continues executing until the found condition is true
	{
		cout << setw(3) << p;//displays the index 
		cout << setw(5) << BST[p] << endl;//displays the value stored at index of p

		if (BST[p] == x)//if the value at index p is equal to value x 
		{
			found = true;//we found the value so found should be true
			cout << "\n";//formatting
			return p;//returns the value of p
		}
		else//if the value at p is not equal to x
		{
			if (BST[p] > x)//if the value at p is greater than the value of x
			{
				p = p * 2;//we go down the left side of the BST
			}
			else//if the value at p is smaller than x
				p = (p * 2) + 1;//we traverse down the right side of the tree
		}
	}
}

int max()//function to search for and return the maximum value
{
	int max = 0;//variable max
	int p = root;//sets p equal to the root index of 1
	int parent = 1;//sets the parent variable to a value to initialize
	bool found = false;//sets found to false

	while (found != true)//loops until found is true
	{
		parent = (p * 2) + 1;//sets parent equal to the right side of index p

		if (BST[p] > BST[parent])//if the value at index p is greater than value at index parent
		{
			max = BST[p];//the value at index p is now the max value
			found = true;//found is now true, stop loop
		}
		else//if the value at index p is less than the value of index parent
		{
			p = (p * 2) + 1;//p is now equal to its right side, allowing us to traverse the right side of the BST
		}
	}

	cout << "Max: " << max << endl;//displays the maximum value 
	return max;//returns maximum value
}

int min()//function to find the minimum value
{
	int min = 0;//initialize value of min
	int p = root;//intialize p to root index
	int parent = 1;//initalize parent
	bool found = false;//set found to false

	while (found != true)//loops until found is true
	{
		parent = (p * 2);//sets parent equal to the index to the left of current index p

		if (BST[p] > BST[parent] && BST[parent] == 0)//if the value at index p is greater than the value at index parent, and the index at parent is 0
		{
			min = BST[p];//value at index p is now the minimum
			found = true;//we found the value
		}
		else//the other option of the above if
		{
			p = (p * 2);//we change p to the index of the left side of index p
		}
	}

	cout << "Min: " << min << endl;//displays the minimum value
	cout << "\n";//formatting
	return min;//returns minimum value
}

void printBST()//function to print out the values of the BST
{
	int p = root;//sets index p = root index


	cout << "Index  Data" << endl;//displays the title of the function display

	for (int i = 1; i < 100; i++)//loop to traverse the BST
	{
		if (BST[i] != 0)//only displays the values and indexes that contain data other than NULL
		{
			cout << setw(3) << i;//displays index
			cout << setw(5) << BST[i] << endl;//displays data at index
		}
	}

	cout << "\n";//formatting

}

void insert(int x)
{
	int p = 1;//sets variable p = 1/root
	bool found = false;//bool to determine when we find the value

	if (BST[1] == 0)//if BST is empty
	{
		BST[1] = x;
	}
	else
	{
		while (found != true)//loop to stop when the item is found
		{
			if (BST[p] > x)//if the element x is less than the current data at index p
			{
				if (BST[p] != 0)//if the index is full, keep going
				{
					p = p * 2;
				}
				else//if index is empty, assign the x to the BST at index p, then make found true
				{
					p = p * 2;
					BST[p] = x;
					found = true;
				}
			}
			else//if x is greater than the data at current index of p
			{
				if (BST[p] < x)//possibly unecesarry if statement
				{
					if (BST[p] != 0)//if the index is full, continue moving
					{
						p = (p * 2) + 1;//statement to make the index on the right side of the BST
					}
					else//if it is not full, then assign the data x to index p and change found to true
					{
						BST[p] = x;
						found = true;
					}
				}
			}
		}
	}
}




void remove(int x)
{
	bool found = false;//bool to determine when we found the value of x
	int p = root;//sets p equal to root index
	int parent = 1;//sets parent equal to 1

	while (found != true)//loop until we find value
	{
		if (BST[p] == x)//if the value at index p is equal to x
		{
			if (BST[p * 2] == 0 && BST[(p * 2) + 1] == 0)//if the current node has no left or right side, case1
			{
				found = true;//we found the element
				BST[p] = 0;//delete this leaf
			}
			else if (BST[p * 2] != 0 && BST[(p * 2)] + 1 == 0)//if the left side contains a value and the right side doesnt contain a value, case2 pt1
			{
				parent = p / 2;//sets parent equal to the parent of current index p

				if (x < BST[parent])//if x is smaller than the current value at parent node
				{
					BST[parent * 2] = BST[p * 2];//we set the left side of parent equal to the left side of p node
				}
				else
					BST[(parent * 2) + 1] = BST[p * 2];//else we set the right side of our parent node equal to the left side of our p node

				BST[p] = 0;//delete current node
				found = true;//we found the element so stop loop
			}
			else if (BST[p * 2] == 0 && BST[(p * 2)] + 1 != 0)//ifthe left side of node p contains nothing and the right side contains a value, case2 pt2
			{
				if (x < BST[parent])//if x is less than the value stored at the parent node
				{
					BST[parent * 2] = BST[(p * 2) + 1];//we set the left side of the parent node equal to the right side of the p node
				}
				else
					BST[(parent * 2) + 1] = BST[(p * 2) + 1];//else we set the right side of the parent node equal to the right side of the p node

				BST[p] = 0;//delete p node
				found = true;//we found our value, stop loop
			}
			else//third case
			{
				BST[p] = BST[(p * 2) + 1];//the value at index p should be set to the value of the right side of node p
				BST[(p * 2) + 1] = 0;//we delete the right side of the node p
				found = true;//we found the value so stop the loop
			}

		}
		else//if index p value is not equal to the value of x
		{
			if (BST[p] > x)//if index p value is greater than x
			{
				p = p * 2;//we go down the left side of the BST
			}
			else
				p = (p * 2) + 1;//else we go down the right side of the BST
		}
	}

}



int main()
{
	insert(5);
	insert(8);
	insert(3);
	insert(1);
	insert(4);
	insert(9);
	insert(18);
	insert(20);
	insert(19);
	insert(2);
	printBST();
	max();
	min();
	search(3);
	search(18);
	search(19);
	remove(19);
	printBST();
	remove(2);
	printBST();
	remove(8);
	printBST();
	remove(3);
	printBST();
	remove(5);
	printBST();
}
