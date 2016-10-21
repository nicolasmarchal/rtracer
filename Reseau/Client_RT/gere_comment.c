# include "raytracer.h"

void	delete_comment(char *line)
{
  int	i;

  i = -1;
  while (line[++i])
    {
      if (line[i] == COMMENT_CHAR)
	{
	  line[i] = 0;
	  return ;
	}
    }
}
