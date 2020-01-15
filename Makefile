NAME = pathfinder
INC = ./inc/header.h
INCLIB = ./libmx/inc/libmx.h
HEADTMP = ./header.h ./libmx.h

SRC = ./main.c ./mx_atoi.c ./mx_city_init.c ./mx_city_push.c 				\
	./mx_city_push.c ./mx_free_all.c ./mx_helper_restor.c 					\
	./mx_init.c ./mx_is_alpha.c ./mx_is_digit.c 							\
	./mx_make_Floyd_matrix.c ./mx_parse_all_lines.c 						\
	./mx_print_all_error.c ./mx_print_err.c ./mx_print_line.c 				\
	./mx_print_path.c ./mx_push_in_AM.c ./mx_read_file.c 					\
	./mx_pop_from_stack.c ./mx_push_in_stack.c 								\
	./mx_top_from_stack.c ./mx_matrix_index.c											

SRCS = ./src/main.c ./src/mx_atoi.c ./src/main.c ./src/mx_atoi.c 			\
	./src/mx_city_init.c ./src/mx_city_push.c 								\
	./src/mx_city_push.c ./src/mx_free_all.c ./src/mx_helper_restor.c 		\
	./src/mx_init.c ./src/mx_is_alpha.c 									\
	./src/mx_is_digit.c ./src/mx_make_Floyd_matrix.c 						\
	./src/mx_parse_all_lines.c ./src/mx_print_all_error.c 					\
	./src/mx_print_err.c ./src/mx_print_line.c 								\
	./src/mx_print_path.c ./src/mx_push_in_AM.c ./src/mx_read_file.c 		\
	./src/mx_pop_from_stack.c ./src/mx_push_in_stack.c 						\
	./src/mx_top_from_stack.c ./src/mx_matrix_index.c											
	 
OBJ = ./main.o ./mx_atoi.o ./mx_city_init.o ./mx_city_push.o 				\
	./mx_free_all.o ./mx_helper_restor.o 									\
	./mx_init.o ./mx_is_alpha.o ./mx_is_digit.o 							\
	./mx_make_Floyd_matrix.o ./mx_parse_all_lines.o 						\
	./mx_print_all_error.o ./mx_print_err.o ./mx_print_line.o 				\
	./mx_print_path.o ./mx_push_in_AM.o ./mx_read_file.o 					\
	./mx_pop_from_stack.o ./mx_push_in_stack.o 								\
	./mx_top_from_stack.o ./mx_matrix_index.o

OBJO = ./obj/main.o ./obj/mx_atoi.o 										\
	./obj/mx_city_init.o ./obj/mx_city_push.o 								\
	./obj/mx_free_all.o ./obj/mx_helper_restor.o 							\
	./obj/mx_init.o ./obj/mx_is_alpha.o 									\
	./obj/mx_is_digit.o ./obj/mx_make_Floyd_matrix.o 						\
	./obj/mx_parse_all_lines.o ./obj/mx_print_all_error.o 					\
	./obj/mx_print_err.o ./obj/mx_print_line.o 								\
	./obj/mx_print_path.o ./obj/mx_push_in_AM.o ./obj/mx_read_file.o 		\
	./obj/mx_pop_from_stack.o ./obj/mx_push_in_stack.o 						\
	./obj/mx_top_from_stack.o ./obj/mx_matrix_index.o										

CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install uninstall
install:
	@cd libmx && make -f Makefile install
	@cp $(INC) $(SRCS) .
	@cp $(INCLIB) . 
	@clang $(CFLGS) -c  $(SRC)
	@mkdir  obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)
uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj
	@rm -rf ./libmx/obj
clean: uninstall
	@cd libmx && make -f Makefile clean
	@rm -rf $(NAME)
reinstall: clean all

