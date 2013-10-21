#include "fatheader.h"

fatheader::fatheader(){}

fatheader::~fatheader() {}

bool fatheader::init(mapped_file_source& fat_file)
{
	_fat_file = fat_file;
	return true;
}

long fatheader::get_size()
{
	return _fat_file.size();
}

