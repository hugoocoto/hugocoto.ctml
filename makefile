SRC := $(wildcard *.ctml *.html)

run: webgen
	./webgen

webgen: webgen.c $(SRC)
	gcc webgen.c -o webgen
