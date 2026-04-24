#include <stdio.h>
#include <string.h>

#define SIZE 20

typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void init(CircularBuffer *cb)
{
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(CircularBuffer *cb)
{
    return cb->count == SIZE;
}
int isEmpty(CircularBuffer *cb)
{
    return cb->count == 0;
}

void writeBuffer(CircularBuffer *cb, char data)
{
    if(isFull(cb))
    {
        printf("Buffer Overflow\n");
        return;
    }

    cb->buffer[cb->tail] = data;

    cb->tail = (cb->tail + 1) % SIZE;

    cb->count++;
}

char readBuffer(CircularBuffer *cb)
{
    char data;

    if(isEmpty(cb))
    {
        printf("Buffer Underflow\n");
        return '\0';
    }

    data = cb->buffer[cb->head];

    cb->head = (cb->head + 1) % SIZE;

    cb->count--;

    return data;
}



int main()
{
    CircularBuffer cb;

    char name[50];

    int i;
    char ch;

    init(&cb);

    printf("Enter your name: ");
    scanf("%s", name);

    strcat(name, "CE-ESY");
  
    for(i = 0; name[i] != '\0'; i++)
    {
        writeBuffer(&cb, name[i]);
    }


    printf("Output: ");

    while(!isEmpty(&cb))
    {
        ch = readBuffer(&cb);
        printf("%c", ch);
    }

    printf("\n");
    if(isEmpty(&cb))
    {
        printf("Buffer is now empty.\n");
    }

    return 0;
}
