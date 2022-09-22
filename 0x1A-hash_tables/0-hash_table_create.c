#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table of the size specified
 * @size: size of the hash table creatd
 * Description: Hash table of size specified is created
 *                and each has two members.
 * The first member is the size i.e to represent the index of the key.
 * The second member is the pointer to the first element on that index.
 *
 * Return: Returns a pointer to the hash_table
 *          or NULL if memory is not allocated.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_node_t **table_array;

	hash_table_t *hash_table = malloc(sizeof(hash_table_t));
	/* Check if hash_table guild is successfully created */
	if (hash_table == NULL)
	{
		return (NULL);
	}

	/* Create new hash_table array and check if it's successful */
	table_array = create_array(size);
	if (table_array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	/* Assign value to the hash table members */
	hash_table->size = size;
	hash_table->array = table_array;

	return (hash_table);
}


/**
 * create_array - create a new hash table array
 * @size: array size
 * Description: Create an array of size specified and initialize
 *   all element in the array to NULL
 *
 * Return: a pointer to the array created or NULL if not successful
 */

hash_node_t **create_array(unsigned long int size)
{
	unsigned long int i;

	hash_node_t **table_array = malloc(sizeof(hash_node_t) * size);

	if (table_array == NULL)
	{
		return (NULL);
	}

	/* Initialize all element of array to NULL */
	for (i = 0; i < size; i++)
	{
		table_array[i] = NULL;
	}

	return (table_array);
}
