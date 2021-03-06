#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node* next;
};

struct Node* insertAtHead(struct Node* head , int data){
struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));
new_head->data = data;
if(head->data ==-1){
head->data= data;
return head;
}
struct Node* temp = head->next;
while(temp->next != head){
    temp=temp->next;
}
temp->next = new_head;
new_head->next = head ;
head = new_head;
return head;
}
void insertAtTail(struct Node* head , int data){
if(head->data == -1){
head->data = data;
head->next = head;
return;
}
struct Node* next_tail = (struct Node*)malloc(sizeof(struct Node));
next_tail->data = data;
struct Node* temp = head;
do{
temp=temp->next;
}while(temp->next!=head);
temp->next = next_tail;
next_tail->next = head;
}
void display(struct Node* head){
struct Node* temp = head;
do{
printf("%d ",temp->data);
temp=temp->next;
}while(temp != head);
}
void insertBeforeNode(struct Node* head , int node , int data){
struct Node* temp = head;
do{
temp=temp->next;
}while(temp->next!=head && temp->next->data !=node);
if(temp->next==head && temp->data != node){
printf("ELement not found");
return;}
struct Node* node_sub = temp->next;
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->data = data;
temp->next = new_node;
new_node->next = node_sub;
}
void insertAfterNode(struct Node* head , int node , int data){
struct Node* temp = head;
do{
temp=temp->next;
}while(temp->next!=head && temp->data != node);
if(temp->next==head && temp->data !=node){
printf("ELement not found");
return;}
struct Node* node_sub = temp->next;
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->data = data;
temp->next = new_node;
new_node->next = node_sub;
}
struct Node* deleteHead(struct Node* head){
struct Node* temp = head;
struct Node* tail_ptr = head;
do{
    tail_ptr = tail_ptr->next;
}while(tail_ptr->next !=head);
tail_ptr->next = temp->next;
head = temp->next;
free(temp);
return head;
}
void deleteTail(struct Node* head){
struct Node* temp = head;
do{
temp=temp->next;
}while(temp->next->next !=head);
struct Node* delNode = temp->next;
temp->next= head;
free(delNode);
}
void deleteNode(struct Node* head , int givenNode ){
struct Node* temp = head;
do{
temp=temp->next;
}while(temp->next!=head && temp->next->data != givenNode);
if(temp->next==head && temp->data != givenNode){
printf("ELement not found");
return;}
if(temp->next->next == NULL){
deleteTail(head);
return;}
struct Node* delNode = temp->next;
temp->next = temp->next->next;
free(delNode);
}
void searchTheNode(struct Node* head , int searchMe){
struct Node* temp = head;
int counter = 0 ;
do{
counter++;
if(temp->data == searchMe){
printf("Number %d found at position %d",searchMe,counter);
return ;
}
temp = temp->next;
}while(temp!=head);
printf("Number %d not found !",searchMe);
}
void lengthLL(struct Node* head){
int l = 0 ;
struct Node* temp = head;
do{
l++;
temp=temp->next;
}while(temp!=head);
printf("Total number of elements : %d",l);
}
int main(){
struct Node* head = (struct Node*)malloc(sizeof(struct Node));
head->data = -1;
head->next = NULL;
printf("Inserting Elements of the Linked List :\n");
while(1){
int input;
char ch;
printf("\nDo you want to enter elements (y/n): ");
scanf("%s",&ch);
if(ch == 'n')
break;
else{
struct Node* inserter = (struct Node*)malloc(sizeof(struct Node));
printf("Enter the element : ");
scanf("%d",&input);
insertAtTail(head,input);
}
}
printf("Content of the Linked List ");
display(head);
printf("\nMAIN MENU\n1. Insert an element\n2.Delete an element\n3.Search for an element\n4.Count the total number of elements\n5.Display the elements of Linked List\n6.Exit\nEnter the choice (1-6): ");
int choice1;
scanf("%d",&choice1);
while(1){
if(choice1 == 6)
{
printf("GOOD-BYE !");
break;
}
switch(choice1){
case 1:
printf("\nINSERT MENU\n1. Insert at the beginning\n2.Insert at the ending\n3.Insert before a given node\n4.Insert after a given node\nEnter the choice (1-4): ");
int ch1;
scanf("%d",&ch1);
int data , node_data;
if(ch1 ==1){
printf("Enter the value to insert : ");
scanf("%d",&data);
head = insertAtHead(head,data);
}
if(ch1 == 3){
printf("Enter the value of the target node : ");
scanf("%d",&node_data);
printf("Enter the value to insert : ");
scanf("%d",&data);
if(node_data == head->data)
head = insertAtHead(head,data);
else
insertBeforeNode(head,node_data,data);
}
if(ch1 == 2){
printf("Enter the value to insert: ");
scanf("%d",&data);
insertAtTail(head,data);
}
if(ch1 == 4){
printf("Enter the value of the target node: ");
scanf("%d",&node_data);
printf("Enter the value to insert: ");
scanf("%d",&data);
insertAfterNode(head,node_data,data);
}
break;
case 2 :
printf("\nDELETE MENU\n1. Delete the first Node\n2.Delete the last node\n3.Delete a given node\nEnter the choice (1-3) : ");
int ch2 , delNodeData;
scanf("%d",&ch2);
if(ch2 == 1)
{
head = deleteHead(head);
}
if(ch2 == 2){
deleteTail(head);
}
if(ch2 == 3){
printf("Enter the value of the given node : ");
scanf("%d",&delNodeData);
if(head->data == delNodeData)
head = deleteHead(head);
else{
deleteNode(head, delNodeData);
}
}
break;
case 3 :
printf("Enter the element to search for : ");
int searchNode;
scanf("%d",&searchNode);
searchTheNode(head, searchNode);
break;
case 4 :
lengthLL(head);
break;
case 5 :
printf("Elements of the Circular linked List : ");
display(head);
break;
case 6 :
break;
break;
}
printf("\nElements of the Circular Linked List is : ");
display(head);
printf("\nMAIN MENU\n1. Insert an element\n2.Delete an element\n3.Search for an element\n4.Count the total number of elements\n5.Display the elements of Linked List\n6.Exit\nEnter the choice (1-6): ");
scanf("%d",&choice1);
}
free(head);
return 0;
}