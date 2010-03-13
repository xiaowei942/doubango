/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsdp_header.c
 * @brief Defines a SDP header/line (<type>=<value>).
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tinySDP/headers/tsdp_header.h"

#include "tinySDP/headers/tsdp_header_Dummy.h"

int tsdp_header_rank_cmp(const tsdp_header_t* hdr1, const tsdp_header_t* hdr2)
{
	if(hdr1 && hdr2){
		return (hdr1->rank - hdr2->rank);
	}
	else{
		return -1;
	}
}

/** Gets the name of the SDP header with a type equal to @a type. 
 * @param	type	The @a type of the header for which to retrieve the name. 
 *
 * @return	The name of the header.
**/
char tsdp_header_get_name(tsdp_header_type_t type)
{
	switch(type)
	{
		case tsdp_htype_A: return 'a';			
		case tsdp_htype_B: return 'b';
		case tsdp_htype_C: return 'c';
		case tsdp_htype_E: return 'e';
		case tsdp_htype_I: return 'i';
		case tsdp_htype_K: return 'k';
		case tsdp_htype_M: return 'm';
		case tsdp_htype_O: return 'o';
		case tsdp_htype_P: return 'p';
		case tsdp_htype_R: return 'r';
		case tsdp_htype_S: return 's';
		case tsdp_htype_T: return 't';
		case tsdp_htype_U: return 'u';
		case tsdp_htype_V: return 'v';
		case tsdp_htype_Z: return 'z';

		default: return '*';
	}
}

char tsdp_header_get_nameex(const tsdp_header_t *self)
{
	if(self){
		if(self->type == tsdp_htype_Dummy){
			return ((tsdp_header_Dummy_t*)(self))->name;
		}
		else{
			return tsdp_header_get_name(self->type);
		}
	}
	return '*';
}


int tsdp_header_tostring(const tsdp_header_t *self, tsk_buffer_t *output)
{
	static char name;
	int ret = -1;
	if(!self || !output){
		return -1;
	}

	/* Name */
	name = tsdp_header_get_nameex(self);
	tsk_buffer_appendEx(output, "%c=", name);

	/* Value */
	if((ret = self->tostring(self, output))){
		// Abort?
	}

	/* CRLF*/
	ret = tsk_buffer_append(output, "\r\n", 2);

	return ret;
}