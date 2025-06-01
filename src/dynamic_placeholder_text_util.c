#include "global.h"
#include "text.h"
#include "dynamic_placeholder_text_util.h"
#include "string_util.h"

static EWRAM_DATA const u8 *sStringPointers[8] = {};

void DynamicPlaceholderTextUtil_Reset(void)
{
    const u8 **ptr;
    u8 *fillval;
    const u8 **ptr2;

    ptr = sStringPointers;
    fillval = NULL;
    ptr2 = ptr + (ARRAY_COUNT(sStringPointers) - 1);
    do
    {
        *ptr2-- = fillval;
    } while ((int)ptr2 >= (int)ptr);
}

void DynamicPlaceholderTextUtil_SetPlaceholderPtr(u8 idx, const u8 *ptr)
{
    if (idx < ARRAY_COUNT(sStringPointers))
    {
        sStringPointers[idx] = ptr;
    }
}

u8 *DynamicPlaceholderTextUtil_ExpandPlaceholders(u8 *dest, const u8 *src)
{
    while (*src != EOS)
    {
        if (*src != CHAR_DYNAMIC)
        {
            *dest++ = *src++;
        }
        else
        {
            src++;
            if (sStringPointers[*src] != NULL)
            {
                dest = StringCopy(dest, sStringPointers[*src]);
            }
            src++;
        }
    }
    *dest = EOS;
    return dest;
}

const u8 *DynamicPlaceholderTextUtil_GetPlaceholderPtr(u8 idx)
{
    return sStringPointers[idx];
}

void FormatTextByWidth(u8 *result, s32 maxWidth, u8 fontId, const u8 *str, s16 letterSpacing)
{
    u8 *end, *ptr, *curLine, *lastSpace;

    end = result;
    // copy string, replacing all space with EOS
    while (*str != EOS)
    {
        if (*str == CHAR_SPACE)
            *end = EOS;
        else
            *end = *str;

        end++;
        str++;
    }
    *end = EOS; // now end points to the true end of the string

    ptr = result;
    curLine = ptr;

    while (*ptr != EOS)
        ptr++;
    // now ptr is the first EOS char

    while (ptr != end)
    {
        // all the EOS chars (except *end) must be replaced by either ' ' or '\n'
        lastSpace = ptr++; // this points at the EOS

        // check that adding the next word this line still fits
        *lastSpace = CHAR_SPACE;
        if (GetStringWidth(fontId, curLine, letterSpacing) > maxWidth)
        {
            *lastSpace = CHAR_NEWLINE;

            curLine = ptr;
        }

        while (*ptr != EOS)
            ptr++;
        // now ptr is the next EOS char
    }
}

