<p align="center">
  <img src="https://img.shields.io/badge/42–School-Personal%20Lib-blue.svg" alt="42 School">
  <img src="https://img.shields.io/badge/Language-C-green.svg" alt="C">
  <img src="https://img.shields.io/badge/Status-Work%20in%20Progress-yellow.svg" alt="Work in Progress">
  <img src="https://img.shields.io/badge/License-MIT-lightgrey.svg" alt="License MIT">
</p>

# MonLib42

> Bibliothèque personnelle en C pour les projets 42 : libft étendue, printf, get_next_line, allocateur d’arène, gestion de fichiers, etc.

---

## 🗂 Table des matières

- [Présentation](#présentation)
- [Fonctionnalités](#fonctionnalités)
- [Structure du projet](#structure-du-projet)
- [Prérequis](#prérequis)
- [Installation & Compilation](#installation--compilation)
- [Exemples d’utilisation](#exemples-dutilisation)
- [Contribuer](#contribuer)
- [Licence](#licence)

---

## 📖 Présentation

Cette bibliothèque regroupe plusieurs modules utiles pour les projets de l’école 42 :

- **libft** : fondations (fonctions sur les chaînes, listes, allocation, etc.).
- **ft_printf** : printf minimaliste supportant les conversions basiques.
- **get_next_line** (fileft) : lecture ligne à ligne depuis un descripteur.
- **arena_allocator** : allocateur d’arène pour gérer rapidement de gros blocs mémoire.
- **p_builtins** : quelques fonctions utilitaires (« builtins ») pour vos minishells ou autres.

Le projet est en constante amélioration : vos retours et PR sont les bienvenus ! 🎉

---

## ⚙️ Fonctionnalités

- 🚀 **Performances** – allocateur d’arène pour réduire les appels `malloc()`.
- 🧩 **Modulaire** – chaque composant compilable indépendamment.
- 🔄 **Portable** – compatible UNIX / Linux / macOS.
- ✔️ **Tests unitaires** (à venir) – validation des fonctions de base.

---

## 🏗 Structure du projet

```text
.
├── arena_allocator
│   ├── arena_allocator.c
│   └── arena_allocator.h
├── fileft
│   ├── get_next_line.c
│   └── ft_file.h
├── ft_printf
│   ├── ft_printf.c
│   ├── handler_base10.c
│   ├── handler_chr.c
│   ├── handler_lower_hex.c
│   ├── handler_percent.c
│   ├── handler_pointer.c
│   ├── handler_string.c
│   ├── handler_unsigned.c
│   ├── handler_upper_hex.c
│   └── p_builtins.c
├── libft
│   ├── ft_atoi.c
│   ├── ft_bzero.c
│   ├── ft_calloc.c
│   ├── ft_free.c
│   ├── ft_isalpha.c
│   ├── … (toutes vos ft_*.c)
│   └── ft_toupper.c
├── includes
│   ├── arena_allocator.h
│   ├── fileft.h
│   ├── libft.h
│   └── p_builtins.h
├── Makefile
└── README.md ← **Vous êtes ici**
```
