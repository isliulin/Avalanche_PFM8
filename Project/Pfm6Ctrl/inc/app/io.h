#ifndef _IO_H
#define _IO_H

#include		<stdio.h>
#include		<stdlib.h>
#include		<stdarg.h>
#include		"ffconf.h"
#include		"ff.h"

int			__print(char *format, ...);
//______________________________________________________________________________________
typedef struct _buffer
{
	char	*_buf,
				*_push,
				*_pull;
	int		size;
} _buffer;	
//______________________________________________________________________________________
typedef struct _io
{
	_buffer	*rx,*tx,*gets;
	int		(*get)(struct _buffer *),
				(*put)(struct _buffer *, int);
	union	{
				int		(*parse)(char *);
				struct _io *io;
	}			 arg;
//	FIL		*file; 														17.3.2017 odkomentiraj vse 	#kj873uhjfru
} _io;
//______________________________________________________________________________________
_buffer	*_buffer_init(int),
				*_buffer_close(_buffer *);
_io			*_io_init(int, int),
				*_io_close(_io *),
				*_stdio(_io	*);

int			_buffer_push(_buffer *, void *,int),
				_buffer_put(_buffer *, void *,int),
				_buffer_pull(_buffer *, void *,int),
				_buffer_count(_buffer *),
				_buffer_empty(_buffer *);
				
				
int			putch(int),
				getch(void),
				ungetch(int),
				ungets(char *);
int			f_getc (FIL*);
//______________________________________________________________________________________
void		Watchdog(void);
//______________________________________________________________________________________
struct	__FILE 
{ 
				_io		*io;
};
#endif
