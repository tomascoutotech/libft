*This project has been created as part of the 42 curriculum by tomanuel.*

# Libft

## Description

Libft is my first C library. It re-implements a set of standard `libc` functions, adds a few useful extra string/memory/output helpers, and provides a small singly linked list API. The result is `libft.a`, reused in later 42 projects.

The library is split in three parts, as required by the subject:

1. **Libc functions** - `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_strlcpy`, `ft_strlcat`, `ft_toupper`, `ft_tolower`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`, `ft_strnstr`, `ft_atoi`, `ft_calloc`, `ft_strdup`. Same prototypes and behaviour as the originals (`restrict` is omitted on purpose).
2. **Additional functions** - `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`.
3. **Linked list** - `t_list` and `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

Technical choices:

- No global variables; helper functions are `static` and live in the file that uses them.
- Allocating functions return `NULL` on failure and never leak: `ft_split` frees every string already built, `ft_lstmap` clears the partial list and calls `del` on the orphan content.
- `ft_calloc` checks `nmemb * size` for overflow before calling `malloc`.
- `ft_strlcat` never reads past `dstsize` bytes of `dst`, as in BSD.
- `ft_memcpy`/`ft_memmove` return `dst` when both pointers are `NULL` instead of crashing.

## Instructions

```sh
make          # builds libft.a
make clean    # removes the object files
make fclean   # removes the object files and libft.a
make re       # fclean + all
```

Everything is compiled with `cc -Wall -Wextra -Werror`, and the archive is created with `ar rcs`. To use it in another program:

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o main    # with #include "libft.h"
```

## Resources

- `man 3` pages of every re-implemented function (`man 3 strlcpy`, `man 3 memmove`, ...)
- The C Programming Language (Kernighan & Ritchie)
- C standard, ISO/IEC 9899:1999 (behaviour of `memmove`, `strchr` with `'\0'`, ...)
- Linked lists: https://en.wikipedia.org/wiki/Linked_list
- The Norm (42 subject)
