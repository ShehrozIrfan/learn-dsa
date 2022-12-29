//Program to implement Queue using Java
package Java.Queue;

public class Queue {
    static final int SIZE = 100;
    int items[] = new int[SIZE];
    int front, rear;

    Queue() 
    {
        front = -1;
        rear = -1;
    }

    //checking if Queue is empty
    boolean isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //checking if Queue is full
    boolean isFull()
    {
        if (front == 0 && rear == SIZE)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    //inserting elements to queue
    void enQueue(int x)
    {

        //checking if queue is full
        if (isFull())
        {
            System.out.println("Queue is full");
        }

        //inserting the element from rear of Queue 
        else{
            if (front == -1)
            {
                front = 0;
            }
        }
        rear++;
        items[rear] = x;
    }

    //removing element from Queue
    int deQueue()
    {
        int x;

        //checking if queue if empty
        if (isEmpty())
        {
            System.out.println("Queue is Empty");
            return (-1);
        }

        //removing the element from front of Queue
        else
        {
            x = items[front];
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else{
                front++;
            }
            return(x);
        }
    }

    //displaying queue
    void display()
    {
        int i;
        if (isEmpty())
        {
            System.out.println("Queue is empty");
        }
        else{
            System.out.println("Queue: ");
            for (i = front; i <= rear; i++)
            {
                System.out.print(items[i] + " ");
            }
        }
    }
}

class Main{
    public static void main(String args[]){
        Queue q = new Queue();
    
        q.deQueue();
        q.enQueue(1);
        q.enQueue(2);
        q.enQueue(3);
        q.deQueue();
        q.display();
    }
}