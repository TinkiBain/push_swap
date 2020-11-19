#include "push_swap.h"

void	init_vector(t_vec *vector, size_t size_elem)
{
	vector->size = 0;
	vector->capacity = 4;
	vector->size_elem = size_elem;
	vector->data = malloc(size_elem * vector->capacity); //TO DO
	vector->end_data = vector->data;
}

void	vector_push_back(t_vec *vector, void *data)
{
	void	*new_data;

	if (vector->size == vector->capacity)
	{
		vector->capacity *= 2;
		new_data = malloc(vector->size_elem * vector->capacity); //TO DO
		ft_memcpy(new_data, vector->data, vector->size * vector->size_elem);
		free(vector->data);
		vector->data = new_data;
		vector->end_data = vector->data + (vector->size_elem * vector->size);
	}
	ft_memcpy(vector->end_data, data, vector->size_elem);
	vector->end_data += vector->size_elem;
	vector->size++;
}
