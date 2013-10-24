#include "fatheader.h"

fatheader::fatheader(){}

fatheader::~fatheader() {}

bool fatheader::init(mapped_file_source& fat_file)
{
	_fat_file = fat_file;	
	//strncpy(oem_name, "test\n", 8);
	process_boot_sector();
	return true;
}

long fatheader::get_size()
{
	return _fat_file.size();
}

uint8_t fatheader::get_byte(long index)
{
	const char* data =  _fat_file.data();
	return (uint8_t)data[index];
}

void fatheader::process_boot_sector()
{
	const char* data = _fat_file.data();
	strncpy(oem_name, data+3+512, 8);
	oem_name[8] = 0;
}

