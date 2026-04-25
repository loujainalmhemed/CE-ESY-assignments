#include <stdio.h>
#include <string.h>

#define SIZE 20

typedef struct
{
    char buffer[SIZE];
    int front;
    int rear;
    int itemsCount;

} CircularBuffer;

void initBuffer(CircularBuffer *cb)
{
    cb->front = 0;
    cb->rear = 0;
    cb->itemsCount = 0;
}

int isFull(CircularBuffer *cb)
{
    return cb->itemsCount == SIZE;
}

int isEmpty(CircularBuffer *cb)
{
    return cb->itemsCount == 0;
}

void enqueue(CircularBuffer *cb, char data)
{
    if (isFull(cb))
    {
        printf("Error: Buffer Full\n");
        return;
    }

    cb->buffer[cb->rear] = data;

    cb->rear = (cb->rear + 1) % SIZE;

    cb->itemsCount++;
}

char dequeue(CircularBuffer *cb)
{
    char data;

    if (isEmpty(cb))
    {
        printf("Error: Buffer Empty\n");
        return '\0';
    }

    data = cb->buffer[cb->front];

    cb->front = (cb->front + 1) % SIZE;

    cb->itemsCount--;

    return data;
}

int main()
{
    CircularBuffer cb;

    char name[50];
    char ch;

    int i;

    initBuffer(&cb);

    printf("Please enter your name: ");
    scanf("%s", name);

    strcat(name, "CE-ESY");

    for(i = 0; name[i] != '\0'; i++)
    {
        enqueue(&cb, name[i]);
    }

    printf("Output: ");

    while(!isEmpty(&cb))
    {
        ch = dequeue(&cb);
        printf("%c", ch);
    }

    printf("\n");

    if(isEmpty(&cb))
    {
        printf("Buffer emptied successfully.\n");
    }

    return 0;
}
