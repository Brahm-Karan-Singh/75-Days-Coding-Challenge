#include<map>
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

Node *removeDuplicates(Node *head)
{
// 	empty list
	if(head == NULL)
		return NULL;
	
// 	non empty list
// 	Approach -1 Using 2 loops
//     Node* curr = head;
// 	while(curr != NULL){
// 		Node* temp = curr;
// 		while(temp -> next != NULL){
// 			if(curr -> data == temp -> next -> data){
// 				Node* nextKaNext = temp -> next ->next;
// 				Node* deleteNode = temp -> next;
// 				deleteNode -> next = NULL;
// 				delete(deleteNode);
// 				temp -> next = nextKaNext;
// 			}else{
// 				temp = temp -> next;
// 			}
// 		}
// 		curr = curr -> next;
// 	}
// 	return head;
	
// 	Approach 2- Using maps
	
	Node* temp = head;
	Node* prev = NULL;
	map<int,bool> visited;
	
	while(temp != NULL){
	   // cout<<"Coming in for "<<temp -> data<<" where visited[temp] = "<<visited[temp->data]<<endl;
		if(visited[temp->data] == true){
		  //  cout<<"Gone in "<<endl;
		    prev -> next = temp -> next;
			delete(temp);
			temp = prev -> next;
		}else{
		visited[temp->data] = true;
// 		cout<<" where visited[temp] = "<<visited[temp->data]<<endl;
		prev = temp;
		temp = temp -> next;
		}
		
	   // cout<<"Going out for "<<temp -> data<<" where visited[temp] = "<<visited[temp->data]<<endl;
	}
// 	print(head);
	return head;
}