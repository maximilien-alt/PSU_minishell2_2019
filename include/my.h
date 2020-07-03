/*
** EPITECH PROJECT, 2019
** my
** File description:
** include
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <sys/sysmacros.h>
#include <signal.h>

typedef struct format_t
{
    char c;
    void (*ptr)(va_list);
} format_t;

typedef struct nodes_s
{
    char *name;
    char *value;
    struct nodes_s *next;
}node_t;

typedef struct tree_s
{
    char *command;
    int pipefds[2];
    struct tree_s *left;
    struct tree_s *right;
}tree_t;

typedef struct buffer_s
{
    char *buffer;
} buffer_t;

typedef struct my_binaries_s
{
    char *command;
    int (*ptr)(node_t *env_list, char *buffer);
}my_binaries_t;

typedef struct sep_s
{
    char *sep;
    void (*ptr)(tree_t *, node_t *);
} sep_t;

void little_print(void);
int check_for_redirect(char c);
int lasts_checks(buffer_t *buff, int ret);
void execute_pipe(tree_t *tree, node_t *env_list);
void exec_double(tree_t *tree, node_t *env_list);
void exec_redirect_right(tree_t *tree, node_t *env_list);
void exec_double_redirect_right(tree_t *tree, node_t *env_list);
void exec_redirect_left(tree_t *tree, node_t *env_list);
void exec_tree_command(tree_t *tree, node_t *env_list);
int simple_ending(char *str, char **exec_tab, char **tab, pid_t pid);
int my_exec_command(char *command, node_t *env_list);
void free_tree(tree_t *my_tree);
int parse_tree(tree_t *tree, node_t *env_list);
int minishell_return(char **tab, char **exec_tab, char *str, pid_t pid);
int exec_pipe(char *command_1, char *command_2, node_t *env_list);
tree_t *my_binary_tree(buffer_t *buff, tree_t *my_tree);
tree_t *insert(tree_t *my_tree, char *command, int separator);
tree_t *obtain_good_tree(buffer_t *buff, int cursor, tree_t *my_tree);
int my_check_sep(char *buffer);
int my_change_buffer(buffer_t *buff);
int check_own(char *buffer, node_t *env_list, int fds[2]);
void minishell_gone_wrong(char *buffer, node_t *env_list);
int my_check_minishelll_two(char *buffer);
int free_list(node_t *env_list);
char **my_list_to_tab(node_t *env_list);
node_t *insert_node(node_t *nodes, char *env);
int is_num(char c);
int is_alp(char c);
node_t *my_env_to_list(node_t *nodes, char **env);
void print_exec(char *command);
int my_disp_error(int pid);
char **quick_mod(char **tab, int check, char *name, char *value);
int check_same_name(char **tab, char *name);
char *my_char_strcat(char *src, char c, int check);
int is_alpha(char c);
int return_and_free(char **tab, int number);
int my_ret(int number, char **tab);
int my_tty(void);
void my_draw_prompt(void);
int my_own_cd(node_t *env_list, char *buffer);
int my_own_exit(node_t *env_list, char *buffer);
int my_own_env(node_t *env_list, char *buffer);
int my_own_setenv(node_t *env_list, char *buffer);
int my_own_unsetenv(node_t *env_list, char *buffer);
char *get_good_env(node_t *env_list);
char *my_get_good_bin(char *env, char *buffer);
void my_free_tab(char **tab);
int minishell_loop(node_t *env_list);
int    my_putnbr_base(int nbr, char const *base);
int    my_compute_power_rec(int nb, int p);
int    my_compute_square_root(int nb);
int    my_find_prime_sup(int nb);
int    my_getnbr(char const *str);
int    my_isneg(int n);
int    my_is_prime(int nb);
int    my_lengh(char const *str);
char    **my_malloc_words(char const *str, char **tab);
void    my_putchar(char c);
void    my_put_nbr(int nb);
int     my_putstr(char const *str);
char    *my_revstr(char *str);
int    my_showmem(char const *str, int size);
int    my_showstr(char const *str);
int    my_show_word_array(char * const *tab);
void    my_sort_int_array(int *tab, int size);
char    *my_strcapitalize(char *str);
char    *my_strcat(char *dest, char *src, int check);
char    my_strcmp(char *s1, char *s2);
char    *my_strcpy(char *dest, char const *src);
char    *my_strcpy2(char *dest, char const *src);
char    *my_strdup(char const *src);
int    my_str_isalpha(char const *str);
int    my_str_islower(char const *str);
int    my_str_isnum(char const *str);
int    my_str_isprintable(char const *str);
int    my_str_isupper(char const *str);
int    my_strlen(char const *str);
char    *my_strlowcase(char *str);
char    *my_strncat(char *dest, char const *src, int nb);
int    my_strncmp(char *s1, char *s2, int n);
char    *my_strncpy(char *dest, char const *src, int n);
char    *my_strstr(char *str, char const *to_find);
char    **my_str_to_word_array(char const *str, char *operator);
char    *my_strupcase(char *str);
void    my_swap(int *a, int *b);
int    my_prime(int nb);
int    my_strlen4(char const *str);
void    my_swap3(char const *dest, char const *src);
void    **my_malloc_word(char const *str, char * const *tab);
int    my_word_number(char const *str);
char   **my_word_in_tab(char const *str, char *const *tab);
int    my_str_neg(char *str, char *str2);
char    *my_infin_add_neg(char *str, char *str2);
int    my_str_is_negative(char *str);
char    *my_str_delete_null(char *str);
char    *my_cpy_without_null(char *str, char *cpy, int letter, int zero);
char    *my_supr_null(char *str, char *cpy, int letter);
char    *my_str_is_easy(char *str, char *cpy);
int    my_int_nbr(char const *str, int letter, int size, char **endptr);
int    my_delete_non_null(char const *str);
int    my_str_tol_error(char const *str);
char    *my_infin_add(char *str, char *str2);
char    *my_infin_add_neg(char *str, char *str2);
int    my_infin_cmp(char *str, char *str2);
char *my_supr_same(char *str, char *strtemp);
char *my_delete_neg(char *str);
char *my_strtemp(char *str, char *div);
int my_mult_zero(char *mult);
char *my_add_x_zero(int cursor);
int    my_clean_add_total(char *str, char *mult);
char *my_delete_mult(char *mult);
char *my_zeroo(char *str, char *mult);
char *my_infin_tol(char *str, char **endptr);
int my_bistro_error(int ac, char **av, char *buff);
char *my_infin_sub(char *str, char *str2);
int my_occ(char *str);
void my_putchar(char c);
void my_print_s(va_list ap);
void my_print_c(va_list ap);
void my_print_d(va_list ap);
void my_print_p(va_list ap);
void my_print_x(va_list ap);
void my_print_upcase_x(va_list ap);
void my_print_o(va_list ap);
void my_print_b(va_list ap);
void my_print_u(va_list ap);
void my_print_upcase_s(va_list ap);
void my_printf(char *format, ...);

#endif /* MY_H_ */
