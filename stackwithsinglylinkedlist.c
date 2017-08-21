#include <stdio.h>
#include <stdlib.h>

typedef struct elementS {
	void *data;
	struct elementS *next;
} element;

int push_stack(element **head, void *data);
int pop_stack(element **head, void **data);
int create_stack(element **head);
int delete_stack(element **head);

int create_stack(element **head)
{
	*head = NULL;
	return 1;
}

int delete_stack(element **head)
{
	element *next, *del_node = *head;

	while(del_node)
	{
		next = del_node->next;
		free(del_node);
		printf("free %p %d %s\n", del_node, __LINE__, __FILE__);
		del_node = next;
	}
	return 1;
}

int push_stack(element **head, void *data)
{
	element *new_node;

	new_node = malloc(sizeof(element));
	if(!new_node)
	{
		printf("fail to allocate memory %d %s\n", __LINE__, __FILE__);
		return 0;
	}
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
	printf("added %p %d %s\n", new_node, __LINE__, __FILE__);
	return 1;
}

int pop_stack(element **head, void **data)
{
	element *node = *head;
	
	if(!*head)
	{
		printf("fail to pop %p %d %s\n", *head, __LINE__, __FILE__);
		return 0;
	}
	*data = node->data;
	*head = node->next;
	free(node);
	printf("free %p %d %s\n", node, __LINE__, __FILE__);
	return 1;
}

int main()
{
	element *stack_1;
	char data1[] = "abcdef";
	char data2[] = "123456";
	void *data_saved;

	create_stack(&stack_1);
	push_stack(&stack_1, &data1);
	push_stack(&stack_1, &data2);
	pop_stack(&stack_1, &data_saved);
	printf("%s\n", (char *)data_saved);
	delete_stack(&stack_1);
}