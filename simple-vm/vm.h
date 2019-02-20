#ifndef _VM_H_
#define _VM_H_

#include "main.h"

namespace VM
{
	enum Instructions 
	{
		PUSH,
		POP,
		ADD,	
		NOP,
		HALT
	};

	class VirtualMachine
	{
		private:
			struct instructions_read
			{
				int instruction;
				int value;
			};

			bool is_executing;
			std::vector<int> stack;
			std::vector<instructions_read> instructions_list;

		public:
			VirtualMachine();

			inline bool IsExecuting()
			{
				return is_executing;
			}

			bool ReadInstructions(const std::string &file_name);
			void ExecuteInstructions();
	};
};

#endif