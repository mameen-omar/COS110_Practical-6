#include "xAxis.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

xAxis::~xAxis()
{
	if(head->next == 0)
	{
		delete head;
		head = 0;
	}

	else if(!head)
	{
		head = 0;
	}

	else
	{
		node* nodePtr = head;
		node* nodePtr2 = 0;

		while(nodePtr != 0)
		{
			nodePtr2 = nodePtr;

			nodePtr = nodePtr->next;

			delete nodePtr2;
		}

		head = 0;
	}
}

xAxis::xAxis()
{
	head = 0;
}
/* constructor: length is the length of the x-axis
					n is an array of labels to describe the values in the x-axis
					v is an array of values for each label

If the value is negative then store it as 0.	*/
xAxis::xAxis(int length, string* n, double* v)
{
	for(int x=0; x<length; x++)
	{
		node *newNode = new node;

		node *nodePtr = 0;

		if(v[x] < 0)
		{
			newNode->value = 0;
		}

		else
		{
			newNode->value = v[x];
		}
		
		newNode->label = n[x];
		newNode->next = 0;

		if(!head)
		{
			head = newNode;
		}

		else
		{
			nodePtr = head;

			while(nodePtr->next)
			{
				nodePtr = nodePtr->next;
			}

			nodePtr->next = newNode;
		}
	}
	

}

	/*appends one node to the linked list with the value v and the label n
If the value is negative then store it as 0.*/																																									
void xAxis::extend(double v,string n)
{

		node *newNode = new node;

		node *nodePtr = 0;

		if(v < 0)
		{
			newNode->value = 0;
		}

		else
		{
			newNode->value = v;
		}
		
		newNode->label = n;
		newNode->next = 0;

		if(!head)
		{
			head = newNode;
		}

		else
		{
			nodePtr = head;

			while(nodePtr->next)
			{
				nodePtr = nodePtr->next;
			}

			nodePtr->next = newNode;
		}

}
	


/*removes the last node from the linked list*/
void xAxis::shorten()
{
	node* nodeDelete = 0;

	node* newLastNode = 0;

	if(!head)
	{
		return;
	}

	else if(head->next == 0)
	{
		delete head;
		head = 0;
	}
	else
	{
		nodeDelete = head;

		while(nodeDelete->next)
		{
			newLastNode = nodeDelete;
			nodeDelete = nodeDelete->next;
		}

		delete nodeDelete;
		newLastNode->next = 0;
	}

}

/*removes the node with the label n from the linked list*/
void xAxis::deleteNode(string n)
{
	node * nodePtr = 0;
	node * prevNode = 0;

	if(!head)
	{
		return;
	}

	if (head->label == n)
      {
          nodePtr = head->next;
          delete head;
          head = nodePtr;
      }

      else
      {
          // Initialize nodePtr to head of list
          nodePtr = head;

          // Skip all nodes whose value member is
          // not equal to num. 
          while (nodePtr != 0 && nodePtr->label != n)
         {
              prevNode = nodePtr;
              nodePtr = nodePtr->next;
          }

          // If nodePtr is not at the end of the list,
          // link the previous node to the node after
          // nodePtr, then delete nodePtr.
          if (nodePtr)
          {
              prevNode->next = nodePtr->next;
              delete nodePtr;
          }
      }


}
	
/*increases the value of the node with label n by val*/																																																																																	
void xAxis::increaseValueBy(string n,double val)
{
	node * nodePtr = 0;

	if(!head)
	{
		return;
	}

	else
	{
		nodePtr = head;

		while(nodePtr != 0)
		{
			if(nodePtr->label == n)
			{
				nodePtr->value = (nodePtr->value) + val;
			}

			nodePtr = nodePtr->next;
		}
	}

}
	
/*decreases the value of the node with label n by val

If the value becomes negative then store it as 0.*/

void xAxis::decreaseValueBy(string n,double val)
{

	node * nodePtr = 0;

	if(!head)
	{
		return;
	}

	else
	{
		nodePtr = head;

		while(nodePtr != 0)
		{
			if(nodePtr->label == n)
			{

				nodePtr->value = nodePtr->value - val;

				if(nodePtr->value < 0)
				{
					nodePtr->value = 0;
				}

			}

			nodePtr = nodePtr->next;
		}
	}

}

	
/*the node which has the label o must be changed so that it has the label n*/
void xAxis::changeLabel(string o,string n)
{
	node * nodePtr = 0;

	if(!head)
	{
		return;
	}

	else
	{
		nodePtr = head;

		while(nodePtr != 0)
		{
			if(nodePtr->label == o)
			{
				nodePtr->label = n;
			}

			nodePtr = nodePtr->next;

		}

	}
}


/*displays all the nodes in a " label    value " newline  format.

	ie:
	one   1.97
	two   2.8076
	three   3.21
	*/
void xAxis::display()
{
	node* nodePtr = 0;

	if(!head)
	{
		return;
	}

	else
	{
		nodePtr = head;


		while(nodePtr->next)
		{
			cout << nodePtr->label << " " << nodePtr->value <<endl;
			nodePtr = nodePtr->next;
		}

		cout << nodePtr->label << " " << nodePtr->value <<endl;
	}
}