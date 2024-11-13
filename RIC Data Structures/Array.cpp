

/*
Array as Data Structure
We can use an array as data structure. 
An array is a fixed size container which can contain different elements.
We can add ,show, update, find and remove different element to and from an array. 
In the given example i am working on integer type array for sake of simplisity. 
You can enhance as per your requirements.................

*/


#include<iostream>
using namespace std;
//add element
void insert(int arr[],int index, int value)
{
arr[index]=	value;
}
//update element
void update(int arr[],int index, int value)
{
arr[index]=	value;
}
//add element
void remove(int arr[],int index)
{
arr[index]=0;
}
void show(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i];
	    cout<<endl;
	}
	
	
}

void find(int arr[],int size, int value)
{
	
for(int i=0;i<size;i++)
	{
		if(arr[i]==value)
		{
			cout<<"Found";
	        cout<<endl;
	        break;
		}
		
	}	
}

main()
{
	int size=5;
	int arr[size]={0};//declare and initialize an array
	
	insert(arr,0, 10);
	

	insert(arr,1, 20);
	insert(arr,2, 30);
	insert(arr,3, 40);
	insert(arr,4, 50);
	
	find(arr,size,30);
	cout<<endl; //new line
	
	show(arr,size);
	
}
