/* This program creates and implements doubly linked list. It performs basic operations on a doubly linked list whose data is entered by a user(of type int).
   Date started :- August 2,2018 (7:12 p.m.) */



#include <iostream>                           			// for cin,cout.

#include <stdlib.h>                           			// for malloc.  

using namespace std;
  
   
struct node 											// base of node structure.
	{ 
	  int val;
	  node *next;
	  node *prev;
	};

void disp(node * P,node *Q)          				  			// function to display the linked list after modification(s).
	{ 
		cout<<"\nThe updated list is:\t";
			while(P!=NULL)
				{ 
					cout<<P->val<<"\t";
					P=P->next;
				}
	    
	    cout<<"\nThe updated (reversed) list is:\t";
			while(Q!=NULL)
				{ 
					cout<<Q->val<<"\t";
					Q=Q->prev;
				}
		cout<<"\n"; 
	}


			void deltval(node * &t,node * &k)
				{ 
					node *del=(node*)malloc(sizeof(node));
					    del=t;
					
					node *pre=(node*)malloc(sizeof(node));
					    pre=t;
					    
					int flag=0,count=0,c2=0;					   // flag to check value. count to count the length of list to recognize last node. 
																   //c2 for position of value found from head
					
					cout<<"\nEnter value to be deleted:\t";        // Value to be deleted from the list.
					int d;
					cin>>d;
					
						  while(del!=NULL)
							   { 
								   if(del->val==d)
								   flag++; 
								   del=del->next; count++;if(flag!=1) c2++;
							   }
							  
						if(flag!=0)
							{	
								if((c2!=0)&&(c2!=count-1))
									{ 
										del=t->next;
									
											while(del->val!=d)
												{   
													del=del->next;
													pre=pre->next;
												}
										if(c2!=count-1)
										    {
											    pre->next=del->next;
											    pre->next->prev=pre;
											    delete del;
									        }
									    else
									        {
												pre->next=NULL;
												delete del;
												k=pre;
											}
									    
									}
								 
								else 
									{
										t=t->next;
										t->prev=NULL;
										delete del; delete pre;
									}
										
								disp(t,k);
							 }	
						 else
						 {
							 cout<<"\nValue not present in the list\n"; 
				          }
				}
				
					
			void deltind(node * &t,node * &k)
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
								t=t->next;
								t->prev=NULL;
								
								delete del;
								disp(t,k);
							}
						
						else
							{   
								del=del->next;
								
									for(int i=2;i<indx;i++)		  // i=2 because, if i want to add at index n,i have to add element after node n-1 and
										{   					  // it would require the address of node at n-1(which is stored in node(n-2))and for reaching node n-2
											pre=pre->next;		  // the loop must run n-2 times.( n>=2)
											del=del->next;
										}
										
										if(del!=k)
											{	
											  pre->next=del->next;
											  del->next->prev=pre;
											  delete del;
											}
										else
											{
											  pre->next=NULL;
											  delete del;	
											  k=pre;
											}
								disp(t,k);
							 }
							 
				      }
				      
				      else 
				      {
							cout<<"\nIndex not available.\n";
					  }
					
				}
		   
				       

			void deltht(node * &t, node * &k)
				{
					cout<<"\n1. Delete head."<<"\n2. Delete tail.\n\t"; 
				    int ch;
				    cin>>ch;
				   
					   switch(ch)
						   {
							   case 1: {
										   node *del=(node*)malloc(sizeof(node));
										   del=t;
										   
										   t=t->next;
										   t->prev=NULL;
										   										   
										   delete del;
										   
										   disp(t,k);
										   
										   break;
									   }
							   
							   case 2: {
								           node *pr=(node*)malloc(sizeof(node));
										   pr=k;
										   k=k->prev;
										   
										   k->next=NULL;
										   
										   delete pr;										   	
																						
										   disp(t,k);
										
										   break;
									   
									   }
										
							   default: { cout<<"\nNo option matches from your choice.(restarting value deletion operation..)";  deltht(t,k);
									    }
							
							}
							
							
				}

	
void delt(node * &t,node * &k)            			 			// function to perform deletion operation.
	{	
			cout<<"\nChoose a method to delete:"<<"\n1. Deletion through value.";
			cout<<"\n2. Deletion through index."<<"\n3. Delete head or tail.\n\t";
			int ch;
			cin>>ch;
				
				switch(ch)
					{  
						case 1:  deltval(t,k);break;
						
						case 2:  deltind(t,k);break;
						
						case 3:  deltht(t,k);break;
						
						default: cout<<"\nChoose one from below";   delt(t,k);
					}
					
	}
      
		   
		   
		   void addind(node * &p,node * &q,node * &ad,node * &t,node * &k)
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
					
					if((indx<=count+1)&&(indx>=1))
					  {
						if(indx==1)
							{ 
							  ad->next=p;
							  p->prev=ad;
							  p=ad;
							  t=p;
							  
							  disp(t,k);
							}
					
						else
							{
							  for(int i=2;i<indx;i++)             
								 {                               // i=2 because, if i want to add at index n,i have to add element after node n-1 and  
								   p=p->next;                    // it would require the address of node at n-1(which is stored in node(n-2))and for reaching node n-2
								 }							     // the loop must run n-2 times.( n>=2)
							   
							  if(p==q)
							  { p->next=ad;
								ad->prev=p;
								k=ad;
							  }
							  else
							  {   								
							  ad->next=p->next;
							  p->next=ad;
							  ad->next->prev=ad;
							  ad->prev=p;
						      }
		
							  disp(t,k);
							 
							}
					   }
					   else  
						{
							cout<<"\nIndex not available\n";
						}
				}
		   
		   
		   
		   void addval(node * &p,node * &q,node * &ad,node * &t,node * &k)
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
														  if(p!=q)
															  {
																ad->next=p->next;
																p->next=ad; 
																ad->prev=p;
																ad->next->prev=ad;
															  }
														  else 
															  {
																p->next=ad;
																ad->prev=p;
																q=ad;
																k=q;
															  }
													  
													  disp(t,k);
													  
													  break;
													
									   case 2:    while(p->val!=n) 
													   { 
														  p=p->next; 
												       }
												             if(p!=t)
																 {
																   ad->prev=p->prev;
																   ad->next=ad->prev->next;
																   ad->prev->next=ad;
																   p->prev=ad;
																 }
															 else
															     {
																	 ad->next=p;
																	 p->prev=ad;
																	 p=ad;
																	 t=p;
															     }
													   disp(t,k);
													   
													   break;
																 															

									   default:{ cout<<"\nNo option matches from your choice.(restarting value addition operation..)";addval(p,q,ad,t,k);
											   }
									}
								
								
						}
						
						else 
						{
							cout<<"\nValue not present in the list";
						}
					
				}
		   
		   
		   
		   void addht(node * &p,node * &q,node * &ad,node * &t,node * &k)
			   {  
				   cout<<"\n1. Add at head."<<"\n2. Add at tail.\n\t"; 
				   int ch;
				   cin>>ch;
				   
					   switch(ch)
						   {
							   case 1: ad->next=p;
							           p->prev=ad;
							           p=ad;
							           t=p;
									   
									   disp(t,k);
									   
									   break;
									   
							   
							   case 2: q->next=ad;
							           ad->prev=q;
							           q=ad;
							           k=q;
							           									   
									   disp(t,k);
										
									   break;
										
							   default: cout<<"\nNo option matches from your choice.";							
							}
				 
				}
				
				
void add(node * &t,node * &k)                          			// function to perform addition operation.
	{   
		node *p=(node*)malloc(sizeof(node));    				// node(head copy) for traversal.
		p=t;
			
		node *q=(node*)malloc(sizeof(node));    				// node(tail copy) for traversal.
		q=k;
		
		node *ad=(node*)malloc(sizeof(node));      				// new node to store input value to be added.
		ad->next=NULL;
		ad->prev=NULL;
		 
		cout<<"\nEnter value to be added:\t"; 
		cin>>ad->val;
		
		cout<<"\nChoose a method to add:"<<"\n1. Addition through values."<<"\n2. Addition through index."<<"\n3. Add at head or tail.\n\t";
		int ch;
		cin>>ch;
		
			switch(ch)
				{  
					case 1:  addval(p,q,ad,t,k);break;
					
					case 2:  addind(p,q,ad,t,k);break;
					
					case 3:  addht(p,q,ad,t,k);break;
					
					default: cout<<"\nChoose one from below";add(t,k);
				}
		   
		  	
	}		            
		                      
		       
    
void menu(node * &t,node * &k)                            		// function for diplaying menu and accesing operations.
	{   
			 int op;
			 cout<<"\n\nChoose an operation from below(enter the number against the operation):";
			 cout<<"\n"<<"1. Add an element.\n"<<"2. Remove an element.\n";
			 cout<<"3. Display the list.\n"<<"4. Exit\n\t";
			 cin>>op;
				
				switch(op)
					{ 
						case 1:   add(t,k);menu(t,k);break;
						
						case 2:   delt(t,k);menu(t,k);break;
						
						case 3:   disp(t,k);menu(t,k);break;
						
						case 4:   cout<<"\nExit successfull";break;
						
						default :   disp(t,k);
					}
	}
        
   
int main()
	{  
	   node *head=(node*)malloc(sizeof(node));					// head creation.
	   head->next=NULL;
	   head->prev=NULL;
	   
	   node *tail=(node*)malloc(sizeof(node));					// tail creation.
	   tail->next=NULL;
	   tail->prev=NULL;
	   
	   cout<<"Enter your linked list(minimum 2 elements of type int):\t\n";
	   cin>>head->val;
	   
	   node *t=(node*)malloc(sizeof(node));					    // node to copy head.
	   t=head;													// node to copy tail.
	   
	   node *k=(node*)malloc(sizeof(node));
	   k=tail;
	   	   
	   char check='Y';
	   
		   while((check=='Y')||(check=='y'))                    		   // creation of linked list.
				  { 
				    node *p=(node*)malloc(sizeof(node));
					p->next=NULL;
					p->prev=t;
				  
					cin>>p->val;
				  
					t->next=p;
					t=p;
				    tail=p;
					cout<<"\nDo you want to add more elements(Y/y for yes, any other character for no):\t";
					cin>>check;
				  }
		 
		
		k=tail;												 // copying tail's value to a back traversal node "k".
		
		t=head; 
		
		disp(t,k);                 							 // copying head's value to a traversal node "t".

		menu(t,k);											 // display menu.
		
			 
		return 0;
		
	}
   
   
   
   
 
