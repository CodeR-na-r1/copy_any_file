#include "Any_file.h"

Any_file::Any_file(const char* name, Type type)
{
	if (type == Type::input)
		this->file.open(name, std::ios::binary | std::ios::in);
	else
		this->file.open(name, std::ios::binary | std::ios::out);

	this->type = type;
	
	this->iterator = 0;

	this->file.seekg(0, std::ios::end);
	this->size = this->file.tellg();
	this->file.seekg(0, std::ios::beg);

	return;
}

bool Any_file::init() const
{
	if (this->file.is_open())
		return false;

	this->type = Type::error;

	return true;
}

bool Any_file::get_data(char* bufer, const signed long long int size)
{
	if (this->type != Type::input)
		return true;

	signed long long int length = ((this->size - this->iterator) <= size) ? this->size - this->iterator : size;
	signed long long int i = 0;

	for (; i < length; ++i)
	{
		file.read(bufer + i, sizeof(char));
	}

	this->iterator += i;

	return this->iterator == this->size;
}

bool Any_file::write_data(const char* bufer, const signed long long int size)
{
	if (this->type != Type::output)
		return true;

	file.write(bufer, size);

	this->size += size;

	return false;
}

signed long long int Any_file::get_size() const
{
	return this->size;
}

Any_file::~Any_file()
{
	file.close();
}