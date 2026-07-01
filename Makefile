winfetch: src/main.c src/sysinfo.c src/hardware.c src/memory.c src/battery.c
	mkdir -p bin
	gcc $^ -o bin/$@ -ladvapi32 -lpowrprof