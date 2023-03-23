#include <stdio.h>
#include <string.h>
#include "circular_buffer.h"

#define CIRCULAR_BUF_SIZE 256
int main()
{
    circular_buffer_t buf;
    circular_buf_data_t data[2 * CIRCULAR_BUF_SIZE] = {0};
    circular_buf_data_t read[2 * CIRCULAR_BUF_SIZE] = {0};
    const size_t bufSize = sizeof(data) / sizeof(data[0]);

    const size_t EXAMPLE_1_SIZE = CIRCULAR_BUF_SIZE / 2;
    
    circular_buffer_init(&buf, data, bufSize);

    // Partiallu Fill Circular Buffer
    for(int i = 0; i < EXAMPLE_1_SIZE; i++)
    {
        circular_buffer_write(&i, &buf);
    }


    size_t count = 0;
    circular_buf_status_t status = CIRCULAR_BUFFER_SUCCESS;

    while(status == CIRCULAR_BUFFER_SUCCESS)
    {
        status = circular_buffer_read(&read[count], &buf);
        if(status == CIRCULAR_BUFFER_SUCCESS)
        {
            printf("Data [%lu]: %d\n",count + 1, read[count]);
            count++;
        }
        else
        {
            printf("Buffer Empty!\n");
        }
        
    }
    
    printf("Total Count %lu\n", count);
    circular_buffer_init(&buf, data, bufSize);
    memset(read, 0, sizeof(read));


    //Overfill Buffer

    const int EXAMPLE_2_SIZE = CIRCULAR_BUF_SIZE * 3 / 2;

    printf("\n------------\n");
    printf("\nEXAMPLE 2\n");
    printf("Overfiling buffer to size %d \n", EXAMPLE_2_SIZE);
    printf("Data At beginning will be overwritten!\n");

    for(int i = 0; i < EXAMPLE_2_SIZE; i++)
    {
        circular_buffer_write(&i, &buf);
    }
    

    count = 0;
    status = CIRCULAR_BUFFER_SUCCESS;

    while(status == CIRCULAR_BUFFER_SUCCESS)
    {
        status = circular_buffer_read(&read[count], &buf);
        if(status == CIRCULAR_BUFFER_SUCCESS)
        {
            printf("Data [%lu]: %d\n",count + 1, read[count]);
            count++;
        }
        else
        {
            printf("Buffer Empty!\n");
        }
        
    }

    printf("Total Count %lu\n", count);

    return 0;
}