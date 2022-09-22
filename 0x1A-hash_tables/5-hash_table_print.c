#include "hash_tables.h"

/**
 * hash_table_print - print the hash table content
 * @ht: The hash table
 * Description: Print out each content of the table
 *  and also navigate to check collisions and print it
 *
 * Return: Nothing
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *current;
	hash_node_t *temp;
	unsigned long int i, size, first = 1;

	/* Check if ht is valid */
	if (ht != NULL)
	{
		size = ht->size;
		printf("{");
		for (i = 0; i < size; i++)
		{
			current = ht->array[i];
			if (current != NULL)
			{
				if (first)
				{
					printf("'%s': '%s'", current->key, current->value);
					first = 0;
				}
				else
				{
					printf(", '%s': '%s'", current->key, current->value);
				}
				/* Print collisions */
				if (current->next != NULL)
				{
					temp = current->next;
					while (temp != NULL)
					{
						printf(", '%s': '%s'", temp->key, temp->value);
						temp = temp->next;
					}
				}
			}
		}
		printf("}\n");
	}
}
