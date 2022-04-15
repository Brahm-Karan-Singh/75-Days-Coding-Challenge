/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
    if(head == NULL)
		return head;
	
	Node* curr = head;
	while(curr != NULL)
	{
		if((curr -> next != NULL) && (curr -> data == curr -> next -> data)){
			Node* nextKaNext = curr -> next -> next;
			Node* temp = curr -> next;
			temp -> next = NULL;
			delete(temp);
			curr -> next = nextKaNext;
		}else{
			curr = curr -> next;
		}
	}
	
	return head;
}