##
## EPITECH PROJECT, 2024
## CPP-ECS
## File description:
## Makefile
##

LIBS				=	base plane space

all:					$(LIBS)

$(LIBS):
	$(MAKE) -C $@

grind:				
	$(foreach lib, $(LIBS), $(MAKE) -C $(lib) grind;)

sanitize:
	$(foreach lib, $(LIBS), $(MAKE) -C $(lib) sanitize;)

unit_tests:
	$(foreach lib, $(LIBS), $(MAKE) -C $(lib) unit_tests;)

clean:
	$(foreach lib, $(LIBS), $(MAKE) -C $(lib) clean;)

fclean:
	$(foreach lib, $(LIBS), $(MAKE) -C $(lib) fclean;)

re:
	$(foreach lib, $(LIBS), $(MAKE) -C $(lib) re;)

.PHONY: all $(LIBS) grind sanitize unit_tests clean fclean re
