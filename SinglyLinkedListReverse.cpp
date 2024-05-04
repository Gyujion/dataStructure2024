#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* remove_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}
ListNode* remove(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
ListNode* reverse_list(ListNode* head)
{
	ListNode* p,*q,*r;
	p = head;	// 역순으로 만들 리스트
	q = NULL;	// 역순으로 만들 노드
	while (p != NULL)
	{
		r = q;	// r은 역순으로 된 리스트

		// r은q, q는 p를 차례로 따라간다.
		q = p;
		p = p->link;	
		q->link = r;	// q의 링크 방향을 바꾼다.
	}
	return q;
}
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
int main()
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	for (int i = 4; i >= 1; i--)
	{
		head1 = insert_first(head1, i*10);
	}
	print_list(head1);
	head2 = reverse_list(head1);
	print_list(head2);
	
	return 0;
}