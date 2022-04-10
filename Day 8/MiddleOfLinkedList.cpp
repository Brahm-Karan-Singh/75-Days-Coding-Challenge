/****************************************************************

    Following is the class structure of the Node class:

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
int getLength(Node* head){
	Node* temp = head;
	int count = 0;
	
	while(temp != NULL){
		count++;
		temp = temp -> next;
	}
	return count;
}


Node *findMiddle(Node *head) {
//  int length = getLength(head);
// 	int mid = length/2;
// 	Node* temp = head;
// 	int ans = 0;
	
// 	while(ans < mid){
// 		temp = temp -> next;
// 		ans++;
// 	}
	
// 	return temp;
	
// Second Approach 
	
	if(head == NULL || head -> next == NULL)
    	return head;
    Node* fast = head -> next;
	Node* slow = head;
	
	while(fast != NULL){
		fast = fast -> next;
		if(fast != NULL)
			fast = fast -> next;
		slow = slow -> next;
	
	}
	
	return slow;

}







