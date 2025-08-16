# === CONFIG ===
NAME_CLIENT := client
NAME_SERVER := server
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g -pedantic-errors
RM          := rm -f
MKDIR_P     := mkdir -p

# === PATHS ===
LIBFT_DIR   := libft
OBJ_DIR     := obj
SRC_DIR     := srcs

# === SOURCES ===
SRC_UTILS   := $(SRC_DIR)/utils.c \
			   $(SRC_DIR)/receipt_signal.c \

SRC_CLIENT  := $(SRC_DIR)/client.c
SRC_SERVER  := $(SRC_DIR)/server.c

# Tous les fichiers objets nécessaires pour chaque binaire
OBJ_CLIENT  := $(SRC_CLIENT:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o) \
               $(SRC_UTILS:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

OBJ_SERVER  := $(SRC_SERVER:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o) \
               $(SRC_UTILS:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

# === HEADERS ===
INCLUDES    := -I$(LIBFT_DIR)/includes -I./includes/

# Couleurs/logos
BOLD        := \033[1m
GREEN       := \033[0;32m
YELLOW      := \033[0;33m
CYAN        := \033[0;36m
RESET       := \033[0m

.PHONY: all prebuild clean fclean re

all: prebuild $(NAME_CLIENT) $(NAME_SERVER)

prebuild:
	@echo "$(CYAN)[🔁] Compilation préalable de LIBFT…$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)[✅] Libft compilée.$(RESET)"

$(NAME_CLIENT): $(OBJ_CLIENT)
	@echo "$(CYAN)[🔗] Linking de l'exécutable $(NAME_CLIENT)…$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) \
		-L$(LIBFT_DIR) -lft \
		-o $@
	@echo "$(GREEN)[✅] Build complete: $(NAME_CLIENT)$(RESET)"

$(NAME_SERVER): $(OBJ_SERVER)
	@echo "$(CYAN)[🔗] Linking de l'exécutable $(NAME_SERVER)…$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_SERVER) \
		-L$(LIBFT_DIR) -lft \
		-o $@
	@echo "$(GREEN)[✅] Build complete: $(NAME_SERVER)$(RESET)"

$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR_P) $(dir $@)
	@echo "$(YELLOW)[⚙️] Compiling C: $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(CYAN)[🧹] Nettoyage des objets…$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@echo "$(CYAN)[🧹] Clean Libft…$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(CYAN)[💥] Suppression des exécutables…$(RESET)"
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@echo "$(CYAN)[💥] fclean Libft…$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

