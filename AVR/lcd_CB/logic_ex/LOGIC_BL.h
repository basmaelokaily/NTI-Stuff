#ifndef LOGIB_BL_H_INCLUDED
#define LOGIB_BL_H_INCLUDED
#include "std_types.h"

struct Record_t {
 u16 Low_Add;
 u8 Data[16];  //64 record inside each record there is 16 code bytes

};

typedef enum {ES_NOK, ES_OK}ErrorStatus;

void Parser(u8* Record,u16 Length_Rec, struct Record_t* data_lines);
u8 Write_line_of_Data(u8* Record, u16 i_Record, u8 counter, struct Record_t* data_lines, u8 Data_Bits);
u8 Check_Sum(u8* Record, u16 Length_Rec);
u8 Make_Byte(u8 num1, u8 num2);
u8 GET_RECORD_TYPE(u8* Record, u8 index);
u16 GET_Address(u8* Record, u8 index);
u8 GET_Data_Bit_Size(u8* Record, u8 index);

#endif // LOGIB_BL_H_INCLUDED
