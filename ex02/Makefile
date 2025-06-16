# Output File
OUTPUT_DIR =	.
NAME = 				$(OUTPUT_DIR)/identifier

# Directories
INCLUDES_DIR =	.
CLASS_DIR =		class
SOURCES_DIR =	.
OBJECTS_DIR =	objs

# Files
SOURCES =		main.cpp Function.cpp class/Base.cpp
HEADERS =		class/Base.hpp class/A.hpp class/B.hpp class/C.hpp Function.hpp
OBJECTS =		$(OBJECTS_DIR)/main.o $(OBJECTS_DIR)/Function.o $(OBJECTS_DIR)/Base.o

# Compiler & Flags
CXX =			c++
CXXFLAGS =		-Wall -Wextra -Werror -std=c++98
CPPFLAGS =		-I $(INCLUDES_DIR) -I $(CLASS_DIR)
MEMOLYFLAGS = -fsanitize=address -g3

#-----------------------------------------------
# Colors
RESET = \033[0m
BOLD = \033[1m
# Regular Colors
GREEN = \033[32m
CYAN = \033[36m
GRAY = \033[90m
# Bold Colors
B_GREEN = \033[1;32m
B_BLUE = \033[1;34m
B_CYAN = \033[1;36m

#-----------------------------------------------
# Rules
all:	$(NAME)

# Link Targets
$(NAME): $(OBJECTS)
	@printf "\r$(GREEN)[%2d/%2d]$(RESET) All files compiled! Linking $(CYAN)$(NAME)$(RESET)\033[K\n" \
		"$$(find $(OBJECTS_DIR) -name '*.o' | wc -l)" "$$(echo $(SOURCES) | wc -w)"
	@$(CXX) $(CPPFLAGS) $^ -o $@
	@echo "$(B_GREEN)SUCCESS:$(RESET) $(NAME) linked successfully"
	@chmod 755 $(NAME)
	@echo "$(B_CYAN)READY:$(RESET) $(NAME) is ready to run"

# Compile Targets
$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp | $(OBJECTS_DIR)
	@printf "\r$(GREEN)[%2d/%2d]$(RESET) Compiling $(CYAN)%s$(RESET)\033[K" \
		"$$(find $(OBJECTS_DIR) -type f | wc -l)" "$$(echo $(SOURCES) | wc -w)" "$<"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJECTS_DIR)/Base.o: $(CLASS_DIR)/Base.cpp | $(OBJECTS_DIR)
	@printf "\r$(GREEN)[%2d/%2d]$(RESET) Compiling $(CYAN)%s$(RESET)\033[K" \
		"$$(find $(OBJECTS_DIR) -type f | wc -l)" "$$(echo $(SOURCES) | wc -w)" "$<"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

# Clean Targets
clean:
	@rm -rf $(OBJECTS)
	@rm -rfd $(OBJECTS_DIR)
	@echo "$(GRAY)CLEAN: $(NAME) object files cleaned$(RESET)"

fclean:	clean
	@rm -rf $(NAME)
	@echo "$(GRAY)FCLEAN: $(NAME) executable files cleaned$(RESET)"

re:		fclean all

update:	fclean
	make

# Phony
.PHONY = all clean fclean re update

#-----------------------------------------------
debug:
	@echo "$(B_BLUE)Debug Information:$(RESET)"
	@echo "$(CYAN)SOURCES:$(RESET) $(SOURCES)"
	@echo "$(CYAN)HEADERS:$(RESET) $(HEADERS)"
	@echo "$(CYAN)OBJECTS:$(RESET) $(OBJECTS)"
	@echo "$(CYAN)OBJECTS_DIR:$(RESET) $(OBJECTS_DIR)"
	@echo "$(CYAN)CLASS_DIR:$(RESET) $(CLASS_DIR)"
	@echo "$(CYAN)CXX:$(RESET) $(CXX)"
	@echo "$(CYAN)CXXFLAGS:$(RESET) $(CXXFLAGS)"
	@echo "$(CYAN)CPPFLAGS:$(RESET) $(CPPFLAGS)"
	@echo "$(CYAN)NAME:$(RESET) $(NAME)"
	@echo "$(CYAN)OUTPUT_DIR:$(RESET) $(OUTPUT_DIR)"

.PHONY: debug
