#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>


typedef int circular_buf_data_t;

#define CIRCULAR_BUF_SIZE 256


typedef enum{
CIRCULAR_BUFFER_SUCCESS,
CIRCULAR_BUFFER_FAIL,
CIRCULAR_BUFFER_EMPTY
}circular_buf_status_t;
typedef struct 
{
    /* data */
    circular_buf_data_t data[CIRCULAR_BUF_SIZE];
    size_t read_ptr;
    size_t write_ptr;
    size_t len;

}circular_buffer_t;

circular_buf_status_t circular_buffer_init(circular_buffer_t *buf);
circular_buf_status_t circular_buffer_write(circular_buf_data_t *newData, circular_buffer_t *buf);
circular_buf_status_t circular_buffer_read(circular_buf_data_t *data, circular_buffer_t *buf);

#endif