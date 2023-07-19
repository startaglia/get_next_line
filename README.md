# get next line

This project is a tool that returns a line from a text file.

## Installing and running the project:

1- Clone the repo:
  
  ```sh
  git clone https://github.com/startaglia/get_next_line get_next_line
  ```

2- Enter in get_next_line dir and compile the program with the following command (to test it you need a test file on the same folder)
	
 ```
 gcc get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42 && ./a.out
 ```
You coul try with different BUFFER_SIZE.</br>

This is an example main for run and compile the program:
```
int	main(void)
{
  char	*line;
  int		i;
  int		fd1;
  
  fd1 = open("file.txt", O_RDONLY);
  i = 1;
  while (i < 7)
  {
    line = get_next_line(fd1);
    printf("line [%02d]: %s", i, line);
    free(line);
    i++;
  }
  close(fd1);
  return (0);
}
```
## Authors

### Simone Tartaglia -  startaglia89@gmail.com - <a href="https://github.com/startaglia" target="_blank"><img align="center" src="https://icon-library.com/images/github-icon-svg/github-icon-svg-0.jpg" height="30" width="30" /></a> <a href="https://www.linkedin.com/in/simone-tartaglia-134723248/" target="_blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="https://www.linkedin.com/in/simone-tartaglia-134723248/" height="30" width="30" /></a>
