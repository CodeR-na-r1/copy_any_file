#pragma once

#include <iostream>
#include <fstream>

enum class Type
{
	input,
	output,
	error
};

class Any_file
{
public:
	Any_file(const char* name, Type type);

	bool init() const;

	bool get_data(char* bufer, const signed long long int size);

	bool write_data(const char* bufer, const signed long long int size);

	signed long long int get_size() const;

	~Any_file();

private:
	Any_file() = delete;

	std::fstream file;
	mutable Type type;
	signed long long int size;
	signed long long int iterator;
};