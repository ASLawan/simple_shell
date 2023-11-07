#include "singly.h"

int main(void)
{
	int add, option, delete, reverse;
	node *new_list;

	node *list = create_list();

	display_list(list);

	printf("\nEnter 1 or 0 to add nodes to the list or not: \n");
	scanf("%d", &add);
	
	if (add == 1)
	{
		printf("Enter (1, 2 or 3) to INSERT at start, any position or end respectively: ");
		scanf("%d", &option);
		if (option == 1)
			new_list = add_at_begin(list);
		else if (option == 2)
			new_list = add_at_pos(list);
		else if (option == 3)
			new_list = add_at_end(list);
		else
			printf("Invalid option\n");
		display_list(new_list);
	}
	else
	{
		printf("No further insertions then\n");
	}

	printf("\nEnter 1 or 0 to delete nodes from the list or not: \n");
	scanf("%d", &delete);
	if (delete == 1)
	{
		printf("Enter (1, 2 or 3) to DELETE at start, any position or end respectively: ");
		scanf("%d", &option);
		if (option == 1)
			new_list = delete_at_begin(list);
		else if (option == 2)
			new_list = delete_at_pos(list);
		else if (option == 3)
			new_list = delete_at_end(list);
		else
			printf("Invalid option\n");
		display_list(new_list);
	}
	else
	{
		printf("No further deletions then\n");
	}
	printf("\nEnter 1 or 0 to reverse the list or not: \n");
	scanf("%d", &reverse);
	if (reverse == 1)
	{
		new_list = reverse_list(list);
		display_list(new_list);
	}
	else
	{
		printf("List will not be reversed!\n");
	}
	return (0);
}
