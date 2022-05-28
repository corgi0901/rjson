TARGET=librjson.so

all: *.c
	gcc -shared -O2 -o ${TARGET} *.c

clean:
	rm ${TARGET}
