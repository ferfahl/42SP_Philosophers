################################################################################
##                               42 PUSH SWAP                                 ##
################################################################################

#static library's name
NAME =		philo
B_NAME =	philo_bonus

ARGS = 5 800 200 200 7

#colors
RESET 			:= \033[0m
GREEN			=	\e[32m
CYAN  			:= \33[1;36m
YELLOW			=	\e[033m
BLUE			=	\e[34m
WHITE			=	\e[00m

#printing
LOG   			:= printf "[$(GREEN)PROJECT_INFO$(RESET)] %s\n"
LOG_SUC			:= printf "[$(CYAN)COMPILING_INFO$(RESET)] %s\n"

################################################################################
##                                DIRECTORIES                                 ##
################################################################################

#scr functions
SRCS =				01_main.c				\
					02_validate_input.c		\
					libft_funct.c			\

BONUS_FILES =

HEADER =			/include/philo.h

#directories
VPATH =				srcs
OBJPATH =			temps


#header to libft.h
INCLUDE =	-I ./ -I 

################################################################################
##                                 COMPILATION                                ##
################################################################################

#compiling
CC =	gcc
FLAGS =	-Wall -Werror -Wextra -g3
GDB =	gdb
VAL =	valgrind --leak-check=full --track-origins=yes
## --trace-children=yes --track-fds=yes

# clean
RM =		-rm -f
RM_DIR =	rm -rf

#tranform into .o
OBJ_MANDATORY = $(SRCS:%.c=$(OBJPATH)/%.o)
OBJ_BONUS = $(BONUS_FILES:%.c=$(OBJPATH)/%.o)

#compiling bar
NUMBER_OF_FILES	=	$(words $(SRCS))	
PROGRESS			=	0

################################################################################
##                                    RULES                                   ##
################################################################################

#make
all: $(OBJPATH) $(NAME)

#make bonus
bonus: $(OBJPATH) $(B_NAME)

##folder for temporary objects
$(OBJPATH):
		@$(LOG) "Creating objects directory..."
		@mkdir -p $(OBJPATH)

##rule name - make philo
$(NAME): $(OBJ_MANDATORY)
		@cc $(FLAGS) -o $(NAME) $(OBJ_MANDATORY) 
		@$(LOG_SUC) "*$(NAME) succesfully compiled!"

##rule name - make philo_bonus
$(B_NAME): $(OBJ_BONUS)
		@cc $(FLAGS) -o $(B_NAME) $(OBJ_BONUS) 

##compile MANDATORY
$(OBJPATH)/%.o: $(VPATH)/%.c $(HEADER)
		@cc $(FLAGS) -c $< -o $@ $(INCLUDE)
		@echo -n "$(YELLOW)Compiling ${NAME} $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_FILES)))%\r"
		$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))

##compile BONUS
$(OBJPATH)/%.o: $(BONUS_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#make val -> mcheck
val:
		$(VAL) ./$(NAME) $(ARGS)

#make vdrd -> check Data Race Detector
vdrd:
		valgrind --tool=helgrind ./$(NAME) $(ARGS)

#make hell -> data race conditions & deadlock
hell:
		valgrind --tool=helgrind ./$(NAME) $(ARGS)

#make clean -> remove objects
clean:
		@$(LOG) "Removing objects..."
		@$(RM) $(OBJ_MANDATORY) $(OBJ_BONUS)

#make fclean -> remove all
fclean: clean
		@$(LOG) "Removing executable..."
		@$(RM) $(NAME) $(B_NAME)
		@$(RM_DIR) $(OBJPATH)
		@$(LOG_SUC) "Cleaned project!"

#make re -> clear all and recompliles
re:		fclean all
		@$(LOG_SUC) "Recompiled succesfully!"

##avoids double inclusion
.PHONY: all clean fclean re bonus

#make git m="message" -> commit to git
git:
		git add .
		git commit -m "$(m)"
		git push

norm:
		clear
		@norminette ${addprefix ${VPATH}/, ${SRCS}}			 | grep -v "OK!" || echo "All files ok!"

