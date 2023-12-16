#ifndef LOGIB_BL_H_INCLUDED
#define LOGIB_BL_H_INCLUDED
#include "std_types.h"

typedef struct{
 uint16 High_add_Part;
 uint8 Data_arr[16];  //64 record inside each record there is 16 code bytes

}Record_t;

void Parser(u8* Record,u16 Length_Rec, Record_t* struct);
u8 Write_line_of_Data(u8* Record, u16 i_Record, u8 counter, u8 *Data_arr);
u8 Check_Sum(u8* Record, u16 Length_Rec);
u8 Make_Byte(u8 num1, u8 num2);
u8 Calculate_RT(u8 index);

#endif // LOGIB_BL_H_INCLUDED
