##
## EPITECH PROJECT, 2024
## CPP-ECS
## File description:
## Makefile
##

LIBGROUPS				=	pure world

ALLMKFILES				=	./pure/base/Makefile \
							./pure/cuda/Makefile \
							./pure/simd/Makefile \
							./world/base/Makefile \
							./world/plane/Makefile \
							./world/space/Makefile

VALGRIND				=	valgrind \
							--leak-check=full \
							--show-leak-kinds=all \
							--track-origins=yes

all: $(LIBGROUPS)

$(LIBGROUPS):
	$(MAKE) -C $@

grind:
	$(foreach lib, $(LIBGROUPS), $(MAKE) -C $(lib) grind;)

sanitize:
	$(foreach lib, $(LIBGROUPS), $(MAKE) -C $(lib) sanitize;)

unit_tests:
	$(foreach lib, $(LIBGROUPS), $(MAKE) -C $(lib) unit_tests;)

everything: all grind sanitize unit_tests

clean:
	$(foreach lib, $(LIBGROUPS), $(MAKE) -C $(lib) clean;)

fclean:
	$(foreach lib, $(LIBGROUPS), $(MAKE) -C $(lib) fclean;)

re:
	$(foreach lib, $(LIBGROUPS), $(MAKE) -C $(lib) re;)

compile_commands.json:
	bear -- make

binary_tests_run:
	echo "No binary tests"

tests_run:
	echo "No unit tests"

.PHONY: all $(LIBGROUPS) grind sanitize unit_tests everything clean fclean re
