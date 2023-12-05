# FIRST: at start, we are at privilege, thumb, thread mode, at stack pointer MSP at 0x20005000
![image](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/6b59f133-d493-4fc3-8db8-37201f0dea1a)


# SECOND: now in MainOS we have successfully set the boundaries of the main stack and process stacks for task A,B ;Currently we are at the NOP while 1
![image](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/aeeb5ae8-3c6e-444c-ae98-e74c8bbd9f78)

without any interrupt, we will still be in the NOP while loop inside MainOs

## at the first interrupt:

![image](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/9b8da767-2278-4feb-883e-587db6f09697)

## the procedures says that the TaskA flag will be raised, then at the MainOs the TaskA_flag=1 condition will be true

![image](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/1da24798-e599-499f-8489-c42079b31047)
as the condition now it true;

## 1- PSP will be set to the start address of TaskA stack

![image](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/1d5595bf-75f3-428b-9070-4c7f451726b9)

## 2- SP will shadow on PSP

![image](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/93a667ab-2801-47d4-b280-2f137ca500e6)

## 3- the state will be unprivileged

![image](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/3659208d-dcea-47b0-a197-e6e4c1ade8d4)

## 4- Task A will be called ( will discuss the stacking)

###   A- Arguments are stored at registers r0-r3 (arguments registers) and command BL to go to the task

   ![image](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/a1558ec6-57df-41ac-8682-78d2b570f863)
   
###   B- now will branch to the task

  ![image](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/040f5efb-63ac-48d9-b052-1dae7f4c1ae1)
  
      the picture has illustration for the stacking and loading for the arguments to perform the needed actions
      
      -- first, r7 is pushed to the stack , r7 acts as frame pointer which points to the first address of the stack used during the call
      
      -- second, the stack pointer is now reserved 5 places for pushing
      
      -- now r7 is assigned to new value of stack frame(current call frame)
      
      -- r0 is stored in the bottom

      -- r1 is stored
      
      -- r2 is stored 
      
      to perform the a+b+c:
      
                          -- (first argument "stored at stack" is loaded at r2)
                          -- (second argument is loaded at r3)
                          --r2+=r3
                          -- (third argument is loaded at r3)
                          --r3+=r2
      -- now r3 is having the return value
      ![image](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/b66dcfeb-d21c-49b0-8079-30b0314f5afc)
      --r0 will have the return value (r0 in arm is the register that will have the return value)
      --stack for task a is cleared using frame pointer (r7)
      --frame pointer of the previous call is popped 
      --branch back using LR


##  5- returning to MainOS after returning from TaskA
## 6- return to privilege using SVC call
  ![image](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/2f63958e-f226-4719-b72e-fc4c535b96e2)
  
###  -- svc call is an interrupt call used to switch from thread mode to handler mode so that we can modify the control register

##  7-- return to main stack pointer
  
  ![image](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/ae28962f-ca02-4191-adab-fe1822111e58)


FINISHH

now for the inline assembly used:
![image](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/49dce8d4-313b-4326-aee3-9988922c6908)


                          

