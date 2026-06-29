winfetch: src/main.c src/sysinfo.c src/hardware.c src/memory.c
	mkdir -p bin
	gcc $^ -o bin/$@ -ladvapi32