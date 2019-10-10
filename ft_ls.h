/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <sjacelyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:27:48 by sjacelyn          #+#    #+#             */
/*   Updated: 2019/04/17 20:32:45 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"

typedef struct      s_queue
{
    t_list          *top;
    t_list          *last;
    size_t          size;
}                   t_queue;

t_list              *append(t_queue *q, const char *path);
t_list              *pop(t_queue *q);
void                free_all(t_queue *q);

# endif