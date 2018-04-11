/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:42:16 by eliajin           #+#    #+#             */
/*   Updated: 2018/04/11 23:38:34 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
/*
** fonction servant à supprimer les commentaires dans le header
*/
char	*rm_comment_header(char *line)
{
	char	*tmp;
	int		len;
	char	*ret;
	int		i;

	len = search_char(line, '"') + 1;
	tmp = ft_strsub(line, len, ft_strlen(line));
	i = search_char(tmp, '"');
	if (tmp [i + 1] && tmp[i + 1] != '#' && tmp[i + 1] != ' ')
		return (NULL);
	if (tmp[i + 1] && tmp[i + 1] == ' ')
	{
		if (tmp[i + 2] && tmp[i + 2] != '#')
			return (NULL);
	}
	ret = ft_strsub(line, 0, i + len + 1);
	free(tmp);
	return (ret);
}

/*
** fonction traitant le header (name + comment)
*/
int		is_header(char *line, char *macro)
{
	char	*tmp;
	char	*rm_comment;

	rm_comment = rm_comment_header(line);
	if (rm_comment == NULL)
		return (0);
	tmp = ft_strsub(rm_comment, 0, ft_strlen(macro));
	if (ft_strcmp(tmp, macro) != 0)
		return (0);
	tmp = ft_strsub(rm_comment, ft_strlen(macro), ft_strlen(rm_comment));
	tmp = ft_epur_str(tmp);
	if (tmp[0] != '"' || tmp[ft_strlen(tmp) - 1] != '"')
		return (0);
	return (1);
}
