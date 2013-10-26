#include "ddig.h"
#include "fatheader.h"

// Application scrapes "RIFF" files from a drive image.
// This was written to salvage audio files after a Tascam unit reformatted the main drive
// and nuked the partition and FAT tables.
//
// Usage: ddig <file.img>
// 	The application scans for all "RIFF" tags, extracts the size of the file, and 
// 	copys it to a new file named in the format "RIFF_0000.wav"
//
// Command to view the raw data of the drive up to the first RIFF file:
// 	od -Ax -tx1 -N 0x81c000 samsung_dump_40gb.img
//
// Conversion from native raw format:
// 	sox -r44100 -s -c1 -2 test.raw test.wav
//
// Snippit of a raw audio section:
// 	dd if=samsung_dump_40gb.img of=test.raw skip=42877 count=10000
//
using namespace boost;
using namespace boost::iostreams;
using namespace std;

int main(int argc, char **argv)
{
	cout << "Loading file..." << argv[1] << endl;
	mapped_file_source src(argv[1]);

	if (src.is_open())
	{
		find_riff_entries(src, false);
		//find_dir_entries2(src, false);
		//find_wav_entries(src, false);
		src.close();
	}

	return 1;
}

template <typename IntegerType>
IntegerType bytesToInt( IntegerType& result, const unsigned char* bytes, bool little_endian = true )
  {
  result = 0;
  if (little_endian)
    for (int n = sizeof( result )-1; n >= 0; n--)
	result = (result << 8) +bytes[ n ];
  else
    for (unsigned n = 0; n < sizeof( result ); n++)
      result = (result << 8) +bytes[ n ];
  return result;
  }


void find_riff_entries(mapped_file_source src, bool save_to_file)
{
	unsigned int fileCount = 0;
	unsigned long fileSize = src.size();
	const char* data = src.data();
	for (unsigned long i = 0; i<fileSize-4; i++)
	{
		if (strncmp(data+i, "RIFF", 4) == 0)
		{
			//cout << "RIFF at " << hex << i << endl;
			uint32_t riff_size;
			bytesToInt<uint32_t>(riff_size, (const unsigned char*)data+i+4);
			//cout << dec << riff_size << endl;

			char fileName[100];
			sprintf(fileName, "RIFF_%03d.wav", fileCount);

			if (save_to_file)
			{
				file_sink riffFile(fileName, BOOST_IOS::binary);
				riffFile.write(data+i, riff_size+8);
				riffFile.close();
			}

			cout << hex << i << ":" << i+riff_size+8 << " - " << fileName << endl; 
			fileCount++;

		}
	}


}

void find_dir_entries(mapped_file_source src, bool save_to_file)
{
	unsigned int fileCount = 0;
	unsigned long fileSize = src.size();
	const char* data = src.data();
	for (unsigned long i = 0; i<fileSize-8; i++)
	{
		if (strncmp(data+i, ".       ", 8) == 0)
		{
			cout << "Directory at " << hex << i << endl;

			if (save_to_file)
			{
			}
		}
	}


}

void find_dir_entries2(mapped_file_source src, bool save_to_file)
{
	unsigned int fileCount = 0;
	unsigned long fileSize = src.size();
	const char* data = src.data();
	for (unsigned long i = 0; i<fileSize; i+=0x20)
	{
		if ((unsigned char)data[i] == (unsigned char)0xe5)
		{
			cout << "Directory entry at " << hex << i << endl;

			if (save_to_file)
			{
			}
		}
	}


}

void find_wav_entries(mapped_file_source src, bool save_to_file)
{
	unsigned int fileCount = 0;
	unsigned long fileSize = src.size();
	
	fileSize = 0x43bd00000;

	const char* data = src.data();

	int stats[4096];

	for (int i=0; i<4096; i++) stats[i] = 0;

	char bytes_to_find[] = {0x44 ,0xac};

	for (unsigned long i = 0; i<fileSize-4; i++)
	{
		//if (memcmp(data+i, ".\0W\0A\0V\0", 8) == 0)
		//if (memcmp(data+i, ".WAV", 4) == 0)
		if (memcmp(data+i, bytes_to_find, 2) == 0)
		{
			cout << "44100 found at " << hex << i << endl;

			stats[i&0x000000FF]++;

			if (save_to_file)
			{
			}
		}
	}

	for (int i=0; i<4096; i++) {
		if (stats[i] >= 20)
		{
			cout << "Offset: " << hex << i << " Count: " << stats[i] << endl;
		}
	}

}

void process_fat_header(mapped_file_source src)
{
	fatheader* fh = new fatheader();
	if (!fh->init(src)) 
	{
		cout << "Error: fathdear->Init() FAILED" << endl;
	}
	else
	{
		cout << "MBR Sig: "  << hex << int(fh->get_byte(0x1fe)) << hex << int(fh->get_byte(0x1ff)) << endl;
		cout << "VBR Sig: "  << hex << int(fh->get_byte(0x3fe)) << hex << int(fh->get_byte(0x3ff)) << endl;
		cout << "Size: " << fh->get_size() << endl;
		cout << "OEM Name: " << fh->oem_name << endl;
	}

	delete fh;
}	

