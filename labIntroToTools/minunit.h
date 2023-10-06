/* minunit.h --- 
 * 
 * Filename: minunit.h
 * Description: 
 * Author: Joseph
 * Maintainer: 
 * Created: Wed Sep 20 10:17:02 2023 (+0100)
 * Last-Updated: Wed Sep 20 10:20:17 2023 (+0100)
 *           By: Joseph
 *     Update #: 2
 * 
 */

/*
Lab 1 - Lab intro to tools. This lab was just to get us started with linux, make and tests
Copyright (c) 2023 Joseph O'Keeffe

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/* Code: */
 /* file: minunit.h */
 #define mu_assert(message, test) do { if (!(test)) return message; } while (0)
 #define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)
 extern int tests_run;


/* minunit.h ends here */
