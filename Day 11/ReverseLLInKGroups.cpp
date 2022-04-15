/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


Node* kReverse(Node* head, int k) {
    // Base case
// 	if the node is pointing to null then how can we reverse it 
    if(head == NULL)
		return NULL;
	
// 	Step 1- Reverse first k nodes 
	Node* prev = NULL;
	Node* curr = head;
	Node* forward = NULL;
	int count = 0;
	
	while(curr != NULL && count < k){
		forward = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = forward;
		count ++ ;
	}

// 	Step 2 - Rest will be seen by recursion
	head -> next = kReverse(forward, k);
	
	return prev;

}