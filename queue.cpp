#include<iostream>
using namespace std;

class node						//class node
{
	public:
	int data;
	node* link;
	node(int value)				//constructor
	{
		data=value;
		link=NULL:
	}
};

class queue
{
	node* front;
	node* end;
	queue()
	{
		front=NULL:
		end=NULL;
	}
	
	void enque(int val)					//enque
	{
		node* temp=new node(val);
		if(front==NULL)
		{
			front= temp;
			end=temp;
		}
		else
		{
			temp->next=front;
			front=temp;
		}
	}
	
	void deque()
	{
		if(front==NULL)
		{
			cout<<"error!the queue is already empty"<<endl;
		}
		else
		{
			 node* curr=front;
			 while(curr->link!=end)
			 {
			 	curr=curr->link;
			 }
			 node* temp= end;
			 end=curr;
			 end->link=NULL;
			 delete temp;
		}
	}
			
	

