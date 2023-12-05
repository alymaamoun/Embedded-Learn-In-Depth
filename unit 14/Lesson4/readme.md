# FIRST

![Thread,priveleged](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/444f7a00-2447-4192-8006-e819ca92b1b9)

## at this point, we are in thread mode after reset so we are in privilege mode

# SECOND


![Thread,unprivildegd](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/8c748a98-6a84-46f0-8a7c-973dd55220bb)
## at this point, we used the inline assembly to switch to unprivileged mode, so we can't access some features

# THIRD


 
 ![Handler,privildged,ISR captured using inline assembly retreving CONTROL reg](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/7562dac6-a3dc-4676-8f95-78ac335d292b)

## we are in handler mode, so privilege mode, additionally, we captured the ISR number in VAL11 using inline assembly by MRS reading from xPSR register and at the call back we set the next thread mode to be in privilege mode

# FOURTH

 ![returned to thread prviliage](https://github.com/alymaamoun/Embedded-Learn-In-Depth/assets/53837104/6c506d7d-4e0e-466b-94fc-c7811174241c)
## returned to thread, privilege
