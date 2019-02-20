#include "vm.h"

namespace VM
{
	VirtualMachine::VirtualMachine()
	{
		this->is_executing = true;
	}

	bool VirtualMachine::ReadInstructions(const std::string &file_name)
	{
		std::ifstream instructions_file(file_name.c_str());

		if (!instructions_file)
		{
			std::cout << "Cannot open the instruction file : " << file_name.c_str() << std::endl;
			return false;
		}

		this->instructions_list.clear(); // In-case somebody tries to read it again.

		std::string line, instruction, value;

		while (std::getline(instructions_file, line))
		{
			std::istringstream ss(line);

			if (!static_cast<bool>(ss >> instruction))
			{
				instruction = "-1";
			}

			if (!static_cast<bool>(ss >> value))
			{
				value = '0';
			}

			this->instructions_list.push_back({ std::stoi(instruction), std::stoi(value) });
		}

		instructions_file.close();
		return true;
	}

	void VirtualMachine::ExecuteInstructions()
	{
		if(!instructions_list.empty())
		{
			for (instructions_read & instructions : this->instructions_list)
			{
				switch (instructions.instruction)
				{
					case Instructions::PUSH:
					{
						std::cout << "VM: " << instructions.value << " pushed into stack." << std::endl;
						stack.push_back(instructions.value);
						break;
					}
					case Instructions::POP:
					{
						std::cout << "VM: Popped " << stack[stack.size() - 1] << std::endl;
						stack.pop_back();
						break;
					}
					case Instructions::ADD:
					{
						int a = stack[stack.size() - 1];
						stack.pop_back();
						int b = stack[stack.size() - 1];
						stack.pop_back();

						std::cout << "VM: ADD (" << a << " + " << b << ')' << std::endl;

						stack.push_back(a + b);
						break;
					}
					case Instructions::NOP:
					{
						std::cout << "VM: NOP" << std::endl;
						break;
					}
					case Instructions::HALT:
					{
						std::cout << "VM: Program halted." << std::endl;
						this->is_executing = false;
						break;
					}
					default:
					{
						std::cout << "VM: Unknown instruction skipped." << std::endl;
						break;
					}
				}
			}
		}
	}
};