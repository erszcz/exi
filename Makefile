all: exip-0.5.4/bin/lib/libexip.so

exip-0.5.4.tar.gz:
	wget http://downloads.sourceforge.net/project/exip/exip-0.5.4.tar.gz

exip-0.5.4: exip-0.5.4.tar.gz
	tar xfz exip-0.5.4.tar.gz

exip-0.5.4/bin/lib/libexip.so: exip-0.5.4
	cd $</build/gcc; make dynlib
