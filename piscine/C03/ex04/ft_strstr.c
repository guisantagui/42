//#include <stdio.h>
//#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	f_match;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[j] != '\0')
	{
		if (str[j] == to_find[i])
		{
			f_match = j;
			while (str[j] == to_find[i] && to_find[i] != '\0' && str[j] != '\0')
			{
				i++;
				j++;
			}
			if(to_find[i] == '\0')
				return (str + f_match);
			else
				i = 0;	
		}
		j++;
	}
	return (NULL);	
}

/*int main() {
    char str[] = "Hello, world!";
    char sub[] = "world";

    // Find the first occurrence of "world" in "Hello, world!"
    char *result = ft_strstr(str, sub);

    if (result != NULL) {
        printf("Substring found: %s\n", result);  // Prints the rest of the string starting from "world"
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}*/
