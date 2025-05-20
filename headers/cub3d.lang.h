/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.lang.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:31:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/20 14:44:32 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LANG_H
# define CUB3D_LANG_H

//Set color strings
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define RES	"\x1B[0m\n"

//Set error messages
# define LANG_E			"\x1b[48;2;100;0;0;1m[Error]\x1b[0m "
# define LANG_E_MALLOC	"\x1b[31mMalloc Error 🤡\n\x1b[0m"
# define LANG_E_IPA		"\x1b[31mInvalid Cub3D Args 💀\n\x1b[0m"

//Set warn messages
# define LANG_W		"\x1b[48;2;140;140;0;1m[Warning]\x1b[0m "

# define ERROR		"Error\n"
# define CHARSET	"Wrong Charset in Map\n"
# define NUMB_PLAYER	"Wrong Number of Player\n"
# define MISSING_VALUES	"Missing Values to Start the Map\n"
# define UNWALLED_MAP	"Map is not Finished by Wall\n"
# define EXTENTION	"Wrong Extention of Map File\n"
# define WRONG_ID	"Missing/Repetition of Texture ID\n"
# define NOT_EXIST	"Map File Does not Exist\n"
# define DOUBLE_MAP	"Map is Seperated By a Space/New Line\n"
# define NO_MAP		"Map is not in File : You Should Add a Map After Textures\n"

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */

#endif
