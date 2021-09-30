#include<iostream>
using namespace std;

template <class T>
class node{
	public: 
	
		T v; // data
		node<T> *next; // pointer to next node
		
		node(T x)
		{
			v = x;
			next = NULL;
		}
		
};

template <class T>
class my_queue{
	
	node<T> *start,*start2;
	node<T> *end,*end2; 
	
	public:
		
		my_queue()
		{
			start = end = NULL;
            start2 = end2 = NULL;

		}
		
		// returns true if queue is empty
		bool empty()
		{
			return start==NULL;
		}

        // returns the size of the queue
        void size()
        {
          node<T> *tmp = start;
          int counter = 0;

          while(tmp!= NULL)
          {
            counter++;
            tmp = tmp->next;
          }

          cout<<counter;
        }
		
		// insert v at the end of the queue
		void push(T v)
		{
			node<T> *temp = new node<T>(v); //creating new node and storing its address in temp
			if(empty())
			{
				start = end = temp;
			}
			else
			{
				end->next = temp;
				end = temp;
			} 
			
		}

        // emplaces an element at the end of the queue
        void emplace(T v)
		{
			node<T> *temp = new node<T>(v); //creating new node and storing its address in temp
			if(empty())
			{
				start = end = temp;
			}
			else
			{
				end->next = temp;
				end = temp;
			} 
			
		}
		
		// retuns the first element of the queue
		T front()
		{
			if(empty())
				return NULL;
			else
				return start->v;	
		} 

        // returns the last element of the queue
        T back()
		{
			if(empty())
				return NULL;
			else
				return end->v;	
		} 
	
		// removes the first element of the queue
		void pop()
		{
			if(empty())
			{
				cout<<"Queue is Empty"<<endl;
			}
			else if(start==end)
			{
				// there is only 1 element in the queue
				delete start;
				start = end = NULL;
			}
			else
			{
				// if there are more than 1 element in the queue
				node<T> *temp = start;
				start = start->next;
				delete temp;
			}
		}		
	
};

void showq(my_queue<string> queue)
{
    my_queue<string> q = queue;
    while(!q.empty()){
        cout << q.front();
        q.pop();
    }
}

int main()
{
	my_queue<string> q;

    q.push("Hello");
    q.push("World");
	
	cout<<"Queue Front: "<<q.front()<<endl;
    cout<<"Queue Back: "<<q.back()<<endl;

    q.emplace("!!!\n");
	
	q.push("My");
	q.push("Name");
	q.push("Is");
	q.push("John");
	q.push("Smith");
	
	showq(q);
}