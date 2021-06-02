#include <iostream>
#include <string>

using namespace std;

template <typename T>
int find(T arr[], int n, T obj)
{
	for(int i = 0; i < n; i++)
		if(arr[i] == obj)
			return i;
	return - 1;
}

int main(void)
{
	string a[] = {"asd","asdd","dsa","ddd"};
	string b = "asdd";

	cout << find(a,6,b) << endl;

	return 0;
}