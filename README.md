# get_next_line

<p align="center">
  <img src="https://github.com/SimpleLuke/get_next_line/assets/89473016/4dbffb48-7dd0-4c46-864a-5b8d92467df7" alt="get_next_line 42 project badge"/>
</p>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

## About the Project
This project is about reading from a file descriptor.
The function returns a single line of strings from a file descriptor.

## Usage

```c
// main.c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}
```
```bash
gcc main.c get_next_line.c get_next_line_utils.c
```
``BUFFER_SIZE`` can be specified:
```bash
gcc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```
```bash
./a.out [file.txt]
```
## Contact

- Luke Lai - [LinkedIn](https://www.linkedin.com/in/luke-lai-309a3522b/) - lukelai.dev@gmail.com
