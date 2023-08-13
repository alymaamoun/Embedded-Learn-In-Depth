/* Linker Script Cortex M3
CopyRights for EmbeddedSystems_Uc
*/



/*MEMORY TYPE (ACTIONS) : ORIGIN = ADDRESS , LENGTH = SIZE */
/*ACTIONS: 
r: read
w: write
x: execute
*/

MEMORY
{
flash(RX) : ORIGIN = 0x00000000, LENGTH = 512M 
sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512M
Peripheral(RWX) : ORIGIN = 0x40000000, LENGTH = 512M
}



/*
    Section_Name : {
             SourceFile(Section_inFile)
    }>VA AT>LA

*/
/*
    VA: Virtual Address (Run time)
    LA: Load Address (Load time)
*/


SECTIONS    
{
    .text :
    {
    *(.vectors*)
    *(.text*)
    *(.rodata*)
    _E_TEXT = . ; /*end of text*/
    }>flash
    
    .data : 
    {
    /*SAVE START ADDRSS OF DATA*/
    _S_DATA = . ;
    *(.data)
    . = ALIGN(4) ;
    /*SAVE END ADDRSS OF DATA*/
    _E_DATA = .;
    /*DATA SECTION IS LOADED FROM THE FLASH TO THE SRAM AT RUNTIME*/
    }>sram AT>flash 

    .bss : 
    {
    /*SAVE START ADDRSS OF BSS*/
    _S_BSS = . ;
    *(.bss*)
    /*SAVE END ADDRSS OF BSS*/
    _E_BSS = . ;
    /*ALIGN FOR BETTER PERFORMANE*/
    . = ALIGN(4) ;
    }>sram 


}



