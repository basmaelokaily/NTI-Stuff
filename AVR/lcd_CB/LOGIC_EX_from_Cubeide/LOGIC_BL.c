#include "LOGIC_BL.h"

struct Record_t record;

u16 Hight_Address;
u32 Full_Address;


void Parser(u8* Record)
{
	if (CAN_FINISHED_TRANSMISSION_FLAG == 1)
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
            record.Data_Size = GET_Data_Bit_Size(Record);
            record.Low_Add = GET_Address(Record);
            record.Check_Sum = GET_Checksum(Record, record.Data_Size);
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
            printf("High Address %X\n", Hight_Address);
        }
        else if (Rec_type == 0x05)
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
            Full_Address = Record[4] << 24 | Record[5] << 16| Record[6] << 8 | Record[7];
            printf("Full Address%X\n", Full_Address);
        }
    }
}

u8 Check_Sum(u8* Record)
{
    u16 sum = 0x0;
    u8 checksum = 0x0;
    u8 inverted = 0x0;
    for(u8 i = 0; i < record.Data_Size + 4; i++)
    {
        sum += Record[i];
    }
    checksum = sum & 0x00ff;
    inverted = (~checksum) + 1;
    printf("Checksum  %X\n", inverted);
    if (inverted == record.Check_Sum)
    {
        printf("This record's bits have been sent correctly\n");
        return ES_OK;
    }
    else
    {
        return ES_NOK;
    }


}
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

u8 GET_Checksum(u8* Record, u8 size_)
{
    return Record[size_ + 4];
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
