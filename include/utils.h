#ifndef UTILS_H
#define UTILS_H
bool empty_string(char *line);
bool	char_in_set(char c, char *set);
void print_strings(char **strings);
int	ft_strcmp(const char *s1, const char *s2);
bool	strmatch(const char *string_1, const char *string_2);
bool	strnmatch(const char *string_1, const char *string_2, size_t n);
#endif
