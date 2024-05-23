// Tensor Operations
// *Need to add remaining functions from: https://github.com/lucasdelimanogueira/PyNorch/blob/main/norch/csrc/cpu.cpp
// #include "tensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void add_tensor_cpu(Tensor* p_tensor1, Tensor* p_tensor2, float* p_result_data)
{
	for(int i = 0; i< p_tensor1->size; i++)
	{
		p_result_data[i] = p_tensor1->data[i] + p_tensor2->data[i];
	}
}

void add_broadcasted_tensor_cpu(Tensor* tensor1, Tensor* tensor2, float* result_data, int* broadcasted_shape, int broadcasted_size) 
{
	int max_ndim = tensor1->ndim > tensor2->ndim ? tensor1->ndim : tensor2->ndim;

	// Stride calculation for broadcasting
	int* strides1 = (int*)malloc(max_ndim * sizeof(int));
	int* strides2 = (int*)malloc(max_ndim * sizeof(int));
	if (strides1 == NULL || strides2 == NULL) 
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(1);
	}

	int stride1 = 1, stride2 = 1;
	for(int i = max_ndim - 1; i >= 0; i--)
	{
		int dim1 = i < tensor1->ndim ? tensor1->shape[tensor1->ndim - max_ndim + i] : 1;
		int dim2 = i < tensor2->ndim ? tensor2->shape[tensor2->ndim - max_ndim + i] : 1;
		strides1[i] = dim1 == broadcasted_shape[i] ? stride1 : 0;
		strides2[i] = dim2 == broadcasted_shape[i] ? stride2 : 0;
		stride1 *= (dime1 == broadcasted_shape[i]) ? dim : 1;
		stride2 *= (dim2 == broadcasted_shape[i]) ? dim2 : 1;
	}

	// Perform element-wise addition with broadcasting
	for (int i = 0; i < broadcasted_size; i++)
	{
		int index1 = 0, index2 = 0;
		int linear_index = i;
		for (int j = max_ndim - 1; j >= 0; j--)
		{
			int pos = linear_index % broadcasted_shape[j];
			linear_index /= broadcasted_shape[j];
			if (strides1[j] != 0) index1 += pos * strides1[j];
			if (strides2[j] != 0) index2 += pos * strides2[j];
		}
		result_data[i] = tensor1->data[index1] + tensor2->data[index2];
	}
	
	// Free strides
	free(strides1);
	free(strides2);
}

void sub_tensor_cpu(Tensor* tensor1, Tensor* tensor2, float* result_data) 
{
	for(int i = 0; i < tensor1->size; i++)
	{
		result_data[i] = tensor1->data[i] - tensor2->data[i];
	}
}

void sub_broadcasted_tensor_cpu(){}

void elementwise_mul_tensor_cpu(Tensor* tensor1, Tensor* tensor2, float* result_data)
{
	for(int i = 0; i < tensor1->size; i++)
	{
		result_data[i] = tensor->data[i] * tensor2->data[i];
	}
}

void scalar_mul_tensor_cpu(){}

void scalar_div_tensor_cpu(){}

void tensor_div_scalar_cpu(){}

void tensor_div_tensor_cpu(){}

void matmul_tensor_cpu(){}

void broadcasted_batched_matmul_tensor_cpu(){}

void batched_matmul_tensor_cpu(){}

void scalar_pow_tensor_cpu(){}

void tensor_pow_scalar_cpu(){}

void log_tensor_cpu(){}

void sum_tensor_cpu(){}

void max_tensor_cpu(){}

void min_tensor_cpu(){}

void equal_tensor_cpu(){}

void equal_broadcasted_tensor_cpu(){}

void ones_like_tensor_cpu(){}

void zeros_like_tensor_cpu(){}

void transpose_1D_tensor_cpu(){}

void transpose_2D_tensor_cpu(){}

void transpose_3D_tensor_cpu(){}

void assign_tensor_cpu(Tensor* tensor, float* result_data)
{
	for(int i = 0l i < tensor->size; i++)
	{
		result_data[i] = tensor->data[i];
	}
}

void make_contiguous_tensor_cpu(){}

void sin_tensor_cpu(){}

void sigmoid_tensor_cpu(){}

void cos_tensor_cpu(){}
