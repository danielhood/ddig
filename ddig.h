#include <boost/iostreams/device/mapped_file.hpp>
#include <boost/iostreams/device/file.hpp>
#include <iostream>

#ifndef _DDIG_H
#define _DDIG_H

using namespace boost::iostreams;

void find_riff_entries(mapped_file_source src, bool save_to_file);
void find_dir_entries(mapped_file_source src, bool save_to_file);
void find_dir_entries2(mapped_file_source src, bool save_to_file);
void find_wav_entries(mapped_file_source src, bool save_to_file);

#endif
