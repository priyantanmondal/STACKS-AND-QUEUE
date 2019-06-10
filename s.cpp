#include<iostream>												//library
using namespace std;


class node																//class node
{
	public:
	int data;
	node* link;
	node(int value)
	{
		data=value;
		link=NULL;
	}
};


class linkedlist													//class linkedlist
{
	public:
	node* head;															//member pointer
	linkedlist()														//constructor
	{
		head=NULL;
	}
	
	int number_of_nodes()										//returns the number of nodes in a linked list
	{
		if(head==NULL)
		{
			return 0;
		}
		else
		{
			int i=1;
			node* curr=head;
			while(curr->link!=NULL)
			{
				curr=curr->link;
				i++;
			}
			return i;
		}
	}
	
	node* nth_from_head(int n)							//returns the pointer which points to nth node from head
	{
		int x=number_of_nodes();
		
		if (head==NULL || n<1 ||n>x )
		{
			cout<<"ERROR"<<endl;
			return NULL;
		}
		else
		{
			node* curr=head;
			int i=1;
			while(i!=n)
			{
				curr=curr->link;
				i++;
			}
			return curr;
		}
	}
	
	node* nth_from_tail(int n)							//
	{
		int i=1;
		node* curr1=head;
		node* curr2=head;
		while(i!=n)
		{
			curr1=curr1->link;
			i++;
		}
		while(curr1->link!=NULL)
		{
			curr1=curr1->link;
			curr2=curr2->link;
		}
		return curr2;
	}
	 
	void insert_head(int val)							//inserts new node with given data at head
	{
		node* temp=new node(val);	
	
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			temp->link=head;
			head=temp;
		}
	}
	
	void insert_tail(int val)						//inserts new node with given data at tail
	{
		node* temp= new node(val);
		
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			int x=number_of_nodes();
			node* curr=nth_from_head(x);
			curr->link=temp;	
		}
	}
	
	void insertrat(int pos,int val)
	{
		int x= number_of_nodes();
		if(pos==1)
		{
			insert_head(val);
		}
		else if(pos<1 || pos>>x)
		{
			cout<<"that is an invalid position"<<endl;
		}
		else
		{
			node* temp=new node(val);
			node* curr= nth_from_head(pos-1);
			
			temp->link=curr->link;
			curr->link=temp;
		}
	}
	
	void delete_head()
	{
		if(head==NULL)
		{
			cout<<"the linkedlist is already empty"<<endl;
		}
		else
		{
			node* curr=head;
			head=head->link;
			delete curr;
		}
	}
	
	void delete_tail()
	{
	}
	
	
	
	void deleteat(int pos)
	{
		int n=number_of_nodes();
		if(head==NULL)
		{
			cout<<"the linkedlist is already empty"<<endl;
		}
		else
		{
			if(pos<1 || pos>n)
			{
				cout<<"that is an invalid position"<<endl;
			}
			else
			{
				node* curr=nth_from_head(pos-1);
				node* temp=curr->link;
				curr->link=temp->link;
				temp->link=NULL;
				delete temp;
			}
		}
	}
	
	void display()
	{
		if(head==NULL)
		{
			cout<<"empty"<<endl;
		}
		else
		{
			node* curr=head;
			while(curr!=NULL)
			{
				cout<<curr->data;
				curr=curr->link;
			}
		}
	}
	
	void reverse()
	{
		
		if(head==NULL)
		{
			cout<<"the linkedlist is empty"<<endl;
		}
		else
		{
			node* previous=NULL;
			node* next=NULL;
			node* curr=head;
		
			if(curr==head)
			{
				next=curr->link;
				curr->link=NULL;
				previous=curr;
				curr=next;
				next=next->link;
				head=curr;
			}
			else
			{
				curr->link=previous;
				previous=curr;
				curr=next;
				next=next->link;
				head=curr;
			}
		}
	}
	
	void reverse_display(node* curr)
	{
		if(head==NULL)
		{
			cout<<"empty"<<endl;
		}
		else if(curr->link==NULL)
		{
			cout<<curr->data;
		}
		else
		{
			reverse_display(curr->link);
			cout<<curr->data;
		}
		
	}
	
};
	
	
class stack
{

	public:
	node* top;
	linkedlist l1;
	stack()
	{
		top=l1.head;
	}
	
	void push(int value)
	{
		l1.insert_head(value);
		top=l1.head;
	}
	
	void pop()
	{
		if(top==NULL)
		{
			cout<<"the stack is empty"<<endl;
		}
		else
		{
			l1.delete_head();
			top=l1.head;
		}
	}
	
	int size()
	{
		if(top==NULL)
		{
			cout<<"0"<<endl;
			return 0;
		}
		else
		{
			cout<<l1.number_of_nodes();
			return l1.number_of_nodes();
		}
	}
	
	bool is_empty()
	{
		if(top==NULL)
		{
			cout<<"the stack is empty"<<endl;
			return true;
		}
		else
		{
			cout<<"the stack is not empty"<<endl;
			return false;
		}
	}
	
	int peek()
	{
		cout<<(l1.head)->data;
		return (l1.head)->data;
	}
	
};


int main()
{
	linkedlist l1;
	cout<<l1.number_of_nodes();
	cout<<(l1.nth_from_head(78))->data;
	l1.insert_head(6);
	cout<<l1.number_of_nodes();
	cout<<(l1.nth_from_head(1))->data;
	return 0;
}
