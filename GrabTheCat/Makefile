all:
	gcc -Iinclude/ src/app.c src/camera.c src/main.c src/scene.c src/texture.c src/utils.c src/cat.c src/bus.c src/ground.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lobj -lfreeglut -lglut32 -lglu32 -lopengl32 -lm -o grabthecat.exe -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ src/app.c src/camera.c src/main.c src/scene.c src/texture.c src/utils.c src/cat.c src/ground.c -lobj -lSDL2 -lSDL2_image -lGL -lm -o cube -Wall -Wextra -Wpedantic
