#include <iostream>
#include "IntList.h"

using namespace std;

   /* Initializes an empty list.
   */
IntList::IntList()
{
    head = 0;
}

   /* Inserts a data value to the front of the list.
   */
void IntList::push_front(int value)
{
    IntNode *temp = new IntNode(value);
    temp->next = head;
    head = temp;
}

   /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
ostream & operator<<(ostream &out, const IntList &rhs)
{
   if (rhs.head == 0)
   {
      return out;
   }
   else
   {
      operator<<(out, rhs.head);
   }
   
   return out;
}

   /* Returns true if the integer passed in is contained within the IntList, 
      otherwise returns false.
   */
bool IntList::exists(int value) const
{
    if (head == 0)
    {
       return false;
    }
    else if (head->data == value)
    {
       return true;
    }
    
    return exists(head->next, value);
}
   /* Helper function that returns true if the integer passed in is contained within
      the IntNodes starting from the IntNode whose address is passed in,
      otherwise returns false.
   */
bool IntList::exists(IntNode *node, int value) const
{
    if (node == 0)
    {
       return false;
    }
    else if (node->data == value)
    {
       return true;
    }
    
    return exists(node->next, value);
}
/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream & operator<<(ostream &out, IntNode *begin)
{
   if (begin == 0)
   {
       return out;
   }
   else if (begin->next == 0)
   {
       out << begin->data;
   }
   else
   {
       out << begin->data << " " << begin->next;
   }
   
   return out;
}