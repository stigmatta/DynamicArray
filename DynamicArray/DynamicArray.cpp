#include "DynamicArray.h"
#include<Windows.h>

DynamicArray::DynamicArray():ptr(nullptr),size(0)
{}
DynamicArray::DynamicArray(int S)
{
	cout << "Construct by 1 param\n";
	size = S;
	ptr = new int[S];	
}

DynamicArray::DynamicArray(const DynamicArray & a)// copy constructor
{
	cout << "Copy construct\n";
	size = a.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = a.ptr[i];
	}
}
DynamicArray::~DynamicArray()
{
	cout << "Destruct\n";
	if (ptr != 0)
	{
		delete[] ptr;
    }
	Sleep(1000);
}
void DynamicArray::Input()
{
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % 20;
	}
}
void DynamicArray::Output() const
{
	for (int i = 0; i < size; i++)
	{
		cout<<ptr[i] <<"\t";
	}
	cout << "\n---------------------------------\n";
}
int * DynamicArray::GetPointer() const
{
	return ptr;
}
int DynamicArray::GetSize()const
{
	return size;
}
void DynamicArray::ReSize(int size)
{
	this->size = this->size + size;
	int * tmp = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		if (i < (this->size - size))
			tmp[i] = this->ptr[i];
		else
			tmp[i] = 0;
	}
	if (this->ptr != nullptr)
		delete[]this->ptr;
	this->ptr= new int[this->size];
	this->ptr = tmp;

}
void DynamicArray::Sort()
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (ptr[j] > ptr[j - 1])
				swap(ptr[j], ptr[j - 1]);
		}
	}
}
int DynamicArray::Search(int a)
{
	for (int i = 0; i < this->size; i++)
	{
		if (ptr[i] == a)
			return i;
	}
	return -1;
}
void DynamicArray::Reverse()
{
	for (int i = 0; i < this->size/2; i++)
	{
		swap(ptr[i], ptr[this->size - i-1]);
	}
}