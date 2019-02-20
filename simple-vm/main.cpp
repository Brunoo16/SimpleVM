#include "main.h"

int main() 
{
	VM::VirtualMachine vm;
	if (vm.ReadInstructions("test.vm"))
	{
		while (vm.IsExecuting())
		{
			vm.ExecuteInstructions();
		}
	}
}