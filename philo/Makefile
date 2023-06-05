################################################################################
##                              42 PHILOSOPHERS                               ##
################################################################################

NAME			:= mandatory_philo

EXECUTABLE		:= philo

ARGS			:= 5 800 200 200 5

RESET			:= \033[0m
GREEN			:=	\e[32m
CYAN			:= \33[1;36m
YELLOW			:=	\e[033m
BLUE			:=	\e[34m
WHITE			:=	\e[00m

################################################################################
##                                 COMPILATION                                ##
################################################################################

#printing
LOG   			:= printf "[$(GREEN)PROJECT_INFO$(RESET)] %s\n"
LOG_SUC			:= printf "[$(CYAN)COMPILING_INFO$(RESET)] %s\n\r"

#compiling
CC		:=	cc
CFLAGS	:=	-Wall -Werror -Wextra -g3
GDB		:=	gdb
VAL		:=	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck

# clean
RM =		-rm -f
RM_DIR =	rm -rf

################################################################################
##                                DIRECTORIES                                 ##
################################################################################

OBJ_DIR			:=	temps
INC_DIRS		:=	include
SRC_DIRS		:=	$(addprefix philo/, $(SRC_DIRS))
SRC_DIRS		+=	srcs

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

HEADERS			:=	philo.h

SOURCES			:=	libft_funct.c			\
					01_main.c				\
					02_validate_input.c		\
					03_init.c				\
					04_routine.c			\
					utils.c					\
					testesf.c				\

#tranform into .o
OBJS			:=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

#compiling bar
NUMBER_OF_FILES	:=	$(words $(SOURCES))
PROGRESS		:=	0

################################################################################
##                                    RULES                                  ##
################################################################################

CFLAGS			:=	-Wall -Werror -Wextra -g $(addprefix -I,$(INC_DIRS))

all:			$(NAME)

$(NAME):		$(EXECUTABLE)

$(EXECUTABLE):	$(OBJS)
	@$(LOG_SUC) "Compiling $@..."
	@$(CC) $(CFLAGS) -lpthread $(OBJS) -o $@
	@$(LOG) "$@ compiled successfully!"

## -lrt  (para usar no philo depois do $^)

$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n "$(YELLOW)Compiling ${EXECUTABLE} $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_FILES)))%\r"
		$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))

$(OBJ_DIR):
	@$(LOG) "Creating objects directory"
	@mkdir $@
	@$(LOG_SUC) "Compiling objects..."

drd: $(NAME)
	valgrind --tool=drd ./$(EXECUTABLE) $(ARGS)

hell: $(NAME)
	valgrind --tool=helgrind ./$(EXECUTABLE) $(ARGS)

val: $(NAME)
	valgrind -q --leak-check=full --show-leak-kinds=all \
		--track-origins=yes ./$(EXECUTABLE) $(ARGS)

clean:
	@$(RM) -r $(OBJS)
	@$(LOG) "Removing objects"
	@$(RM) -r $(OBJ_DIR)
	@$(LOG) "Removing objects directory"

fclean: clean
	@$(LOG) "Removing $(EXECUTABLE)"
	@$(RM) -r $(EXECUTABLE)
	@$(LOG_SUC) "Cleaned project!"

re: fclean all

.PHONY: all clean fclean re

teste: $(NAME)
	./$(EXECUTABLE) $(ARGS)

#make git m="message" -> commit to git
git:
		git add .
		git commit -m "$(m)"
		git push

norm:
		clear
		@norminette ${addprefix ${SRC_DIRS}/, ${SOURCES}} | grep -v "OK!" || echo "All files ok!"
