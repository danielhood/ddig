#include <boost/iostreams/device/mapped_file.hpp>
#include <iostream>

using namespace boost;
using namespace boost::iostreams;

class fatheader
{
public:
	fatheader();
	~fatheader();

public:
	bool init(mapped_file_source& fat_file);
	long get_size();
	uint8_t get_byte(long index);

public:
	char oem_name[9];

private:
	mapped_file_source _fat_file;

	void process_boot_sector();

};
