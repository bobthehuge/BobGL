CC = gcc
CFLAGS = -Wall -Wextra -O3 -g `pkg-config --cflags --libs gl glfw3 glew` `pkg-config --cflags bobgl`
LDFLAGS = `pkg-config --libs gl glfw3 glew` `pkg-config --cflags bobgl`

SRC = bobgl.c
OBJ = ${SRC:.c=.o}

all: comp pack clean

install: comp pack
	echo "Installation done !" 
	echo "Don't forget to add current path to lib to 'PKG_CONFIG_PATH'"

comp:
	$(CC) $(CFLAGS) -c src/$(SRC) -o lib/$(OBJ)

pack:
	ar rcs ./lib/libbobgl.a ./lib/$(OBJ)

clean:
	$(RM) ./lib/$(OBJ)
# END
