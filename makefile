obj:=$(patsubst %.c, %.o, $(wildcard *.c))

file.exe: $(obj)
	gcc -o $@ $^
clean:
	rm *.o *.exe

