TARGET = bin/main
FLAGS = -std=c99 -Wall -Werror -Wextra -fstack-protector

DOSSIER = Shape_and_Other


SRCS = main.c $(DOSSIER)/Main_function/creation.c $(DOSSIER)/Menus/main_menus.c $(DOSSIER)/Shape/shape.c $(DOSSIER)/Shape/Shape_modifier/color.c $(DOSSIER)/Shape/Shape_modifier/node.c

build:
	gcc $(SRCS) -o $(TARGET) $(FLAGS)

run:
	./$(TARGET)

clean:
	rm $(TARGET)