// Tensor definition and instantiation function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct 
{
	float* data;
	int* strides;
	int* shape;
	int ndim;
	int size;
	char* device;
} Tensor;

Tensor* create_tensor(float* p_data, int* p_shape, int p_ndim) 
{
	Tensor* tensor = (Tensor*)malloc(sizeof(Tesnor));
	if(tensor == NULL) 
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(1);
	}
	tensor->data = p_data;
	tensor->shape = p_shape;
	tensor->ndim = p_ndim;
	tensor->size = 1;
	
	for (int i = 0; i < ndim; i++) 
	{
		tensor->size *= shape[i];
	}

	tensor->strides = (int*)malloc(ndim * sizeof(int));
	if(tensor->strides == NULL) 
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(1);
	}
	int stride = 1;
	for(int i=ndim-1; i>=0; i--) 
	{
		tensor->strides[i] = stride;
		stride *= shape[i];
	}

	return tensor;
}

// Element access via stride arithmetic
float get_item(Tensor* p_tensor, int* p_indices)
{
	int index = 0;
	for(int i = 0; i < tensor->ndim; i++) 
	{
		index += indices[i] * tensor->strides[i];
	}
	float result;
	result = tensor->data[index];
	
	return result;
}
