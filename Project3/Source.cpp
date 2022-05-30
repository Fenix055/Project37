#include <iostream>

void function(int* arr, int& size)
{
	delete[] arr;
	arr = new int[++size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = i;
	}

}

void SortShaker(int* l, int* r)
{
	for(int j=(r-l);j>0;j)
	{
		bool o = 0;
		int maxmin = 0;
		int index = 0;
		for(int i=(r-l)-j;i<j;i++)
		{
			if (l[i] > maxmin) { maxmin = l[i]; index = i; o = 1; }
		}
		j--;
		if (!o)break;
		if (o) {
			l[index] = l[j];
			l[j] = maxmin;
		}
		o = 0;
		for(int i=j-1;i>=0;i--)
		{
			if (l[i]<maxmin) { maxmin = l[i]; index = i; o = 1;}
		}
		j--;
		if (!o)break;
		if (o) {
			l[index] = l[r-l-j];
			l[r - l - j] = maxmin;
		}
	}
}

struct node
{
	int value;
    node* next;
};


class List {
	node* head;
	node* tail;
public:
	List() {
		head = tail = NULL;
	};
	~List() {
		DelAll();
	};
	void Push(int value) {
		node* temp = new node;
		temp->value = value;
		temp->next = NULL;
		if (head != NULL)
		{
			tail->next = temp;
			tail = temp;
		}
		else
		{
			head = tail = temp;
		}
	};
	void Pop() 
	{
		node* temp = head;
		std::cout << temp->value << " ";
		head = head->next;
		delete temp;
	};
	void DelAll()
	{
		while (head != NULL)
			Pop();
	};
	void Print()
	{
		node* temp=head;
		while(temp !=0)
		{
			std::cout << temp->value << " ";
			temp = temp->next;
		}
	}
};

int main()
{
	//int* arrs = new int[5]{ 5,9,1,3,6 };
	//int size = 5;

	///*function(arrs, size);*/

	//SortShaker(arrs, arrs + size);

	//for (int i = 0; i < size; i++)
	//	std::cout << arrs[i];

	List list;
	list.Push(3);
	list.Push(4);
	list.Push(6);
	list.Push(9);
	list.Push(1);
	list.Push(5);
	return 0;
}