#include "iostream"
#include <fstream>

using namespace std;

int main()
{
	const char* filename = "file.jpg";
	const char* output_filename = "Ouput_file.jpg";

	ifstream in;
	in.open(filename, ios::binary);
	if (!in.is_open())
	{
		cout << "File is not open!" << endl;
		return -1;
	}

	in.seekg(0, ios::end);
	int size_file{in.tellg()};
	in.seekg(0, ios::beg);
	cout << "Size of file = " << size_file << " bytes" << endl;
	
	unsigned char* temp_data = new unsigned char;
	
	ofstream out;
	out.open(output_filename, ios::binary);
	if (!out.is_open())
	{
		cout << "Output file is not open!" << endl;
		return -2;
	}

	for (int i = 0; i < size_file; ++i)
	{
		in.read((char*)temp_data, sizeof(*temp_data));
		out.write((const char*)temp_data, sizeof(*temp_data));
	}
	cout << "Ready" << endl;

	delete temp_data;
	in.close();
	out.close();
	system("pause");
	return 0;
}