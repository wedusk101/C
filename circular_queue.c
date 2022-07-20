/* The following code implements a basic Circular Queue data structure. */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct 
{
    size_t* buffer;
    size_t* read_ptr;
    size_t* write_ptr;
    size_t capacity;
	size_t nItems;	
} CircularBuffer;

int isInitialized = 0;
int isCopyValid = 0;

void circular_buf_init(CircularBuffer* cb, size_t capacity, int* error, int isCopy)
{
	if (isCopy < 0 && isInitialized != 1234)
	{
		cb->buffer = malloc(capacity * sizeof(size_t));
		cb->capacity = capacity;
		cb->read_ptr = cb->buffer;
		cb->write_ptr = cb->buffer;
		cb->nItems = 0;
		isInitialized = 1234; // magic number to ensure initialized state
		*error = 0;
	}
	else if (isCopy > 0 && isCopyValid != 1234)
	{
		cb->buffer = malloc(capacity * sizeof(size_t));
		cb->capacity = capacity;
		cb->read_ptr = cb->buffer;
		cb->write_ptr = cb->buffer;
		cb->nItems = 0;
		isCopyValid = 1234; // magic number to ensure validity state of the copied buffer
		*error = 0;
	}
	else
		*error = 1;
}

void circular_buf_reset(CircularBuffer* cb)
{
	if (isInitialized)
	{
		cb->nItems = 0;
		isInitialized = 0;
		cb->read_ptr = cb->buffer;
		cb->write_ptr = cb->buffer;
	}
}

void circular_buf_cleanup(CircularBuffer* cb, int isCopy)
{
	if (isCopy > 0)
	{
		if (isCopyValid)
		{			
			free(cb->buffer);
			cb->buffer = NULL;
			isCopyValid = 0;
			cb->read_ptr = NULL;
			cb->write_ptr = NULL;
		}
	}
	else
	{
		if (isInitialized)
		{
			free(cb->buffer);
			cb->buffer = NULL;
			isInitialized = 0;
			cb->read_ptr = NULL;
			cb->write_ptr = NULL;
		}
	}			
}

void circular_buf_put(CircularBuffer* cb, size_t data, int* error)
{
	if (cb->nItems < cb->capacity)
	{
		*(cb->write_ptr) = data;

		if (((cb->write_ptr - cb->buffer)) < cb->capacity)
			(cb->write_ptr)++; 
		else
		{
			int cap = cb->capacity + 1;
			int idx = cap - cb->capacity;
			cb->write_ptr = &cb->buffer[idx];
		}
		
		*error = 0;
		(cb->nItems)++;
	}
	else
		*error = 1;
}
	
size_t circular_buf_get(CircularBuffer* cb, int* error)
{
	if (cb->nItems > 0)
	{
		size_t data = *(cb->read_ptr);
		
		if ((cb->read_ptr - cb->buffer) < cb->capacity)
			(cb->read_ptr)++;
		else
		{
			int cap = cb->capacity + 1;
			int idx = cap - cb->capacity;
			cb->read_ptr = &cb->buffer[idx];
		}
		
		*error = 0;
		--(cb->nItems);
		return data;
	}
	else
	{
		*error = 1;
		return 0;
	}
}

void circular_buf_copy(CircularBuffer* cb, CircularBuffer* copy, int* error)
{
	int err = 0;
	printf("Before init\n");
	circular_buf_init(copy, cb->capacity, &err, 1);	
	printf("After init\n");
	
	if (!err)
	{
		copy->read_ptr = cb->read_ptr;
		copy->write_ptr = cb->write_ptr;
		copy->nItems = cb->nItems;	
		printf("Before memcpy\n");
		memcpy(copy->buffer, cb->buffer, cb->capacity);
		printf("After memcpy\n");
		isCopyValid = 1234;
		*error = 0; 
	}
	else
	{
		isCopyValid = 0;
		*error = 1;
	}
}

void circular_buf_print(CircularBuffer* cb)
{
	if (cb->nItems == 0)
	{
		printf("Buffer is empty!\n");
		return;
	}
	
	if (isInitialized)
	{
		int error = 0;	
		CircularBuffer copy;
		printf("Before copy\n");
		circular_buf_copy(cb, &copy, &error);
		
		printf("After copy\n");
			
		if (error)
		{
			printf("Error occured in copy operation.\n");
			return;
		}
		
		for (size_t i = 0; i < copy.capacity; ++i)
		{
			int data = circular_buf_get(&copy, &error);
			
			printf("After get\n");
			
			if (error)
			{
				printf("Error occured in get operation.\n");
				break;
			}
			
			printf("%d\n", data);
		}
		circular_buf_cleanup(&copy, 1);
		printf("After cleanup\n");
	}
	else
		printf("Buffer not initialized properly. Operation failed.\n");
}

int main()
{
	CircularBuffer cb;
	size_t len = 0; 
	int choice = 1;
	
	do
	{	
		printf("\n----------- MENU -------------\n");
        printf("\n 1.  Initialize the circular buffer.\n");
		printf("\n 2.  Insert an element into the circular buffer.\n");
		printf("\n 3.  Read an element from the circular buffer.\n");
		printf("\n 4.  Print the contents of the circular buffer.\n");
		printf("\n 5.  Reset the circular buffer.\n");
		printf("\n 0.  EXIT.\n");
		printf("\n------------------------------\n");
		
		printf("Please enter your choice: \n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:	
			{			
				printf("Please enter the capacity of the ring buffer.\n");
				scanf("%zu", &len);
			
				int error = 0;
				circular_buf_init(&cb, len, &error, -1);
				if (error)
					printf("Operation failed. Buffer already initialized!\n");
				else
					printf("Buffer initialized successfully.\n");
				
				break;
			}
				
			case 2:
			{
				int error = 0;
				size_t input = 0;				
				printf("Please enter the element to insert.\n");
				scanf("%zu", &input);
				
				circular_buf_put(&cb, input, &error);
				if (error)
					printf("Insert operation failed. Buffer full!\n");
				else
					printf("Element inserted successfully.\n");
				
				break;
			}
				
			case 3:
			{
				int error = 0, output = 0;
				output = circular_buf_get(&cb, &error);
				
				if (error)
					printf("Read operation failed. Buffer empty!\n");
				else
					printf("Element read: %d\n", output);
				
				break;
			}
				
			case 4:
				circular_buf_print(&cb);
				break;
				
			case 5:
				circular_buf_reset(&cb);
				break;
				
			case 0:	
				printf("Thank you.\n");
				break;
				
			default:
				printf("Invalid input.\n");
				break;		
		}
	} while (choice != 0);
	
	
	circular_buf_cleanup(&cb, 0);
	return 0;
}