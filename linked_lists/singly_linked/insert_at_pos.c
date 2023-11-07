#include "singly.h"

node *add_at_pos(node *head)
{
	int pos, value, i = 1, choice = 1, len = 0;
	node *new_node = NULL;
	node *temp = NULL;
	
	temp = head;
	/*get list length*/
	len = list_length(temp);
	printf("Length: %d", len);
	printf("Enter position to insert at: ");
	scanf("%d", &pos);
	/*checkf if its within range*/
	if (pos > len - 1)
	{
		printf("Invalid insert position\n");
		return (NULL);
	}
	else
	{
		while (choice)
		{
			new_node = (node *)malloc(sizeof(node));
			if (new_node == NULL)
			{
				free(new_node);
				return (NULL);
			}
			printf("Enter data to insert: ");
			scanf("%d", &value);
			/*point temp to head and use it to traverse list*/
			new_node->data = value;
			temp = head;

			while (i < pos)
			{
				temp = temp->next;
				i++;
			}
			new_node->next = temp->next;
			temp->next = new_node;

			printf("Insert another node (1-yes/0-no): ");
			scanf("%d", &choice);
		}
	}
	return (head);
}
