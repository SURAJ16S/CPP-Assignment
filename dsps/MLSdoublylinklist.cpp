/*
doubly link list : it is a type of linked list in which the data is store in a node . a node is consist of three fields 1st is prev ,in which address of previous node is store , then data field where the actual address is stored and 3 rd is address of next node.


>Previous Pointer in Class Declaration:

MLS *next, *prev; // Added prev pointer for doubly linked list
This line declares the prev pointer in the class to maintain a reference to the previous node, enabling bidirectional traversal.

>Setting Previous Pointer in Accept Function:

newnode->next = newnode->prev = NULL; // Initialize both next and prev pointers
This line initializes both next and prev pointers to NULL when a new node is created.

>Updating Previous Pointer in Accept Function:


newnode->prev = temp; // Link the previous node to the new node
tail = newnode; // Update the tail pointer to the new node
These lines update the prev pointer of the new node to point to the current last node (temp), and set the tail pointer to the new node.

>Reverse Print in Display Function:

temp = tail;  // for reverse print
while(temp != NULL) {
    cout << temp->title << "\t" << temp->artist << "\t" << temp->trackid << endl;
    temp = temp->prev;
}

*/