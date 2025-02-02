//
// Created by jeremymolina on 12/6/19.
//

#ifndef PERMONITOR_Q_H
#define PERMONITOR_Q_H

#include <stdio.h>
#define MAXSIZE 32

long double queue[MAXSIZE];

int front = -1;
int rear = -1;
int size = -1;

int isempty()
{
    return size<0;
}

int isfull()
{
    return size == MAXSIZE;
}

int queueSize()
{
    return size;
}

void enqueue(long double value)
{
    if(size<MAXSIZE)
    {
        if(size<0)
        {
            queue[0] = value;
            front = rear = 0;
            size = 1;
        }
        else if(rear == MAXSIZE-1)
        {
            queue[0] = value;
            rear = 0;
            size++;
        }
        else
        {
            queue[rear+1] = value;
            rear++;
            size++;
        }
    }
    else
    {
        printf("Queue is full\n");
    }
}

int dequeue()
{
    if(size<0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        size--;
        front++;
    }
}

int Front()
{
    return queue[front];
}

void display()
{
    int i;
    if(rear>=front)
    {
        for(i=front;i<=rear;i++)
        {
            printf("%Lf\n",queue[i]);
        }
    }
    else
    {
        for(i=front;i<MAXSIZE;i++)
        {
            printf("%Lf\n",queue[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%Lf\n",queue[i]);
        }
    }
}

void sendOut()
{
    int i;
    long double *array[24];
    if(rear>=front)
    {
        for(i=front;i<=rear;i++)
        {
            array[i] = &queue[i];
        }
    }
}

#endif //PERMONITOR_Q_H
