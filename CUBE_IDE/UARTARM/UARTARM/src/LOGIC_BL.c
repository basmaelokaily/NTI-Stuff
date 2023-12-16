#include "LOGIC_BL.h"

struct Record_t record;

u16 Hight_Address;
u32 Full_Address;


void Parser(u8* Record)
{
	u8 Rec_type = GET_RECORD_TYPE(Record);

	if (Rec_type == 0x00)
	{
		record.Data_Size = GET_Data_Bit_Size(Record);
		record.Low_Add = GET_Address(Record);
		record.Check_Sum = GET_Checksum(Record, record.Data_Size);
		for (u8 i = 0; i < 16; i++)
		{
			record.Data[i] = NULL;
		}
		for (u8 i = 0; i < record.Data_Size; i++)
		{
			record.Data[i] = Record[i + 4];
		}
	}
	else if (Rec_type == 0x01)
    {
        Hight_Address = Record[4] << 8 | Record[5];
        record.Data_Size = NULL;
		record.Low_Add = NULL;
		record.Check_Sum = NULL;
		for (u8 i = 0; i < 16; i++)
		{
			record.Data[i] = NULL;
		}
        printf("This is the End of the Hex File\n");
    }
    else if (Rec_type == 0x02)
    {
        printf("Obsolete\n");
    }
    else if (Rec_type == 0x03)
    {
        printf("Obsolete\n");
    }
    else if (Rec_type == 0x04)
    {
        Hight_Address = Record[4] << 8 | Record[5];
        record.Data_Size = NULL;
		record.Low_Add = NULL;
		record.Check_Sum = NULL;
		for (u8 i = 0; i < 16; i++)
		{
			record.Data[i] = NULL;
		}
        printf("High Address %X\n", Hight_Address);
    }
    else if (Rec_type == 0x05)
    {
        Hight_Address = Record[4] << 8 | Record[5];
        record.Data_Size = NULL;
		record.Low_Add = NULL;
		record.Check_Sum = NULL;
		for (u8 i = 0; i < 16; i++)
		{
			record.Data[i] = NULL;
		}
        Full_Address = Record[4] << 24 | Record[5] << 16| Record[6] << 8 | Record[7];
        printf("Full Address%X\n", Full_Address);
    }
}
/*
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
}*/
/*
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

}*/
u8 Make_Byte(u8 num1, u8 num2)
{
	return (num1<<4 | num2);
}

u8 GET_RECORD_TYPE(u8* Record)
{
    return Record[3];
}

u16 GET_Address(u8* Record)
{
    return Record[1] << 8 | Record[2] ;
}

u8 GET_Data_Bit_Size(u8* Record)
{
    return Record[0];
}

u8 GET_Checksum(u8* Record, u8 size)
{
    return Record[size + 4];
}

void print_Data(void)
{
    printf("Record Size = 0x%x\n", record.Data_Size);
    printf("Record Address = 0x%x\n", record.Low_Add);
    for (u8 i = 0; i < record.Data_Size; i++)
    {
        if (i == 0)
        {
            printf("Data = 0x");
        }
        printf("%X", record.Data[i]);
        if (i == record.Data_Size - 1)
        {
            printf("\n");
        }
    }
    printf("Record Checksum = 0x%x\n", record.Check_Sum);
}
