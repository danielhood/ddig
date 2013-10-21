#include <boost/iostreams/device/mapped_file.hpp>
#include <iostream>

lsing namespace boost;
using namespace boost::iostreams;

class fatheader
{
public:
	fatheader();
	~fatheader();

public:
	bool init(mapped_file_source& fat_file);
	long get_size();

public:
	char[8] oem_name();

private:
	mapped_file_source _fat_file;


};
