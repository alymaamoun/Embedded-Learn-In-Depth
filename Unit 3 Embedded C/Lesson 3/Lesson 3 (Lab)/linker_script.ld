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
flash(RX): ORIGIN = 0x08000000, LENGTH = 128K 
sram(RWX): ORIGIN = 0x20000000, LENGTH = 20K
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
    _S_DATA = . ;
    *(.data)
    . = ALIGN(4) ;
    _E_DATA = .;
    }>sram AT>flash 

    .bss : 
    {
    _S_BSS = . ;
    *(.bss*)
    _E_BSS = . ;
    . = ALIGN(4) ;
    . = . + 0x1000;
    _STACK_TOP = . ;
    }>sram 


}



