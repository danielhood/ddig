dd if=samsung_dump_40gb.img of=160000600.raw skip=11534339 count=1966080
dd if=samsung_dump_40gb.img of=190000600.raw skip=13107203 count=1966080
dd if=samsung_dump_40gb.img of=1c0000600.raw skip=14680067 count=1966080
dd if=samsung_dump_40gb.img of=1f0000600.raw skip=16252931 count=1966080
dd if=samsung_dump_40gb.img of=220000600.raw skip=17825795 count=1966080
dd if=samsung_dump_40gb.img of=250000600.raw skip=19398659 count=1966080
dd if=samsung_dump_40gb.img of=280000600.raw skip=20971523 count=1966080
dd if=samsung_dump_40gb.img of=2a0000600.raw skip=22544387 count=1966080
dd if=samsung_dump_40gb.img of=2d0000600.raw skip=24117251 count=1966080
dd if=samsung_dump_40gb.img of=300000600.raw skip=25690115 count=1966080
dd if=samsung_dump_40gb.img of=330000600.raw skip=27262979 count=1966080
dd if=samsung_dump_40gb.img of=360000600.raw skip=28835843 count=1966080
dd if=samsung_dump_40gb.img of=390000600.raw skip=30408707 count=1966080
dd if=samsung_dump_40gb.img of=3c0000600.raw skip=31981571 count=1966080
dd if=samsung_dump_40gb.img of=3f0000600.raw skip=33554435 count=1966080
dd if=samsung_dump_40gb.img of=420000600.raw skip=35127299 count=923656
sox -r44100 -s -c1 -2 160000600.raw 160000600.wav
sox -r44100 -s -c1 -2 190000600.raw 190000600.wav
sox -r44100 -s -c1 -2 1c0000600.raw 1c0000600.wav
sox -r44100 -s -c1 -2 1f0000600.raw 1f0000600.wav
sox -r44100 -s -c1 -2 220000600.raw 220000600.wav
sox -r44100 -s -c1 -2 250000600.raw 250000600.wav
sox -r44100 -s -c1 -2 280000600.raw 280000600.wav
sox -r44100 -s -c1 -2 2a0000600.raw 2a0000600.wav
sox -r44100 -s -c1 -2 2d0000600.raw 2d0000600.wav
sox -r44100 -s -c1 -2 300000600.raw 300000600.wav
sox -r44100 -s -c1 -2 330000600.raw 330000600.wav
sox -r44100 -s -c1 -2 360000600.raw 360000600.wav
sox -r44100 -s -c1 -2 390000600.raw 390000600.wav
sox -r44100 -s -c1 -2 3c0000600.raw 3c0000600.wav
sox -r44100 -s -c1 -2 3f0000600.raw 3f0000600.wav
sox -r44100 -s -c1 -2 420000600.raw 420000600.wav
