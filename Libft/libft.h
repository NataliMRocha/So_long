/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:11:17 by namoreir          #+#    #+#             */
/*   Updated: 2023/10/23 17:01:56 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32000
# endif

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

/**@param char_read the character stored
 * @param next the pointer to the next node
 * */
typedef struct s_liste	t_liste;
struct					s_liste
{
	char				char_read;
	t_liste				*next;
};

/**@brief Creates a new node of the linked list and put a buffer
 * character in the node.
 *
 * @param c the character to be placed
 * @return The new node
 * */
t_liste					*get_char_node(char c);

/**@param pos the current position in buf
 * @param nb_read the amount of bytes read of buf
 * @param len the size of string
 * @param fd the number of a file descriptor received as parameter
 * @param buf the string to store wath haved read to file
 * @param line the struct where the line will be storaged
 * */
typedef struct s_file
{
	int					pos;
	int					nb_read;
	int					len;
	int					fd;
	char				buf[BUFFER_SIZE];
	t_liste				*line;
}						t_file;

/**@brief Puts the node at the end of the linked list.
 * If don't ecxist list, the new node will be the head of list.
 *
 * @param lst the list
 * @param new the new node
 * */
void					put_in_pos_gnl(t_liste **lst, t_liste *new);

/**@brief frees the allocated memory if the read returns -1.
 *
 * @param line the list to be freed
 * @return null pointer
 * */
char					*free_file(t_liste *line);

/**@brief The principal function, defines the value of variables inside struct
 * cleans the buffer, and makes the first read.
 *
 * @param fd the int representing a file descriptor
 * @return a string passed as a parameter to the read_line function
 * */
char					*get_next_line(int fd);

/**@brief Makes a loop to read the file, create new nodes with each character
 * read, counts the size of bytes stored until it finds \n or \0
 *
 * @param temp a struct with multiple variables
 * @return a string passed as a parameter to the get_current_line function
 * */
char					*read_line_gnl(t_file *temp);

/**@brief creates a new string and copy each character from the list into it
 *
 * @param set a struct with multiple variables
 * @return a string with the line
 * */
char					*get_current_line(t_file *set);

/**@brief Check if the int 'c' is an alphabetical character
 * from the ASCII table.
 *
 * @param c a int
 * @return Int '1' for true or int '0' for false.
 * */
int						ft_isalpha(int c);

/**@brief Checks if the int 'c' is a digit character from the ASCII table.
 *
 * @param c a int
 * @return Int '1' for true or int '0' for false.
 */
int						ft_isdigit(int c);

/**@brief Checks if the int 'c' is a alphanumeric character
 * from the ASCII table.
 *
 * @param c a int
 * @return Int '1' for true or int '0' for false.
 */
int						ft_isalnum(int c);

/**@brief Checks if the int 'c' is in the ASCII table.
 *
 * @param c a int
 * @return Int '1' for true or int '0' for false.
 */
int						ft_isascii(int c);

/**@brief Checks if the int 'c' is a printable character
 * (including space) in the ASCII table.
 *
 * @param c a int
 * @return Int '1' for true or int '0' for false.
 */
int						ft_isprint(int c);

/**@brief Calculates the length of the string pointed to by 's',
 * before the terminating null byte ('\0') can be found.
 *
 * @param s as a true C string, terminated by '\0'
 * @return The number of chars in the string.
 */
size_t					ft_strlen(const char *s);

/**@brief Fills the first 'n' bytes of the memory area
 * pointed to by 's' with the int 'c'.
 *
 * @param s a sequential memory area
 * @param c char used to fill the bytes in 's'
 * @param n the number of bytes in 's' to fill with 'c'
 * @return A pointer to the memory area s.
 */
void					*ft_memset(void *s, int c, size_t n);

/**@brief Sets the first 'n' chars of a string 's' to zero ('\0').
 *
 * @param s as a string
 * @param n the number of bytes to fill with '\0'
 */
void					ft_bzero(void *s, size_t n);

/**@brief Copies 'n' bytes from memory area 'src' to memory
 * area 'dest'. The memory areas must not overlap.
 *
 * @param dest destination memory area to received the copy of 'src'
 * @param src source memory area to be copy
 * @param n the amount of bytes in 'src' to be copied
 * @return A pointer to 'dest'.
 */
void					*ft_memcpy(void *dest, const void *src, size_t n);

/**@brief Copies 'n' bytes from memory area 'src' to memory
 * area 'dest' n case of memory overlap, 'src' will be copied
 * to a temporary array and then to 'dst'.
 *
 * @param dest destination memory area to received the copy of 'src'
 * @param src source memory area to be copy
 * @param n the amount of bytes in 'src' to be copied
 * @return A pointer to 'dest'.
 */
void					*ft_memmove(void *dest, const void *src, size_t n);

/**@brief Copies size - 1 characters from the NUL-terminated
 * string 'src' to 'dst', NUL-terminating the result.
 *
 * @param dst destination string to received the copy of 'src'
 * @param src source string to be copy
 * @param size the full size of the 'dst' buffer
 * @return The total length of the string they tried to create.
 */
size_t					ft_strlcpy(char *dst, const char *src, size_t size);

/**@brief Appends the NUL-terminated string 'src' to the end of 'dst'.
 * It will append at most ('size' - 'strlen(dst)' - 1 bytes),
 * NUL-terminating the result.
 *
 * @param dst destination string to received the copy of 'src'
 * @param src source string to be copy
 * @param size the full size of the 'dst' buffer
 * @return The total length of the string they tried to create.
 */
size_t					ft_strlcat(char *dst, const char *src, size_t size);

/**@brief Convert lowercase letters to uppercase.
 *
 * @param c a int
 * @return The converted letter, or 'c' if the conversion
 * was not possible.
 */
int						ft_toupper(int c);

/**@brief Convert uppercase letters to lowercase.
 *
 * @param c a int
 * @return The converted letter, or 'c' if the conversion
 * was not possible.
 */
int						ft_tolower(int c);

/**@brief Looks for the first occurrence of the character 'c'
 * in the string 's'.
 *
 * @param s a string
 * @param c a char to be searched for in 's'
 * @return A pointer to the matched character or NULL if the
 * character is not found. The terminating null byte is considered
 * part of the string.
 */
char					*ft_strchr(const char *s, int c);

/**@brief Looks for the last occurrence of the character
 * 'c' in the string 's'.
 *
 * @params a string
 * @param c a char to be searched for in 's'
 * @return A pointer to the matched character or NULL if the
 * character is not found. The terminating null byte is considered
 * part of the string.
 */
char					*ft_strrchr(const char *s, int c);

/**@brief Compares only the first (at most) n bytes of two strings,
 * 's1' and 's2'.
 *
 * @param s1 a string
 * @param s2 a string
 * @param the amount of bytes to compair
 * @return An integer less than, equal to, or greater than
 * zero if 's1' is found, respectively, to be less than, to match,
 * or be greater than 's2'.
 */
int						ft_strncmp(const char *s1, const char *s2, size_t n);

/**@brief Scans the initial 'n' bytes of the memory area pointed to
 * by 's' for the first instance of 'c'.
 *
 * @param s the memory area to search
 * @param c a char to be search
 * @param n amount of bytes to scan
 * @return A pointer to the matching byte or NULL if the character
 * does not occur in the given memory area.
 */
void					*ft_memchr(const void *s, int c, size_t n);

/**@brief Compares the first 'n' bytes, each interpreted as
 * unsigned char, of the memory areas 's1' and 's2'.
 *
 * @param s1 a memory area
 * @param s2 another memory area
 * @param n amount of bytes to compare in 's1' and 's2'
 * @return An integer less than, equal to, or greater than zero if
 * the first 'n' bytes of 's1' is found, respectively, to be less than,
 * to match, or be greater than the first 'n' bytes of 's2'. If 'n' is
 * zero, the return value is zero.
 */
int						ft_memcmp(const void *s1, const void *s2, size_t n);

/**@brief Locates the first occurrence of the null-terminated string
 * little in the string big, where not more than len characters
 * are searched. Characters that appear after a '\0' character are not
 * searched.
 *
 * @param big a string to be searched through
 * @param little a substring to be located in big
 * @param len amount of character to search
 * @return (If 'little' is an empty string, 'big' is returned); if 'little'
 * occurs nowhere in 'big', NULL is returned; otherwise a pointer to the
 * first character of the first occurrence of 'little' is returned.
 */
char					*ft_strnstr(const char *big, const char *little,
							size_t len);

/**@brief Converts the initial portion of the string pointed to by
 * 'nptr' to int.
 *
 * @param nptr a string to convert
 * @return int with the converted value.
 */
int						ft_atoi(const char *nptr);

/**@brief Allocates memory for an array of 'nmemb' elements of 'size'
 * bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero. If 'nmemb' or 'size' is 0, then calloc
 * returns either NULL, or a unique pointer value that can later be
 * successfully passed to free().
 *
 * @param nmemb number of elements to be allocated
 * @param size size of each element in bytes
 * @return void* a pointer to the allocated memory, all bytes set to '\0'
 */
void					*ft_calloc(size_t nmemb, size_t size);

/**@brief Duplicate the contents of string 's'. Memory for the
 * new string is obtained with malloc.
 *
 * @param s a string
 * @return char * a pointer to the duplicate string.
 * It returns NULL if insufficient memory was available.
 */
char					*ft_strdup(const char *s);

/**@brief Allocates (with malloc(3)) and returns a substring
 * from the string 's'. The substring begins at index 'start'
 * and is of maximum size 'len'.
 *
 * @param s the string from which to create the substring
 * @param start the start index of the substring in the string 's'
 * @param len the maximum length of the substring
 * @return The substring. NULL if the allocation fails.
 */
char					*ft_substr(char const *s, unsigned int start,
							size_t len);

/**@brief Allocates (with malloc(3)) and returns a new string,
 * which is the result of the concatenation of 's1' and 's2'.
 *
 * @param s1 the prefix string
 * @param s2 the suffix string
 * @return The new string. NULL if the allocation fails.
 */
char					*ft_strjoin(char const *s1, char const *s2);

/**@brief Allocates (with malloc(3)) and returns a copy of 's1'
 * with the characters specified in 'set' removed from the beginning
 * and the end of the string.
 *
 * @param s1 the string to be trimmed
 * @param set the reference set of characters to trim
 * @return The trimmed string. NULL if the allocation fails.
 */
char					*ft_strtrim(char const *s1, char const *set);

/**@brief Allocates (with malloc(3)) and returns an array of strings
 * obtained by splitting 's' using the character 'c' as a delimiter.
 * The array must end with a NULL pointer.
 *
 * @param s the string to be split
 * @param c the delimiter character
 * @return The array of new strings resulting from the split.
 * NULL if the allocation fails.
 */
char					**ft_split(char const *s, char c);

/**@brief Allocates (with malloc(3)) and returns a string representing
 * the integer received as an argument. Negative numbers must be handled.
 *
 * @param n the integer to convert
 * @return The string representing the integer. NULL if the allocation fails.
 */
char					*ft_itoa(int n);

/**@brief Applies the function 'f' to each character of the string 's',
 * and passing its index as first argument to create a new string
 * (with malloc(3)) resulting from successive applications of 'f'.
 *
 * @param s the string on which to iterate
 * @param f the function to apply to each character
 * @return The string created from the successive applications
 * of ’f’. Returns NULL if the allocation fails.
 */
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));

/**@brief Applies the function 'f' on each character of the string passed
 * as argument, passing its index as first argument. Each character is
 * passed by address to 'f' to be modified if necessary.
 *
 * @param s the string on which to iterate
 * @param f the function to apply to each character
 */
void					ft_striteri(char *s, void (*f)(unsigned int, char *));

/**@brief Outputs the character 'c' to the given file descriptor.
 *
 * @param c the character to output
 * @param fd the file descriptor on which to write
 */
void					ft_putchar_fd(char c, int fd);

/**@brief Outputs the string 's' to the given file descriptor.
 *
 * @param s the string to output
 * @param fd the file descriptor on which to write
 */
void					ft_putstr_fd(char *s, int fd);

/**@brief Outputs the string 's' to the given file descriptor
followed by a newline.

 * @param s the string to output
 * @param fd the file descriptor on which to write
*/
void					ft_putendl_fd(char *s, int fd);

/**@brief Outputs the integer 'n' to the given file descriptor.
 *
 * @param n the integer to output
 * @param fd the file descriptor on which to write
 */
void					ft_putnbr_fd(int n, int fd);

// ----------------Bonus functions----------------

/**@brief Allocates (with malloc(3)) and returns a new node.
 * The member variable 'content' is initialized with the value of the
 * parameter 'content'. The variable 'next' is initialized to NULL.
 *
 * @param content the content to create the node with
 * @return The new node.
 */
t_list					*ft_lstnew(void *content);

/**@brief Adds the node 'new' at the beginning of the list.
 *
 * @param lst the address of a pointer to the first link of a list.
 * @param new the address of a pointer to the node to be added to the list.
 */
void					ft_lstadd_front(t_list **lst, t_list *new);

/**@brief Counts the number of nodes in a list.
 *
 * @param lst the beginning of the list
 * @return The length of the list.
 */
int						ft_lstsize(t_list *lst);

/**@brief Returns the last node of the list.
 *
 * @param lst the beginning of the list
 * @return Last node of the list.
 */
t_list					*ft_lstlast(t_list *lst);

/**@brief Adds the node 'new' at the end of the list.
 *
 * @param lst the address of a pointer to the first link of a list
 * @param new the address of a pointer to the node to be added to the list.
 */
void					ft_lstadd_back(t_list **lst, t_list *new);

/**@brief Takes as a parameter a node and frees the memory of the node’s
 * content using the function 'del' given as a parameter and free the node.
 * The memory of 'next' must not be freed.
 *
 * @param lst the node to free
 * @param del 'he address of the function used to delete the content.
 */
void					ft_lstdelone(t_list *lst, void (*del)(void *));

/**@brief Deletes and frees the given node and every successor of that node,
 * using the function 'del' and free(3). Finally, the pointer to the list
 * must be set to NULL.
 *
 * @param lst the address of a pointer to a node
 * @param del the address of the function used to delete the content
 * of the node.
 */
void					ft_lstclear(t_list **lst, void (*del)(void *));

/**@brief Iterates the list 'lst' and applies the function
'f' on the content of each node.

 * @param lst the address of a pointer to a node.
 * @param f the address of the function used to iterate on
the list.
*/
void					ft_lstiter(t_list *lst, void (*f)(void *));

/**@brief Iterates the list 'lst' and applies the function
 * 'f' on the content of each node. Creates a new list resulting of
 * the successive applications of the function 'f'.
 * The 'del' function is used to delete the content of a node if needed.

 * @param lst the address of a pointer to a node.
 * @param f  the address of the function used to iterate on
the list.
 * @param del the address of the function used to delete
the content of a node if needed.
 * @return The new list. NULL if the allocation fails.
*/
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
int						ft_putstr(char *str);
int						ft_putchar(char c);
int						ft_putptr(unsigned long ptr, char *base);
int						ft_putnbr_hx(unsigned int hx, char *base);
int						ft_putnbr_uns(unsigned int nb);
int						ft_putnbr(int nb);
int						ft_printf(const char *format, ...);

#endif