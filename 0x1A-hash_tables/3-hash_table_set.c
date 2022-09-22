#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table to be updated
 * @key: The key
 * @value: The key's value
 * Description: A key and value is set to a particular
 *  index on the HT, if collision, the element will be set
 *  to the beginning of the list and the previous element to next.
 *
 * Return: 1 if succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index, size;
	hash_node_t *new_key, **ht_array;
	char *str;
	const char *ch;

	/* Check if hash table is valid */
	if (ht == NULL)
	{
		return (0);
	}
	ht_array = ht->array;
	/* Create new key */
	new_key = create_key(key, value);
	if (new_key == NULL)
	{
		return (0);
	}
	/* Generate index for the element */
	size = ht->size;
	index = key_index((unsigned char *)key, size);
	str = strdup(value);
	/* Set new key to index position on hash table */
	if (ht_array[index] == NULL)
	{
		ht_array[index] = new_key;
		free(str);
	}
	else
	{
		ch = (const char *)ht_array[index]->key;
		if (strcmp(ch, key) == 0)
		{ /* Update the value if key already exist*/
			ht_array[index]->value = str;
			return (1);
		}
		new_key->next = ht_array[index];
		ht_array[index] = new_key;
		free(str);
	}
	return (1);
}


/**
 * create_key - create a new key with value
 * @key: The key
 * @value: The key's value
 * Description: Create a new key with the value assign from a duplicate
 *  then return the created key/value
 * Return: a pointer to the key if successful or NULL if not
 */

hash_node_t *create_key(const char *key, const char *value)
{
	hash_node_t *element;
	char *ele = strdup(key);
	char *str = strdup(value);

	/* Create the new element */
	element = malloc(sizeof(hash_node_t));

	/* Check if element is created successfully */
	if (element == NULL)
	{
		return (NULL);
	}

	/* Assign key and value to the new element */
	element->key = ele;
	element->value = str;
	element->next = NULL;

	return (element);
}
