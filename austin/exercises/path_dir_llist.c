#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*list struct*/
typedef struct node
{
	char *data;
	struct node *next;
} node_s;

node_s *head = NULL;
node_s *current = NULL;

/*insert node to list*/
void insert_node(char *data)
{	/*declare new node*/
	node_s *new_node;

	/*allocate memory to node*/
	new_node = (struct node*) malloc(sizeof(struct node));
	/*verify allocated memory*/
	if (new_node == NULL)
	{
		return;
	}
	/*assign values to node*/
	new_node->data = data;
	new_node->next = head;
	head = new_node;

}

/*print linked list*/
void print_list()
{
	node_s *p = head;

	printf("\n[");

	while (p != NULL)
	{
		printf(" %s ", p->data);
		p = p->next;
	}
	printf("]\n");
}

int main(void)
{
	char *path;
	char *dir;

	path = getenv("PATH");
	dir = strtok(path, ":");

	while (dir)
	{
		insert_node(dir);
		dir = strtok(NULL, ":");
	}

	print_list();

	return (0);
}
