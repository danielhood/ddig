ddig Build Notes
================

Prerequisites: boost v1.54.0

Build:

	g++ -lboost_filesystem -lboost_iostreams ddig.cc -oddig

Above repalced by makefile.

This application ended up being a utility to search for RIFF and other aspects of a TASCAM drive dump that had undergone a partial reformat (partition and FAT tables were lost).  
The goal was to extract as much data from the drive as posible. It turned out that only RIFF files were identifiable.  
The bulk of the tascam takes were simply dupmed into 1GB file dumps with a WAV header placed on them via sox (see process.sh).
This produced decent results, howver some of the raw takes involving more than 1 channel simultaneously recording, interleaved their channel data.  This would require additonal processing to break out. It is assumed that this interlaving was done 1 cluster for each pass (4K chunks).

