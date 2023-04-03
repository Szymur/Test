
#include <stdio.h>
#include <stdint.h>

uint8_t Val = 5;
uint8_t Val2 = 10;


typedef enum 
{
    STATUS_OK = 0,
    STATUS_ERROR = 1
    
}Status_t;

Status_t Function(uint8_t DataIn, uint8_t *DataToAdd, uint8_t *DataToSub);

int main()
{
   Status_t Status;
   
   printf("Before: Status: %d, Val: %d, Val2: %d\n\r", Status, Val, Val2);
   
   Status = Function(1, &Val, &Val2);
   
   printf("After:  Status: %d, Val: %d, Val2: %d\n\r", Status, Val, Val2);

    return 0;
}

Status_t Function(uint8_t DataIn, uint8_t *DataToAdd, uint8_t *DataToSub)
{
    if (DataIn == 0)
    {
        return STATUS_ERROR;
    }
    
    if ((*DataToAdd > (255 - DataIn)) || (*DataToSub < DataIn) )
    {
        return STATUS_ERROR;
    }
    
    *DataToAdd  += DataIn;
    *DataToSub  -= DataIn;
    
    return STATUS_OK;
}

