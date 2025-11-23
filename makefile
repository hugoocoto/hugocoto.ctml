SRC := $(wildcard common/*.ctml src/*.ctml)
BRANCH := $(shell git rev-parse --abbrev-ref HEAD)

update:
	@git fetch
	@if ! git diff --quiet HEAD..origin/$(BRANCH); then \
		git pull --ff-only; \
	fi

run: wgen 
	./wgen

wgen: webgen/webgen.c $(SRC) webgen/build.c
	gcc webgen/webgen.c -o wgen -Icommon -Isrc
