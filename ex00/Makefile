# # Memo
# VAR = val: Normal setting - values within are recursively expand when var used.
# VAR := val: Setting of var with simple expansion of values inside - values are expanded at decl time.
# VAR ?= val: Set var only if it doesn't have a value.
# VAR += val: Append val to existing value (or set if var didn't exist).
#
# $@: name of the target file (one before colon)
# $<: name of first prerequisite file (first one after colon)
# $^: names of all prerequisite files (space separated)
# $*: stem (bit which matches the % wildcard in rule definition)

#-----------------------------------------------
# Output File
OUTPUT_DIR =	.
NAME = 				$(OUTPUT_DIR)/convert.a

# Directories
INCLUDES_DIR =	.
SOURCES_DIR =		.
OBJECTS_DIR =		objs

# Files
SOURCES =		./ScalarConverter.cpp ./main.cpp
INCLUDES =	$(patsubst $(SOURCES_DIR)/%.cpp, $(INCLUDES_DIR)/%.hpp, $(SOURCES))
OBJECTS =		$(patsubst $(SOURCES_DIR)/%.cpp, $(OBJECTS_DIR)/%.o, $(SOURCES))

# Compiler & Flags
CXX =				c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98
CPPFLAGS :=	-I $(INCLUDES_DIR)
MEMOLYFLAGS := -fsanitize=address -g3

#-----------------------------------------------
# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#-----------------------------------------------
# Rules
all:	$(NAME)

# Link Targets
$(NAME): $(OBJECTS)
	@printf "\r$(GREEN)[%2d/%2d]$(DEF_COLOR) All files compiled! Linking $(CYAN)$(NAME)$(DEF_COLOR)\033[K" \
		"$$(find $(OBJECTS) -type f | wc -l)" "$$(find $(SOURCES) \( -type l -o -type f \) | wc -l)"
	@$(CXX) $(CPPFLAGS) $^ -o $@
	@echo "\n$(GREEN)<-------- $(NAME) linked. -------------------------->$(DEF_COLOR)"
	@chmod 755 $(NAME)
	@echo "$(GREEN)<-------- $(NAME) permission changed. -------------->$(DEF_COLOR)"
	@echo "$(CYAN)######### $(NAME) compile finished! #################$(DEF_COLOR)"

# Compile Targets
$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp | $(OBJECTS_DIR)
	@printf "\r$(GREEN)[%2d/%2d]$(DEF_COLOR) Compiling objects: $(CYAN)%s$(DEF_COLOR)\033[K" \
		"$$(find $(OBJECTS_DIR) -type f | wc -l)" "$$(find $(SOURCES) \( -type l -o -type f \) | wc -l)" "$<"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

# Clean Targets
clean:
	@rm -rf $(OBJECTS)
	@rm -rfd $(OBJECTS_DIR)
	@echo "$(GRAY)<-------- $(NAME) object files cleaned. ------------>$(DEF_COLOR)"

fclean:	clean
	@rm -rf $(NAME)
	@echo "$(GRAY)<-------- $(NAME) executable files cleaned. -------->$(DEF_COLOR)"

re:		fclean all

update:	fclean
	make

# Phony
.PHONY = all clean fclean re update

#-----------------------------------------------
# Test Variables
TEST_DIR =		./test
TEST_SHELL =		$(TEST_DIR)/test.sh

.PHONY: test

test: $(NAME)
	@echo "$(BLUE)Running tests...$(DEF_COLOR)"
	@bash $(TEST_SHELL)

#-----------------------------------------------

debug:
	@echo "INCLUDES: $(INCLUDES)"
	@echo "SOURCES: $(SOURCES)"
	@echo "OBJECTS: $(OBJECTS)"
	@echo "OBJECTS_DIR: $(OBJECTS_DIR)"
	@echo "CXX: $(CXX)"
	@echo "CXXFLAGS: $(CXXFLAGS)"
	@echo "CPPFLAGS: $(CPPFLAGS)"
	@echo "NAME: $(NAME)"
	@echo "OUTPUT_DIR: $(OUTPUT_DIR)"
