/********************************
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

********************************/

void insertAtTail(Node* &tail,Node* temp){
	tail -> next = temp;
	tail = temp;
}

Node* sortList(Node *head)
{
// 	Approach 1 -
//     Node* temp = head;
// 	int zeroCount = 0;
// 	int oneCount = 0;
// 	int twoCount = 0;
	
// 	while(temp != NULL){
// 		if(temp -> data == 0){
// 			zeroCount ++;
// 		}else if(temp -> data == 1){
// 			oneCount ++;
// 		}else{
// 			twoCount ++;
// 		}
// 		temp = temp -> next;
// 	}
	
// 	temp = head;
	
// 	while(temp != NULL){
// 	    while(zeroCount !=0 ){
// 			temp -> data = 0;
// 			temp = temp -> next;
// 			zeroCount --;
// 		}
// 		while(oneCount !=0 ){
// 			temp -> data = 1;
// 			temp = temp -> next;
// 			oneCount --;
// 		}
// 		while(twoCount !=0 ){
// 			temp -> data = 2;
// 			temp = temp -> next;
// 			twoCount --;
// 		}
// 	}
// 	return head;
	
// 	Approach 2-
// 	Making three linkedlists of 0,1,2
	Node* zeroHead = new Node(-1);
	Node* zeroTail = zeroHead;
	Node* oneHead = new Node(-1);
	Node* oneTail = oneHead;
	Node* twoHead = new Node(-1);
	Node* twoTail = twoHead;
	
	Node* temp = head;
// 	Traversing linked lists and adding nodes respectively
	while(temp != NULL){
	if(temp -> data == 0){
		insertAtTail(zeroTail,temp);
	}else if(temp -> data == 1){
		insertAtTail(oneTail,temp);
	}else{
		insertAtTail(twoTail,temp);
	}
		temp = temp -> next;
	}
	
// 	Merging linked lists
	if(oneHead -> next != NULL)
		zeroTail -> next = oneHead -> next;
	else
		zeroTail -> next = twoHead -> next;
	
	oneTail -> next = twoHead -> next;
	twoTail -> next = NULL;
	head = zeroHead -> next;
	
// 	Deleting dummy nodes
	delete oneHead;
	delete twoHead;
	delete zeroHead;
	
// 	Returning the ans 
	return head;
	
	
	
	
}
