all:
	@$(MAKE) -sC echo/
	@$(MAKE) -sC env/
	@$(MAKE) -sC export/
	@$(MAKE) -sC pwd/
	@$(MAKE) -sC unset/

clean:
	@$(MAKE) -sC echo/ clean
	@$(MAKE) -sC env/ clean 
	@$(MAKE) -sC export/ clean
	@$(MAKE) -sC pwd/ clean
	@$(MAKE) -sC unset/ clean

fclean:
	@$(MAKE) -C echo/ fclean
	@$(MAKE) -C env/ fclean
	@$(MAKE) -C export/ fclean
	@$(MAKE) -C pwd/ fclean
	@$(MAKE) -C unset/ fclean

re: fclean all

.PHONY: all clean fclean re
