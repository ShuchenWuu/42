NAME = a

$(NAME): $(NAME).o
	echo 123
	gcc -o a a.o

a.o: a.c
	echo 456
	gcc -c a.c

clean:
	rm -f $(NAME).o

fclean:
	rm -f $(NAME)
