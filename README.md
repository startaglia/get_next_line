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
It's a project written on Linux, to make it work on MAC you have to replace `FOPEN_MAX` with `OPEN_MAX` </br></br>

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
## Bonus part
The bonus part is an implementation to make the project work even with different files at the same time. To test it, compile the program with:
 
 ```
 gcc get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=42 && ./a.out
 ```

Obviously you will need more than one test file.</br>

This is an example main to use on get_next_line_bonus.c for run and compile the bonus part:
```
int	main(void)
{
  char	*line0;
  char	*line1;
  int		i;
  int		fd0;
  int		fd1;
  
  fd0 = open("file0.txt", O_RDONLY);
  fd1 = open("file1.txt", O_RDONLY);
  i = 1;
  while (i < 7)
  {
    line0 = get_next_line(fd0);
    line1 = get_next_line(fd1);
    printf("line [%02d]: %s", i, line0);
    printf("line [%02d]: %s", i, line1);
    free(line0);
    free(line1);
    i++;
  }
  close(fd1);
  return (0);
}
```

## Technologies Used:

- **Programming Language**: C
- **Operating System**: Linux
- **Compiler**: GCC (GNU Compiler Collection)
- **C Standard Library**
- **File Descriptor Handling**: Functions like `open()`, `read()`, and `close()`
- **String Handling**: Standard library functions from `string.h`
- **Dynamic Memory Management:**: Functions like `malloc()` and `free()`

## Authors:

- **Simone Tartaglia**
  - Email: [startaglia89@gmail.com](mailto:startaglia89@gmail.com)
  - GitHub: [startaglia](https://github.com/startaglia)
  - LinkedIn: [Simone Tartaglia](https://www.linkedin.com/in/simone-tartaglia-134723248/)
