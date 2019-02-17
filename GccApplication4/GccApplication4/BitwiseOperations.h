/*
 * BitwiseOperations.h
 *
 * Created: 2/13/2019 11:38:14 AM
 *  Author: AVE-LAP-032
 */ 

#ifndef BITWISEOPERATIONS_H_
#define BITWISEOPERATIONS_H_

#define Set_Bit(Register,Bit)     ( Register |= ( 1 << (Bit)  ) )

#define Clear_Bit(Register,Bit)   (Register  &= (~(1<<(Bit)   ) )  )

#define Get_Bit(Register,Bit)     ( (Register & (1<<(Bit)) )>>(Bit))

#define Toggle_Bit(Register,Bit)  (Register ^=  (1<<(Bit)  )  )


#endif /* BITWISEOPERATIONS_H_ */