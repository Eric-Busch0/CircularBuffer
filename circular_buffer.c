#include <string.h>

#include "circular_buffer.h"

circular_buf_status_t circular_buffer_init(circular_buffer_t *buf, circular_buf_data_t *data, size_t bufSize )
{
    if (buf == NULL)
    {
        return CIRCULAR_BUFFER_FAIL;
    }

    buf->len = 0;

    buf->read_ptr = 0;

    buf->write_ptr = 0;

    buf->bufSize = bufSize;
    
    circular_buffer_bind_data(buf, data);

    memset(buf->data, 0, buf->bufSize);

    return CIRCULAR_BUFFER_SUCCESS;
}
circular_buf_status_t circular_buffer_bind_data(circular_buffer_t *buf,circular_buf_data_t *data)
{

    if(buf == NULL || data == NULL)
    {
        return CIRCULAR_BUFFER_FAIL;
    }

    buf->data = data;

    return CIRCULAR_BUFFER_SUCCESS;
}
circular_buf_status_t circular_buffer_write(circular_buf_data_t *newData, circular_buffer_t *buf)
{

    if(newData == NULL || buf == NULL)
    {
        return CIRCULAR_BUFFER_FAIL;
    }

    buf->data[buf->write_ptr] = *newData;

    buf->len++;
    buf->write_ptr++;

    if(buf->write_ptr >= buf->bufSize)
    {
       buf->write_ptr = 0;
    }

    return CIRCULAR_BUFFER_SUCCESS;
}
circular_buf_status_t circular_buffer_read(circular_buf_data_t *data, circular_buffer_t *buf)
{

    if(data == NULL || buf == NULL)
    {
        return CIRCULAR_BUFFER_FAIL;
    }
    
    if(buf->len == 0)
    {
        return CIRCULAR_BUFFER_EMPTY;
    }

    *data = buf->data[buf->read_ptr];

    buf->len--;
    buf->read_ptr++;

    if(buf->read_ptr >= buf->bufSize)
    {
        buf->read_ptr = 0;
    }

    return CIRCULAR_BUFFER_SUCCESS;
}