/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> * prev = NULL;
	LinkedListNode<int> * curr = head;
	LinkedListNode<int> * forward;
	
	if(head == NULL || head->next == NULL)
		return head;
	
	while(curr != NULL){
		forward = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = forward;	
	}
	
	return prev;
}