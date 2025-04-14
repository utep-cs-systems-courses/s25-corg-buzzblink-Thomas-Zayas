#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"


int main() {

  int cyc = 4545;
  configureClocks();
  switch_init();
  buzzer_init();
  enableWDTInterrupts();

    or_sr(0x18);          // CPU off, GIE on
}
int count= 0;
int secondCount = 0;
int newnote = 0;

void __interrupt_vec(WDT_VECTOR) WDT() 
{
  secondCount ++;
  if (secondCount >= 60) { 
    update_note(0);
    
  }
  
   if(secondCount >=65){
     
     newnote = notes[count];
     update_note(newnote);
     count++;
     secondCount = 0;
    }
   
    
  
}

