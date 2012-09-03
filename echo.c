/*
 * Copyright 2012 Mo McRoberts.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
 
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef HAVE_LOCALE_H
# include <locale.h>
#endif

int
main(int argc, char **argv)
{
	int c, e, ch, nonl, stop;
	const char *p;
	char *endp;

#ifdef ENABLE_NLS
	setlocale(LC_ALL, "");
#endif
	e = 0;
	nonl = 0;
	stop = 0;
	for(c = 1; c < argc; c++)
	{
		for(p = argv[c]; *p; p++)
		{
			if(e)
			{
				switch(*p)
				{
				case '\\':
					putchar('\\');
					break;
				case 'a':
					putchar('\a');
					break;
				case 'b':
					putchar('\b');
					break;
				case 'c':
					nonl = 1;
					stop = 1;
					break;
				case 'f':
					putchar('\f');
					break;
				case 'n':
					putchar('\n');
					break;
				case 'r':
					putchar('\r');
					break;
				case 't':
					putchar('\t');
					break;
				case 'v':
					putchar('\v');
					break;
				case '0':
					endp = (char *) p;
					ch = (int) strtol(p, &endp, 8);
					if(!endp)
					{
						endp = (char *) p;
					}
					else if(endp > p)
					{
						endp--;
					}
					p = endp;
					putchar(ch);
					break;
				default:
					putchar('\\');
					putchar(*p);
					break;
				}
				e = 0;
			}
			else if(*p == '\\')
			{
				e = 1;
				continue;
			}
			else
			{
				putchar(*p);
			}
			if(stop)
			{
				break;
			}
		}
		if(stop)
		{
			break;
		}
		if(c + 1 < argc)
		{
			putchar(' ');
		}
	}
	if(!nonl)
	{
		putchar('\n');
	}
	fflush(stdout);
	return 0;
}
