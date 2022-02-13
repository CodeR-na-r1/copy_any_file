#include "iostream"
#include "Any_file.h"

using namespace std;

int main()
{
	Any_file file("file.jpg.", Type::input);
	Any_file out_file("out_file.jpg", Type::output);
	
	char* bufer = new char[file.get_size()];

	file.get_data(bufer, file.get_size());

	out_file.write_data(bufer, file.get_size());

	delete[] bufer;

	return 0;
}