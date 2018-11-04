#include "libft.h"

void	vector_double_increase_capacity(t_vector *vector)
{
	size_t	i;
	void	**tmp_data;

	i = 0;
	if (vector->capacity == 0)
		vector->capacity += 1;
	tmp_data = malloc(vector->capacity);
	while (i < vector->size)
	{
		tmp_data[i] = vector->array[i];
		i += 1;
	}
	vector->array = malloc(vector->capacity * 2);
	i = 0;
	while (i < vector->size)
	{
		vector->array[i] = tmp_data[i];
		i += 1;
	}
	free(tmp_data);
	vector->capacity *= 2;
}

void	vector_push_back(t_vector *vector, void *data)
{
	if (vector->size == vector->capacity)
		vector_double_increase_capacity(vector);
	vector->array[vector->size] = data;
	vector->size += 1;
}

void	*vector_get_at(t_vector *vector, size_t index)
{
	return vector->array[index];
}