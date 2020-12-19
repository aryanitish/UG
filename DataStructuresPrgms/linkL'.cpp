/* This program creates and implements linked list. It performs basic operations on a linked list whose data is entered by a user(of type int).
   Date started :- August 1,2018 (10:05 p.m.) */



#include <iostream>                           			// for cin,cout.

#include <stdlib.h>                           			// for malloc.  

using namespace std;
  
   
struct node 											// base of node structure.
	{ 
	  int val;
	  node *next;
	};

void disp(node * P)          				  			// function to display the linked list after modification(s).
	{ 
		cout<<"\nThe updated list is:\t";
			while(P!=NULL)
				{ 
					cout<<P->val<<"\t";
					P=P->next;
				}
		cout<<"\n"; 
	}

			void deltval(node * &t)
				{ 
					node *del=(node*)malloc(sizeof(node));
					    del=t;
					
					node *pre=(node*)malloc(sizeof(node));
					    pre=t;
					    
					int flag=0;
					
					cout<<"\nEnter value to be deleted:\t";
					int d;
					cin>>d;
					
						while(del!=NULL)
							   { 
								   if(del->val==d)
								   flag++; 
								   del=del->next;
							   }
						if(flag!=0)
							{	if(flag!=1)
									{
										del=t->next;
									
											while(del->val!=d)
												{   
													del=del->next;
													pre=pre->next;
												}
										
									    pre->next=del->next;
									
									    delete del;
									}
								 else 
								 {
									 t=t->next;
								     delete del; delete pre;
							     }
						 else
						 {
							 cout<<"\nValue not present in the list\n"; 
				          }
				}
				
					
			void deltind(node * &t)
				{
					int indx,count=0;
					cout<<"\nEnter index of elememt to be deleted:\t";
					cin>>indx;

					node *del=(node*)malloc(sizeof(node));
						del=t;
					node *pre=(node*)malloc(sizeof(node));
						pre=t;
							
							while(del!=NULL)
								   { 
									   count++;
									   del=del->next;
								   }
								   
						   del=t;
					
					if((indx<=count)&&(indx>=1))
					  {

						if(indx==1)
							{
								t=t->next; updatehead(t);
								delete del;
								disp(t);
							}
						
						else
							{   
								del=del->next;
								
									for(int i=2;i<indx;i++)
										{   
											pre=pre->next;
											del=del->next;
										}
									
								pre->next=del->next;
								
								delete del;	
							 
								disp(t);
							 }
				      }
				      
				      else 
				      {
							cout<<"\nIndex not available.\n";
					  }
					
				}
		   
				       

			void deltht(node * &t)
				{
					cout<<"\n1. Delete head."<<"\n2. Delete tail.\n\t"; 
				    int ch;
				    cin>>ch;
				   
					   switch(ch)
						   {
							   case 1: {
										   node *del=(node*)malloc(sizeof(node));
										   del=t;
										   
										   t=t->next; updatehead(t);
										   
										   delete del;
										   
										   disp(t);
										   
										   break;
									   }
							   
							   case 2: {
								           node *p=(node*)malloc(sizeof(node));
										   p=t; 
										
										   p=p->next;
										
										   node *prev=(node*)malloc(sizeof(node));
										   prev=t;
											
												while(p->next!=NULL)  
													{ 
														p=p->next; 
														prev=prev->next;
										             }
										
										   prev->next=NULL;
										
										   delete p;
										
										   disp(t);
										
										   break;
									   
									   }
										
							   default: { cout<<"\nNo option matches from your choice.(restarting value deletion operation..)";  deltht(t);
									    }
							
							}
							
							
				}

	
void delt(node * &t)            			 			// function to perform deletion operation.
	{	
			cout<<"\nChoose a method to delete:"<<"\n1. Deletion through value.";
			cout<<"\n2. Deletion through index."<<"\n3. Delete head or tail.\n\t";
			int ch;
			cin>>ch;
				
				switch(ch)
					{  
						case 1:  deltval(t);break;
						
						case 2:  deltind(t);break;
						
						case 3:  deltht(t);break;
						
						default: cout<<"\nChoose one from below";   delt(t);
					}
					
	}
      
		   
		   
		   void addind(node * &p,node * &ad,node * &t)
			   { 
					int indx,count=0;
					cout<<"\nEnter index no. where the element is to be added:\t";
					cin>>indx;
					
					 while(p!=NULL)
						   { 
							   count++;
							   p=p->next;
						   }
						   
				   p=t;
					
					if((indx<=count)&&(indx>=1))
					  {
						if(indx==1)
							{ 
							  ad->next=p;
							  p=ad; updatehead(t);
							  disp(t);
							}
					
						else
							{
							  for(int i=2;i<indx;i++)             
								 {                               // i=2 because, if i want to add at index n,
								   p=p->next;                    // it would require the address of node at n(which is stored in node(n-1))and for reaching node n-1
								 }							     // the loop must run n-2 times.(given nodes start from 0 & n>=2)
							   
							     								
							  ad->next=p->next;
							  p->next=ad;
							  disp(t);
							 
							}
					   }
					   else  
						{
							cout<<"\nIndex not available\n";
						}
				}
		   
		   void addval(node * &p,node * &ad,node * &t)
			   { 
				   int flag=0;
				   cout<<"\nEnter a value from the linked list:\t";
				   int n; 
				   cin>>n;
				   
					   while(p!=NULL)
						   { 
							   if(p->val==n)
							   flag=1;
							   p=p->next;
						   }
						   
				   p=t;
				   
					   if(flag==1)
					   {
						   cout<<"\n1. Add after\t"<<n<<"\n2. Add before\t"<<n<<"\n";
						   int ch;
						   cin>>ch;
						   
							   switch(ch)
								   { 
									   case 1:   while(p->val!=n) 
													  { 
													   p=p->next;
													  }
												  
												  ad->next=p->next;
												  p->next=ad; 
												  
												  disp(t);
												  
												  break;
												
									   case 2:  {
													node *adpr=(node*)malloc(sizeof(node));
													adpr=p;
													int flag=0;
													p=p->next; 
														   
															while(adpr->val!=n) 
																 { 
																   flag=1;
																   p=p->next; 
																   adpr=adpr->next;
																 }
														
														if(flag==1)
															{		 
																ad->next=p;
																adpr->next=ad;
															}
														else
															{
																ad->next=t;
																t=ad; updatehead(t);
															}
													disp(t);
													
													break;
												}

									   default:{ cout<<"\nNo option matches from your choice.(restarting value addition operation..)";addval(p,ad,t);
											   }
									}
								
								
						}
						
						else 
						{
							cout<<"\nValue not present in the list";
						}
					
				}
		   void addht(node * &p,node * &ad,node * &t)
			   {  
				   cout<<"\n1. Add at head."<<"\n2. Add at tail.\n\t"; 
				   int ch;
				   cin>>ch;
				   
					   switch(ch)
						   {
							   case 1: ad->next=t;
							           t=ad;
							           updatehead(t);
									   
									   disp(t);
									   
									   break;
									   
							   
							   case 2:   while(p->next!=NULL)  
												{ 
													p=p->next; 
												}
										
										p->next=ad;
										
										disp(t);
										
										break;
										
							   default: cout<<"\nNo option matches from your choice.";							
							}
				 
				}
				
void add(node * &t)                          			// function to perform addition operation.
	{   
		node *p=(node*)malloc(sizeof(node));    				// node for traversal.
	    p->next=NULL;
		p=t;
			
		
		node *ad=(node*)malloc(sizeof(node));      				// new node to store input value to be added.
		ad->next=NULL;
		 
		cout<<"\nEnter value to be added:\t"; 
		cin>>ad->val;
		
		cout<<"\nChoose a method to add:"<<"\n1. Addition through values."<<"\n2. Addition through index."<<"\n3. Add at head or tail.\n\t";
		int ch;
		cin>>ch;
		
			switch(ch)
				{  
					case 1:  addval(p,ad,t);break;
					
					case 2:  addind(p,ad,t);break;
					
					case 3:  addht(p,ad,t);break;
					
					default: cout<<"\nChoose one from below";add(t);
				}
		   
		  	
	}		            
		                      
		       
    
void menu(node * &t)                            		// function for diplaying menu and accesing operations.
	{   
			 int op;
			 cout<<"\n\nChoose an operation from below(enter the number against the operation):";
			 cout<<"\n"<<"1. Add an element.\n"<<"2. Remove an element.\n";
			 cout<<"3. Display the list.\n"<<"4. Exit\n\t";
			 cin>>op;
				
				switch(op)
					{ 
						case 1:   add(t);menu(t);break;
						
						case 2:   delt(t);menu(t);break;
						
						case 3:   disp(t);menu(t);break;
						
						case 4:   cout<<"\nExit successfull";break;
						
						default :   disp(t);
					}
	}
        
   
int main()
	{  
	   node *head=(node*)malloc(sizeof(node));					// head creation.
	   head->next=NULL;
	   
	   cout<<"Enter your linked list(minimum 2 elements of type int):\t\n";
	   cin>>head->val;
	   
	   node *t=(node*)malloc(sizeof(node));
	   t=head;
	   
	   char check='Y';
	   
		   while((check=='Y')||(check=='y'))                    		   // creation of linked list.
				  { 
				    node *p=(node*)malloc(sizeof(node));
					p->next=NULL;
				  
					cin>>p->val;
				  
					t->next=p;
					t=p;
				  
					cout<<"\nDo you want to add more elements(Y/y for yes, any other character for no):\t";
					cin>>check;
				  }
		 
		   
		 
		
		t=head;                  							 // copying head's value to a traversal node "t".

		menu(t);											 // display menu.
		
			 
		return 0;
		
	}
   
   
   
   
 
