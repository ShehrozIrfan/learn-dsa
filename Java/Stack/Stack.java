public class Stack {
    static final int SIZE = 100;
    int top;
    //maximum size of the Stack
    int arr[] = new int[SIZE];

    //checking if stack is empty or not
    boolean isEmpty()
    {
        return (top < 0);
    }
    Stack()
    {
        top = -1;
    }

    //inserting element in top of stack
    boolean push(int x)
    {
        if (top >= (SIZE - 1)) {
            System.out.println("Stack Overflow");
            return false;
        }
        else {
            arr[++top] = x;
            return true;
        }
    }

    //removing an element from top of stack
    int pop()
    {
        if (top < 0){
            System.out.println("Stack Underflow");
            return 0;
        }
        else{
            int x = arr[top--];
            return x;
        }
    }

    //returns the current top element of stack
    int peek()
    {
        if (top < 0){
            System.out.println("Stack Underflow");
            return 0;
        }
        else{
            int x = arr[top];
            return x;
        }
    }

    //displaying stack
    void display()
    {
        System.out.println("Stack: ");
        for (int i=top; i>-1; i--)
        {
            System.out.print(" " + arr[i]);
        }
    }
}

class Main{
    public static void main(String args[]){
        Stack s = new Stack();
        s.push(1);
        s.push(2);
        s.push(3);
        s.pop();
        System.out.println("Top element is: " + s.peek());
        s.display();
    }
}