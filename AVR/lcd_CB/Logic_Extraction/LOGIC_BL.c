#include "LOGIC_BL.h"

struct Record_t DATA_LINE[64];

u16 Hight_Address = 0;

void Parser(u8* Record,uint16 Length_Rec, Record_t* struct)
{
       u8 cc,rec_type, Data_size, data_line = 0;
       u16 Add_low_Part;


	   //long double data_rec;
    for(u16 i=0, i< Length_Rec; i++)
    {
        if(Record[i] == ':')
        {
            cc = Record[i+1] << 4 | Record[i+2];
            rec_type = Calculate_RT(Record, i);
            Data_size = 0;
            if(rec_type == 0x00)
            {
                //normal process call write line of data


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

u8 Write_line_of_Data(u8* Record, u16 i_Record, u8 counter, u8 *Data_arr, u8 Data_Bits)
{
	static u8 index_1 = i_Record + 9;
	static u8 index_2 = i_Record + 10;
	for (u8 k = 0; k < Data_Bits; k++)
	{
		DATA_LINE[counter].Data_arr[k] = Make_Byte(Record[index_1], Record[index_2]);
		index_1 = index_1 + 2 ;
		index_2 = index_2 + 2;
	}
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
					return E_OK;
				}
				else
				{
					return E_NOK;
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

u8 Calculate_RT(u8* Record, u8 index)
{
    return Record[index+7] << 4 | Record[index+8];
}

u16 Create_Address(u8* Record, u8 index)
{
    return Record[i+3] << 12 | Record[i+4] << 8 | Record[i+5]<< 4 | Record[i+6];
}

u8 Calculate_Data_Bit_Size(u8* Record, u8 index)
{
    return Record[index+1] << 4 |Record[index+2];
}
