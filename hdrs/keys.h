/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:22:09 by jlensing      #+#    #+#                 */
/*   Updated: 2020/06/05 12:42:06 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

#ifdef __APPLE_
# define KEY_ESCAPE 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_C 8
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124
# define KEY_NUM_MINUS 78
# define KEY_F12 65481
# define KEY_SHIFT 257
#elif __linux__
# define KEY_ESCAPE 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_C 8
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_RIGHT 65363
# define KEY_NUM_MINUS 78
# define KEY_F12 65481
# define KEY_SHIFT 257
#endif

#endif
