/*
 * copyright (c) 2004 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of Libav.
 *
 * Libav is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Libav is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Libav; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef AVCODEC_UNARY_H
#define AVCODEC_UNARY_H

#include "bitstream.h"

/**
 * Get unary code of limited length
 * @param bc BitstreamContext
 * @param[in] stop The bitstop value (unary code of 1's or 0's)
 * @param[in] len Maximum length
 * @return Unary length/index
 */
static inline int get_unary(BitstreamContext *bc, int stop, int len)
{
    int i;

    for (i = 0; i < len && bitstream_read_bit(bc) != stop; i++)
        ;
    return i;
}

/**
 * Get unary code terminated by a 0 with a maximum length of 33
 * @param bc BitstreamContext
 * @return Unary length/index
 */
static inline int get_unary_0_33(BitstreamContext *bc)
{
    return get_unary(bc, 0, 33);
}

static inline int get_unary_0_9(BitstreamContext *bc)
{
    return get_unary(bc, 0, 9);
}

#endif /* AVCODEC_UNARY_H */
