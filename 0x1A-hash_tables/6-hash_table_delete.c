#include "hash_tables.h"

/**
 * hash_table_delete - delete the hash table
 * @ht: The hash table
 * Description: Delete each content of the table by
 *  freeing the allocated memory on the heap
 *  and also navigate to check collisions and delete it
 *
 * Return: Nothing
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *current, *temp;
	unsigned long int i, size;

	/* Check if ht is valid */
	if (ht != NULL)
	{
		size = ht->size;
		for (i = 0; i < size; i++)
		{
			current = ht->array[i];
			while (current != NULL)
			{
				temp = current;
				free(temp->key);
				free(temp->value);
				free(temp);
				current = current->next;
			}
		}
		free(ht->array);
		free(ht);
	}
}
