INCLUDE_FILES=$(shell escript tools/get_included_files_h.erl)
CFLAGS_LINUX = -shared
CFLAGS_DARWIN = -undefined dynamic_lookup
CFLAGS_REST = -Iexip-0.5.4/bin/headers -l:exip-0.5.4/bin/lib/libexip.a -fPIC

ifeq ($(shell uname), Darwin)
	CFLAGS = $(CFLAGS_DARWIN) $(INCLUDE_FILES) $(CFLAGS_REST)
else
	CFLAGS = $(CFLAGS_LINUX) $(INCLUDE_FILES) $(CFLAGS_REST)
endif


all: compile run

exip-0.5.4.tar.gz:
	wget http://downloads.sourceforge.net/project/exip/exip-0.5.4.tar.gz

exip-0.5.4: exip-0.5.4.tar.gz
	tar xfz exip-0.5.4.tar.gz

exip-0.5.4/bin/lib/libexip.a: exip-0.5.4
	cd $</build/gcc; make dynlib

compile: priv/encoder_nif.so
	rebar compile

priv/encoder_nif.so: c_src/encoder.c c_src/encoder_nif.c exip-0.5.4/bin/lib/libexip.a
	@mkdir -p priv
	cc -o $@ $^ $(CFLAGS)

run:
	erl -pa $(PWD)/ebin/
