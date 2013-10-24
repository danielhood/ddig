#include "ddig.h"
#include "fatheader.h"

using namespace boost;
using namespace boost::iostreams;
using namespace std;

int main(int argc, char **argv)
{
	cout << "Loading file..." << argv[1] << endl;
	mapped_file_source src(argv[1]);

	fatheader* fh = new fatheader();
	if (!fh->init(src)) 
	{
		cout << "Error: fathdear->Init() FAILED" << endl;
	}
	else
	{
		cout << "Sig: "  << hex << int(fh->get_byte(0x1fe)) << hex << int(fh->get_byte(0x1ff)) << endl;
		cout << "Size: " << fh->get_size() << endl;
		cout << "OEM Name: " << fh->oem_name << endl;
	}

	delete fh;
	

	return 1;
}
