#include "main.h"

/**
 * cap_string - capitalized all words of s string
 * @s: string to be capitalized
 * Return: s
 */
char *cap_string(char *s)
{
int index = 0;

while (s[index])
{
while (!(s[index] >= 'a' && s[index] <= 'z'))
{
index++;
}
if (s[index - 1] == ' ' || s[index - 1] == '\t' || s[index - 1] == '\n' ||
s[index - 1] == ',' || s[index - 1] == ';' || s[index - 1] == '.' ||
s[index - 1] == '!' || s[index - 1] == '?' || s[index - 1] == '"' ||
s[index - 1] == '(' || s[index - 1] == ')' || s[index - 1] == '{' ||
s[index - 1] == '}' || index == 0)
{
s[index] -= 32;
}
}
return (s);
}
