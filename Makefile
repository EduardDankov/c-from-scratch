.PHONY: all src tests clean

BUILD_DIR = build
BUILD_TESTS_DIR = build-tests

all: src tests

src:
	$(MAKE) -C src

tests:
	$(MAKE) -C tests

clean:
	$(MAKE) -C src clean
	$(MAKE) -C tests clean
