#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node *next;
} Node;	

Node* createNode(int data){
	Node* temp = (Node*)malloc(sizeof(Node));
	if(temp==NULL)
		return NULL;
	temp->data=data;
	temp->next = NULL;
	return temp;
}
Node* insert(Node *head, int data){
	if(head==NULL){
		Node* node = createNode(data);
		return node;
	}
	Node* node = createNode(data);
	if(node != NULL){
		node->next = head;
		head = node;
	}
	return head;
}
void display(Node *head){
	Node* temp = head;
	while(temp!=NULL){
		printf("%d \n",temp->data);
		temp = temp->next;
	}
}

Node* reverse(Node*head){
	Node *prev=NULL,*cur=head, *next=NULL;
	while(cur!=NULL){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

Node* mergelist(Node* list1, Node*list2){
	Node* dummy = createNode(-1);
	Node *sorted=dummy;
	if(list1->data < list2->data)
		dummy->next = list1;
	else
		dummy->next = list2;
	while(list1!=NULL && list2!=NULL){
		if(list1->data<list2->data){
			sorted->next = list1;
			sorted = list1;
			list1 = list1->next;
		}else{
			sorted->next = list2;
			sorted = list2;
			list2 = list2->next;
		}
	}
	if(list1==NULL && list2!=NULL)
		sorted->next = list2;
	else if(list1!=NULL && list2==NULL)
		sorted->next = list1;
	sorted = dummy->next;
	free(dummy);
	return sorted;
}

//Assumption - start_data and end_data are present in the list
void reverse_sublist(Node* head, int start_data, int end_data){
	Node* start=NULL,*end=NULL,*prev_start=NULL,*next_end=NULL;
	start=head;
	while(start->data!=start_data){
		prev_start=start;
		start = start->next;
	}
	end=head;
	next_end=end->next;
	while(end->data!=end_data){
		end = next_end;
		next_end = next_end->next;
	}
	end->next=NULL;
	prev_start->next = NULL;
	prev_start->next= reverse(start);
	end = prev_start->next;
	while(end->next!=NULL)
		end = end->next;
	end->next = next_end;


}
int main(){

	Node *list=NULL,*list2=NULL;
	list = insert(list,10);
	list = insert(list,20);
	list = insert(list,30);
	list = insert(list,40);
	list = insert(list,50);
	list2 = insert(list2,15);
	list2 = insert(list2,25);
	list2 = insert(list2,35);
	list2 = insert(list2,45);
	display(list);
	display(list2);
	printf("\n");
	list = reverse(list);
	list2 = reverse(list2);
	display(list);
	display(list2);
	Node* merge_list = mergelist(list,list2);
	display(merge_list);
	printf("\n");
	printf("reverse list between 20,40\n");
	reverse_sublist(merge_list,20,40);
	display(merge_list);

	return 0;
}
