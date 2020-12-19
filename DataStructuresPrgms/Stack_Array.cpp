					/***********Program to show implementation of Stack through Arrays.
								Created by Nitish Arya. Started on 10th August 2018.***********/

#include <iostream>

using namespace std;

class Stack 	 				//Stack decleration.
{ 
	private:
			int val[100];
			int top;
    public:
            Stack()
            {
				top = -1;
			} 
			
			bool stackfull();
			
			bool stackempty();
			 
			void push(int x);
			
			int pop();
			
			void display();
}s;                            //Stack object declared(global);

bool Stack::stackfull()             //Function to check if the stack is full(i.e if top's value is 99 or not).
{
	if(top == 99)
	return true;
	
	else 
	return false;		
}

bool Stack::stackempty()			   //Function to check if the stack is empty(i.e if top's value is -1 or not).
{
	if(top == -1)
	return true;
	
	else
	return false;
}

void Stack::push(int x)             //Function to add a value at the top of the Stack after checking if the Stack is full or not.
{		
	if(!stackfull())
    {
		val[top+1]=x;
		top++;
	}
	
	else
	cout<<"Stack full!"<<endl;
}

int Stack::pop()                   //Function to pop the topmost value from the stack after checking if the Stack is empty or not.
{
	if(!stackempty())
	{
		int y;
		y=val[top];
		top--;
		
		return y;
	}
	
	else
	{
		cout<<"Stack empty!"<<endl;
	    return 0; 
	}
}

void Stack::display()			   //Function to display Stack.
{
	if(!stackempty())
	{
	    cout<<"\nStack is:"<<endl;
	    
		for(int i=0;i<=top;i++)
		{
			cout<<"["<<val[i]<<"]"<<endl;
		}
		for(int i=0;i<50;i++)
		{
			cout<<"_";
        }	
        
        cout<<endl;
	}
}

void menu()                    //Fuction to display menu and call the function according to the input of the user.
{
	int choice;                //Variable to store the choice of user's input.
	static int flag=1;				   //Variable(Signal) to indicate that Stack has to be created for the first time.
	
    if(flag==1)				   //Condition to check if user is running the program first time and hence has to create a Stack for further operations.
    {
		int l,x;
		cout<<"Create a Stack by entering values(max 100)."<<endl;
		cout<<"Enter no. of values to be inserted:\t";
		cin>>l;    
        cout<<endl<<"Enter values:"<<endl;
        for(int i=0;i<l;i++)
        {
			cin>>x; s.push(x);
		}
		
		flag=0;			   //Flag changed implies user has created a Stack and now can only operate on it.
		
	}    
    
    
		cout<<"\n1. Push an element"<<endl<<"2. Pop an element"<<endl<<"3. Display Stack"<<endl<<"4. Exit"<<endl<<"\t";
		cout<<"\nEnter your choice:\t";
		
		cin>>choice;
    

		switch(choice)
		{
			case 1: {
					    int x;
						cout<<"\nEnter element to be pushed:\t";      
						cin>>x;
						s.push(x); s.display(); menu(); break;
			        }
			        
			case 2: {   
				        if(s.stackempty()) 
				        { s.pop(); menu(); break;}      //If Stack is empty, display the message and open menu again.
				        int y;
						y=s.pop();
						cout<<"\nElement popped is:\t"<<y<<endl;	
						s.display(); menu(); break;
					}
					
            case 3: s.display(); menu(); break;
            
            case 4:	cout<<"Exit scuccessfull!"<<endl; break;		
			   
			default : cout<<"Enter a valid choice."<<endl; 
						menu(); break;
		}
	
}
	
    


int main()
{ 
	menu();
	
	return 0;
	
}
