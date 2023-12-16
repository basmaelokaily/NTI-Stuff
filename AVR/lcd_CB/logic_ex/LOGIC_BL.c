#include "LOGIC_BL.h"

struct Record_t DATA_LINE[64];

u16 Hight_Address;


void Parser(u8* Record,u16 Length_Rec, struct Record_t* data_lines)
{
	u8 cc = 0;
	u8 rec_type = 0;
	u8 Data_size = 0;
	u8 line_counter = 0;
	//long double data_rec;
    for(u16 i=0; i< Length_Rec; i++)
    {
        if(Record[i] == ':')
        {
            cc = Record[i+1] << 4 | Record[i+2];
            rec_type = GET_RECORD_TYPE(Record, i);
            Data_size = 0;
            if(rec_type == 0x00)
            {
                //normal process call write line of data u8* Record, u16 i_Record, u8 counter, struct Record_t* data_lines, u8 Data_Bits
				Write_line_of_Data(Record, i, line_counter, DATA_LINE, GET_Data_Bit_Size(Record, i));
				if (!(line_counter > 63) && !(line_counter < 0))
				{
					line_counter++;
				}
            }
            else if (rec_type == 0x01)
            {
                //end of file write special char to the data array
            }
            else if (rec_type == 0x04)
            {
                //data bits represents the high address
                Hight_Address = Record[i+9] << 12 | Record[i+10] << 8 | Record[i+11]<< 4 | Record[i+12];
            }
            else if (rec_type == 0x05)
            {

            }
        }
    }
}

u8 Write_line_of_Data(u8* Record, u16 i_Record, u8 counter, struct Record_t* data_lines, u8 Data_Bits)
{	
	//static
	ErrorStatus State = ES_OK;
	static u8 index_1 = 0;
	static u8 index_2 = 0;
	index_1 = i_Record + 9;
	index_2 = i_Record + 10;
	data_lines[counter].Low_Add = GET_Address(Record, i_Record);
	for (u8 k = 0; k < Data_Bits; k++)
	{
		data_lines[counter].Data[k] = Make_Byte(Record[index_1], Record[index_2]);
		index_1 = index_1 + 2 ;
		index_2 = index_2 + 2;
	}
	return State;
}

u8 Check_Sum(u8* Record, u16 Length_Rec)
{
		u16 sum = 0;
		u8 BYTE = 0;
		u8 CS = 0;
		u8 Low_Byte = 0;
		for (u16 i = 0; i < Length_Rec; i+2)
		{
			if (Record[i] == ':')
			{
				sum = 0;
			}
			if (Record[i] == '\n')
			{
				CS = Make_Byte(Record[i-2], Record[i-1]);
				sum = sum - CS;
				Low_Byte = sum & 0x00ff;
				Low_Byte = (~Low_Byte) + 1;
				if (Low_Byte == CS)
				{
					return ES_OK;
				}
				else
				{
					return ES_NOK;
					//resend the whole hex file again
				}
			}
			else{
				BYTE = Make_Byte(Record[i+1], Record[i+2]);
				sum += BYTE;
			}

		}
}
u8 Make_Byte(u8 num1, u8 num2)
{
	return (num1<<4 | num2);
}

u8 GET_RECORD_TYPE(u8* Record, u8 index)
{
    return Record[index+7] << 4 | Record[index+8];
}

u16 GET_Address(u8* Record, u8 index)
{
    return Record[index+3] << 12 | Record[index+4] << 8 | Record[index+5]<< 4 | Record[index+6];
}

u8 GET_Data_Bit_Size(u8* Record, u8 index)
{
    return Record[index+1] << 4 |Record[index+2];
}
