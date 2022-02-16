#include "iostream"
#include "Any_file.h"
#include "Mytime.h"

using namespace std;

int main()
{
	Any_file file("file.docx", Type::input);
	if (!file.is_open())
	{
		std::cerr << "Error open input file" << std::endl;
		return -1;
	}

	Any_file out_file("out_file.docx", Type::output);
	if (!out_file.is_open())
	{
		std::cerr << "Error open output file" << std::endl;
		return -2;
	}

	char* bufer = new char[1024];

	int remains;
	Mytime time;
	while ((remains = file.get_data(bufer, 1024)))
	{
		out_file.write_data(bufer, remains);
	}
	time.output_time();
	std::cout << file.get_size() << std::endl;
	std::cout << out_file.get_size() << std::endl;
	std::cout << (file.get_size() == out_file.get_size());
	delete[] bufer;

	return 0;
}