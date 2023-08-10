BIN_DIR		=	bin/

all: $(BIN_DIR)
	@$(MAKE) -sC echo/
	@$(MAKE) -sC env/
	@$(MAKE) -sC export/
	@$(MAKE) -sC pwd/
	@$(MAKE) -sC unset/
	@$(MAKE) -sC cd/

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	@$(MAKE) -sC echo/ clean
	@$(MAKE) -sC env/ clean 
	@$(MAKE) -sC export/ clean
	@$(MAKE) -sC pwd/ clean
	@$(MAKE) -sC unset/ clean
	@$(MAKE) -sC cd/ clean

fclean:
	@$(MAKE) -sC echo/ fclean
	@$(MAKE) -sC env/ fclean
	@$(MAKE) -sC export/ fclean
	@$(MAKE) -sC pwd/ fclean
	@$(MAKE) -sC unset/ fclean
	@$(MAKE) -sC cd/ fclean
	@rm -fr $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re
