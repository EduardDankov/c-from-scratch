.PHONY: all src clean

BUILD_DIR = build

all: src

src:
	$(MAKE) -C src

clean:
	rm -rf $(BUILD_DIR)
