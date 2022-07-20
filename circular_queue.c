/* The following code implements a basic, fixed size, Circular Buffer data structure. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct 
{
    size_t* buffer;
    size_t* read_ptr;
    size_t* write_ptr;
    size_t capacity;
	size_t nItems;	
} CircularBuffer;

int isInitialized = 0;

/*
	Initializes the circular buffer by 
	allocating memory for it.
	
	NOTE: Sets error code to 1 in case 
	an error is encountered.
*/	
void circular_buf_init(CircularBuffer* cb, size_t capacity, int* error)
{
	if (!isInitialized)
	{
		cb->buffer = malloc(capacity * sizeof(size_t));
		cb->capacity = capacity;
		cb->read_ptr = cb->buffer;
		cb->write_ptr = cb->buffer;
		cb->nItems = 0;
		isInitialized = 1;
		*error = 0;
	}
	else
		*error = 1;
}

/*
	Updates the capacity of the circular buffer 
	to the value specified by the user. This opertation
	will reset the state of the buffer clearing all 
	its contents.
	
	NOTE: Sets error code to 1 in case 
	an error is encountered.
*/	
void circular_buf_resize(CircularBuffer* cb, size_t capacity, int* error)
{
	if (isInitialized)
	{	
		free(cb->buffer);
		cb->buffer = malloc(capacity * sizeof(size_t));
		cb->capacity = capacity;
		cb->read_ptr = cb->buffer;
		cb->write_ptr = cb->buffer;
		cb->nItems = 0;
		isInitialized = 1;
		*error = 0;
	}
	else
		*error = 1;
}

/*
	Resets the state of the circular buffer
	but does not destroy it. After this operation
	the buffer will appear empty.
	
	NOTE: Sets error code to 1 in case 
	an error is encountered.
*/
void circular_buf_reset(CircularBuffer* cb, int* error)
{
	if (isInitialized)
	{
		cb->nItems = 0;
		cb->read_ptr = cb->buffer;
		cb->write_ptr = cb->buffer;
		*error = 0;
	}
	else
		*error = 1;
}

/*
	Destroys the circular buffer and
	releases any resource it holds.
	
	NOTE: Sets error code to 1 in case 
	an error is encountered.
*/
void circular_buf_cleanup(CircularBuffer* cb, int* error)
{
	if (isInitialized)
	{
		free(cb->buffer);
		cb->buffer = NULL;
		isInitialized = 0;
		cb->read_ptr = NULL;
		cb->write_ptr = NULL;
		*error = 0;
	}
	else
		*error = 1;
}

/*
	Inserts an item into the circular buffer.
	
	NOTE: Sets error code to 1 in case 
	an error is encountered.
*/
void circular_buf_put(CircularBuffer* cb, size_t data, int* error)
{
	if (cb->nItems < cb->capacity)
	{
		*(cb->write_ptr) = data;

		if (((cb->write_ptr - cb->buffer)) < cb->capacity)
			(cb->write_ptr)++; 
		else
			cb->write_ptr = cb->buffer;
		
		*error = 0;
		(cb->nItems)++;
	}
	else
		*error = 1;
}

/*
	Retrieves an item from the circular buffer.
	
	NOTE: Sets error code to 1 in case 
	an error is encountered.
*/	
size_t circular_buf_get(CircularBuffer* cb, int* error)
{
	if (cb->nItems > 0)
	{
		size_t data = *(cb->read_ptr);
		
		if ((cb->read_ptr - cb->buffer) < cb->capacity)
			(cb->read_ptr)++;
		else
			cb->read_ptr = cb->buffer;
			
		--(cb->nItems);		
		*error = 0;	
		return data;
	}
	else
	{
		*error = 1;
		return 0;
	}
}

int circular_buf_empty(CircularBuffer* cb)
{
	return (cb->nItems > 0) ? 0 : 1;
}

size_t circular_buf_len(CircularBuffer* cb)
{
	return cb->nItems;
}

/*
	Retrieves each item in the buffer and
	displays it on the command line. The buffer
	will be empty after calling this function.
*/
void circular_buf_print(CircularBuffer* cb)
{
	if (isInitialized)
	{
		if (cb->nItems == 0)
		{
			printf("Buffer is empty!\n");
			return;
		}
		
		printf("Items in the buffer are:\n");
		while (!circular_buf_empty(cb))
		{	
			int error = 0;
			int data = circular_buf_get(cb, &error);
				
			if (error)
			{
				printf("Error occured in get operation.\n");
				break;
			}
			else
				printf("%d\n", data);
		}
	}
	else
		printf("Buffer has not been initialized yet. Operation failed.\n");
}

int main()
{
	CircularBuffer cb;
	size_t len = 0; 
	int choice = 1, error = 0;
	
	do
	{	
		printf("\n----------- MENU -------------\n");
        printf("\n 1.  Initialize the circular buffer.\n");
		printf("\n 2.  Insert an element into the circular buffer.\n");
		printf("\n 3.  Read an element from the circular buffer.\n");
		printf("\n 4.  Print the number of elements currently in the buffer.\n");
		printf("\n 5.  Print the contents of the circular buffer, thus clearing it.\n");
		printf("\n 6.  Resize the circular buffer.\n");
		printf("\n 7.  Reset the circular buffer.\n");
		printf("\n 0.  EXIT.\n");
		printf("\n------------------------------\n");
		
		printf("Please enter your choice: \n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:	
			{			
				printf("Please enter the capacity of the circular buffer.\n");
				scanf("%zu", &len);
			
				int error = 0;
				circular_buf_init(&cb, len, &error);
				if (error)
					printf("Operation failed. Buffer already initialized!\n");
				else
					printf("Buffer initialized successfully.\n");
				
				break;
			}
				
			case 2:
			{
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
				size_t output = 0;
				output = circular_buf_get(&cb, &error);
				
				if (error)
					printf("Read operation failed. Buffer empty!\n");
				else
					printf("Element read: %zu\n", output);
				
				break;
			}
			
			case 4:
				printf("No. of elements in the buffer: %zu\n", circular_buf_len(&cb));
				break;
				
			case 5:
				circular_buf_print(&cb);
				break;
				
			case 6:
				printf("Please enter the new capacity of the circular buffer.\n");
				scanf("%zu", &len);
				circular_buf_resize(&cb, len, &error);
				
				if (error)
					printf("Buffer has not been initialized yet. Operation failed.\n"); 
				else
					printf("Buffer resized successfully.\n");
				
				break;
				
			case 7:
				circular_buf_reset(&cb, &error);
				
				if (error)
					printf("Buffer has not been initialized yet. Operation failed.\n"); 
				else
					printf("Buffer reset successfully.\n");
				
				break;
				
			case 0:	
				printf("Thank you.\n");
				break;
				
			default:
				printf("Invalid input.\n");
				break;		
		}
	} while (choice != 0);
	
	circular_buf_cleanup(&cb, &error);
	return 0;
}