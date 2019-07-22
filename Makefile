CC=clang++
CFLAGS=-Wall -Wextra -Werror
OBJS_CONTROLLER=GameOver.o FrameClock.o Input.o main.o time_util.o MainMenu.o GameController.o
OBJS_MODEL=AGameObjects.o Enemy.o Player.o Rocket.o World.o
OBJS_VIEW=
OBJS=$(addprefix Controller/, $(OBJS_CONTROLLER)) \
	 $(addprefix Model/, $(OBJS_MODEL)) \
	 $(addprefix View/, $(OBJS_VIEW))
RM=rm -rf
NAME=ft_retro

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lncurses

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
