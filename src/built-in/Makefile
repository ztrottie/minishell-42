all:
	@$(MAKE) -sC echo/
	@$(MAKE) -sC env/
	@$(MAKE) -sC exit/
	@$(MAKE) -sC export/
	@$(MAKE) -sC pwd/
	@$(MAKE) -sC unset/

clean:
	@$(MAKE) -sC echo/ clean
	@$(MAKE) -sC env/ clean 
	@$(MAKE) -sC exit/ clean
	@$(MAKE) -sC export/ clean
	@$(MAKE) -sC pwd/ clean
	@$(MAKE) -sC unset/ clean

fclean:
	@$(MAKE) -sC echo/ fclean
	@$(MAKE) -sC env/ fclean
	@$(MAKE) -sC exit/ fclean
	@$(MAKE) -sC export/ fclean
	@$(MAKE) -sC pwd/ fclean
	@$(MAKE) -sC unset/ fclean

re: fclean all

.PHONY: all clean fclean re
