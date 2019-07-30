/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lib.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 13:17:07 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 23:36:36 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>

typedef struct	s_size
{
	int		good_size_map;
	int		size_map;
}				t_size;

typedef struct	s_pos
{
	int		i;
	int		j;
	int		i_v2;
	int		j_v2;
	int		krpos;
	int		imax;
	int		jmax;
	int		len_x;
	int		len_y;
}				t_pos;

typedef struct	s_param
{
	int		line;
	char	cv;
	char	co;
	char	cp;
}				t_param;

void			ft_display(char	**map2d);
int				ft_line(char **map2d);
int				ft_strlen(char *str);
int				ft_strlen_v2(char *str);
int				ft_map_size(char *av);
int				ft_error1(int i, char **map2d);
int				ft_error2(int i, int j, char *map1d, char **map2d);
int				ft_error3(int i, char *map1d);
int				ft_check(t_pos pos, int size_kr, char *map1d, char **map2d);
int				ft_resolve_square(t_pos pos, char *map1d, char **map2d,
		int size_krmax);
char			*ft_map1d_generator(int size, char *av, char *map1d);
char			*ft_map1d_generator_v2(int size, int rd, char *av, char *map2d);
char			*ft_param(char *map1d);
char			**ft_map2d_generator(char *map1d, char **map2d);
char			**ft_map2d(char *map1d, char **map2d, int size_x, int y);
char			**ft_pre_resolve(char *map1d, char **map2d);
char			**ft_resolve(t_pos pos, char *map1d, char **map2d);
char			**ft_fill(t_pos pos, char *map1d, char **map2d);
char			**ft_fill_final(char *map1d, char **map2d);
char			*ft_realoc(char *old, int len, char *buff, int ret);

#endif
