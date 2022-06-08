#include "s21_string.h"

size_t s21_strlen(const char *str) {
    int count = 0;

		if (str == NULL)
			return (0);
    while (*str != '\0')
    {
        str++;
        count++;
    }
    return (count);
}

int s21_strcmp(const char *s1, const char *s2) {
    int i = 0;

		if (s1 == NULL || s2 == NULL)
				return (0);
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            break;
        i++;
    }
    return (s1[i] - s2[i]);
}


char *s21_strcpy(char *dest, const char *src) {
    int i = 0;

		if (src == NULL || dest == NULL)
			return (NULL);
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

size_t  s21_strnlen(const char *s, size_t maxlen)
{
		size_t i = 0;
		
		if (s == NULL || maxlen < 1)
				return (0);
		while (s[i] != '\0' && i < maxlen)
				i++;
		return (i);
}

char *s21_strcat(char *dest, const char *src) {
    int i = 0;
		int j = 0;

    while (dest[i] != '\0')
        i++;
    while(src[j] != '\0')
    {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}

char *s21_strstr(const char *haystack, const char *needle) { 
	size_t i , j;

	i = 0;
	if (haystack == NULL || needle == NULL)
		return (NULL);
  if (*needle == '\0')
    return ((char *)haystack);
  while (haystack[i] != '\0'){
		j = 0;
		while (haystack [i + j] && needle[j] && haystack[i + j] == needle[j]){
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
  return (0);
}

int    s21_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char c1;
	unsigned char c2;

	if (n == 0)
		return (0);
  while (n--){
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
    if (c1 > c2)
			break ;
		if (c1 < c2)
			break ;
		if (c1 == '\0' || c2 == '\0')
			break;
	}
    return (c1 - c2);
}
