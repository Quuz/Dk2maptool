/******************************************************************************/
/** @file dk2mtool.c
 * Allows reading/writing DK2 map files.
 * @par Purpose:
 *     Allows reading/writing DK2 dk2 map files (KWD/KLD).
 * @par Comment:
 *     None.
 * @author   Tomasz Lis
 * @date     15 Jul 2008 - 05 Aug 2008
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dk2mfile.h"

int main(int argc, char *argv[])
{
    printf("\nDungeon Keeper 2 map tool\n");
    printf("-------------------------------\n");
    if ((argc<3)||(strlen(argv[2])!=1))
    {
        printf("Not enought parameters.\n");
        printf("Usage:\n");
        printf("  %s <mapname> <operation>\n","dk2mtool");
        printf("The <mapname> should be given without extension.\n");
        printf("Valid <operations> are:\n");
        printf("  d: Dump file structure data\n");
        printf("\n");
        system("PAUSE");	
    	return 1;
    }
    printf("Get struct\n");
  struct DK2_Level *lvl;
  short flags = DK2MFLAG_VERBOSE;
  char *map_name=argv[1];
  char operatn=tolower(argv[2][0]);
  short result;
  printf("Get result lvl create\n");
  result=dk2m_lvl_create(&lvl,flags);
  if (result!=ERR_NONE)
  {
    //system("PAUSE");	
    return 2;
  }
  printf("Get result read map files\n");
  result=dk2m_read_mapfiles(lvl,map_name,flags);
  printf("Check\n");
  if (result!=ERR_NONE)
  {
    //system("PAUSE");	
    printf("Error: dk2m_read_mapfiles returned code %d\n", result);
    fflush(stdout);
    return 4;
  }
  printf("switch\n");
  switch (operatn)
  {
  case 'd':
    {
      dk2m_print_level(lvl);
    };break;
  default:
      printf("Unknown opertation symbol.\n");
      printf("Exiting without any changes.\n");
      break;
  }
  printf("free\n");
  result=dk2m_lvl_free(&lvl,flags);
  return 0;
}
