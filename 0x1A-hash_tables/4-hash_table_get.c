#include "hash_tables.h"

/**
 * hash_table_get - retrieved a value associated with a key
 * @ht: hash table
 * @key: The key
 * Description: The value of the specified key is retrieve
 *  from the hash table by accessing the index where the key is stored.
 *
 * Return: The value or NULL
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index, size;
	char *str;
	const char *ch;
	hash_node_t *ptr;

	/* Check if hash table is valid */
	if (ht == NULL)
	{
		return (NULL);
	}

	size = ht->size;
	index = key_index((unsigned char *)key, size);
	ptr = ht->array[index];
	if (ht->array[index] != NULL)
	{
		while (ptr != NULL)
		{
			/* find key */
			ch = ptr->key;
			if (strcmp(ch, key) == 0)
			{
				str = ptr->value;
				return (str);
			}
			ptr = ptr->next;
		}
		return (NULL);
	}
	else
	{
		return (NULL);
	}
}
