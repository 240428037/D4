int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);
	while (*str)//(*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	int len = my_strlen("abc");
	printf("%d\n", len);
	return 0;
}