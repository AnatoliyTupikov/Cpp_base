void main()
{
	int* p = new int; // Operator new allocates memory on the heap
	*p = 42; // Assign value to allocated memory
	delete p; // Free allocated memory, but p is now a dangling pointer. We also can set or get from p after delete, which is bad practice.
	p = nullptr; // We should set p to nullptr after delete to avoid dangling pointer issues.

}