CC = gcc
CFLAGS = -Wall -Wextra -O3 `pkg-config --cflags --libs gl glfw3 glew` `pkg-config --cflags bobgl`
LDFLAGS = `pkg-config --cflags --libs gl glfw3 glew` `pkg-config --cflags bobgl`

SRC = bobgl.c
OBJ = ${SRC:.c=.o}

all: comp pack clean

install: comp pack
	echo "Installation done !" 
	echo "Don't forget to add current path to lib to 'PKG_CONFIG_PATH'"

comp:
	$(CC) $(CFLAGS) -c bobgl.c -o lib/bobgl.o

pack:
	ar rcs ./lib/libbobgl.a ./lib/bobgl.o

clean:
	${RM} ./lib/bobgl.o
# END
