// ============================================================
// PURPOSE:  This project implements basic linked list.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

template <class TYPE, class KTYPE>
class List;
template <class TYPE>
class Iterator;

// ********************************************************************
// Declaration of node class
// ********************************************************************
template <class TYPE>
class Node
{
private:
	TYPE data;
	Node<TYPE> *next;
public:
	Node<TYPE>(TYPE dt): data(dt){};
	friend class List;
	friend class Iterator;
};

// *********************************************************************
// Declaration of list class
// *********************************************************************
template <class TYPE, class KTYPE>
class List                          // maintain an ordered list of items
{
private:
	Node<TYPE> *head;    		  	// pointer to the first node
    Node<TYPE> *rear;            	// pointer to the last node
    int count;         				// the number of nodes
public:
	List(void);						// Constructor for creating an empty list
	~List(void);					// Destructor
	Iterator<TYPE> begin();			// get head of the list
	Iterator<TYPE> end();			// get rear of the list
	bool insert(Iterator<TYPE> &iter, const TYPE &dataIn);
 									// insert a new node after node *iter
	void remove(Iterator<TYPE> &iter, TYPE &dataOut);
									// delete the node next to *iter, dataOut = iter.curr->data
 	bool search(Iterator<TYPE> &iter, const KTYPE &key);
									// search for the node containing a value equal to key
    bool emptyList(void){ return ( count == 0 ); }
									// test if the list is empty
	bool fullList(void);			// test to see if the list is full; that is,
      								// no more memory to add an additional node
	int listCount(void) { return count; }
									// return the number of nodes
	void traverse(void);			// traverse list displaying keys
	friend class Iterator;
};

template <class TYPE, class KTYPE>
List<TYPE, KTYPE>::List(void)
{
	head = NULL;
	rear = NULL;
	count = 0;
}

template <class TYPE, class KTYPE>
List<TYPE, KTYPE>::~List(void)
{
	Node<TYPE> *deletePtr;	// local pointer
	while( head != NULL )	// Continue to delete nodes until the list is empty
	{
		deletePtr = head;
		head = head->next;
		delete deletePtr;
	}
	count = 0;
}
template <class TYPE, class KTYPE>
Iterator<TYPE> List<TYPE, KTYPE>::begin()
{
	Iterator<TYPE> iter;
	iter.curr = head;
	iter.prev = NULL;
	return iter;
}

template <class TYPE, class KTYPE>
Iterator<TYPE> List<TYPE, KTYPE>::end()		
{
	Iterator<TYPE> iter;
	iter.curr = NULL;
	iter.prev = rear;
	return iter;
}

template <class TYPE, class KTYPE>
bool List<TYPE, KTYPE>::insert(Iterator<TYPE> &iter, const TYPE &dataIn)
// -------------------------------------------------------------------
// Purpose: This function inserts a new node either at the beginning
//          or after the node *iter.prev.
// -------------------------------------------------------------------
{
	Node<TYPE> *pNew;		// Create a new node with pNew pointing to the object.
	if (!(pNew = new Node<TYPE>(dataIn)))
   		return false;

	if (iter.prev == NULL)	// insert to front or into an empty list
	{
		pNew->next = head;
		head = pNew;
	}
	else					// non-empty list
	{
		pNew->next = iter.curr;
		iter.prev->next = pNew;
	}

	if (pNew->next == NULL)
   		rear = pNew;

	iter.curr = pNew;
	++count;
	return true;
}

template <class TYPE, class KTYPE>
void List<TYPE, KTYPE>::remove(Iterator<TYPE> &iter, TYPE &dataOut)
// -------------------------------------------------------------------
// Purpose: This function deletes node *iter.curr
// -------------------------------------------------------------------
{
	dataOut = iter.curr->data;	// Return the data value of the node to be deleted.
	if (iter.prev == NULL)		// delete the first node
		head = iter.curr->next;
	else
		iter.prev->next = iter.curr->next;

	if (iter.curr->next == NULL)
   		rear = iter.prev;

	delete iter.curr;
	if (iter.prev == NULL)
		iter.curr = head;
	else
		iter.curr = iter.prev->next;
	--count;
	return;
}

template <class TYPE, class KTYPE>
bool  List<TYPE, KTYPE>::search(Iterator<TYPE> &iter, const KTYPE &key)
// ------------------------------------------------------------------
// Purpose: Search for the existence of a node containing a value
//          equal to key.
// ------------------------------------------------------------------
{
	// Initialize iterator iter.
	iter = begin();

	for (int i = 1; i <= count; i++)
	{
		if (key == iter.curr->data.key)
			return true;	
   		iter.prev = iter.curr;
		iter.curr = iter.curr->next;
	}
	return  false;
}

template <class TYPE, class KTYPE>
bool List<TYPE, KTYPE>::fullList()
{
	Node<TYPE>* pNew;
	if (pNew = new Node<TYPE>)  // successful memory allocation
	{
		delete pNew;
		return false;
	}
	return true;
}

template <class TYPE, class KTYPE>
void  List<TYPE, KTYPE>::traverse(void)
{
	Node<TYPE> *pNext = head;

	// Display the keys from each node of the linked list.
	while(pNext)
	{
		cout << pNext->data.key << " | " << pNext->data.info << endl;
		pNext = pNext->next;
	}
	cout << endl;
}

// *********************************************************************
// Declaration of iterator class
// *********************************************************************

template <class TYPE>
class Iterator
{
private:
	Node<TYPE> *curr;    		  	// pointer to the current node
    Node<TYPE> *prev;				// pointer to the previous node
public:
	Iterator();						// constructor
	bool operator ==(Iterator<TYPE> &Ir);
	bool operator !=(Iterator<TYPE> &Ir);
	void operator ++();				// advance iterator - prefix
	void operator ++(int);			// advance iterator - postfix
	TYPE getdata();					// return data of *curr
	Node<TYPE> operator *();		// return node *curr for a friend function of Node
	friend class List;
};

template <class TYPE>
Iterator<TYPE>::Iterator()
{
	curr = NULL;
	prev = NULL;
}

template <class TYPE>
bool Iterator<TYPE>::operator ==(Iterator<TYPE> &Ir)
{
	return ((curr == Ir.curr)&&(prev == Ir.prev));
}

template <class TYPE>
bool Iterator<TYPE>::operator !=(Iterator<TYPE> &Ir)
{
	return !((curr == Ir.curr)&&(prev == Ir.prev));
}

template <class TYPE>
void Iterator<TYPE>::operator ++()
{
	if (curr != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
}

template <class TYPE>
void Iterator<TYPE>::operator ++(int)
{
	if (curr != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
}

template <class TYPE>
TYPE Iterator<TYPE>::getdata()
{
	return curr->data;
}

template <class TYPE>
Node<TYPE> Iterator<TYPE>::operator *()
{
	return *curr;
}

// main function
struct TestNode
{	
   		int key;
		string info;
};

void main()
{
	TestNode T;
	List<TestNode, int> L;
	Iterator<TestNode> iter;
	iter = L.begin();

	cout << "Enter a key(-1 to stop): ";
   	cin >> T.key;
	while (T.key > 0)
	{
		cout << "Enter info:";
   		cin >> T.info;

		int result = L.insert(iter, T);
   		iter++;				// or ++iter;
		cout << "Enter a key(-1 to stop): ";
   		cin >> T.key;
	}

	L.traverse();
	iter = L.begin();
	while (iter != L.end())
	{
		cout << "data: " << iter.getdata().key << " " << iter.getdata().info << endl;
		iter++;
	}

	int key;
	cout << "Enter a key for search: ";
	cin >> key;

	if (L.search(iter, key))
		cout << "found data: " << iter.getdata().key << " " << iter.getdata().info << endl;
	else
		cout << "key not found!" << endl;


	//*************

	int cnt = 0;
	TestNode T2;
	List<TestNode, int> L2;
	Iterator<TestNode> iter2;
	

	cout << "Enter a key(-1 to stop): ";
   	cin >> T2.key;
	while (T2.key > 0)
	{


		cout << "Enter info:";
   		cin >> T2.info;

		iter2 = L2.begin();


		//------------
			
			if(L2.listCount()==0)
				{
					L2.insert(iter2, T2);
				}
            else
			{
				while(iter2 != L2.end())
				{
					if(T2.key > iter2.getdata().key)
						iter2++;
					else
						break;
				}
				L2.insert(iter2, T2);

			}
			//-----------------



		
		cout << "Enter a key(-1 to stop): ";
   		cin >> T2.key;
	}

	L2.traverse();
	iter2 = L2.begin();
	while (iter2 != L2.end())
	{
		cout << "data: " << iter2.getdata().key << " " << iter2.getdata().info << endl;
		iter2++;
	}

	cout << "Enter a key for search: ";
	cin >> key;

	if (L2.search(iter2, key))
		cout << "found data: " << iter2.getdata().key << " " << iter2.getdata().info << endl;
	else
		cout << "key not found!" << endl;
}
