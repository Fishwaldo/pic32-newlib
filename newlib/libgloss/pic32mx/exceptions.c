
#include <stdlib.h>

extern void _on_reset() __attribute__((weak));

extern void _nmi_handler() __attribute__((weak)) __attribute__((nomips16));

extern void _on_bootstrap() __attribute__((weak)); 

extern void _bootstrap_exception_handler() __attribute__((weak)) __attribute__((nomips16));

extern void _general_exception_handler(unsigned cause, unsigned status) __attribute__((weak)); /* should have nomips16 here as well */

void _on_reset() {
  /* nothing */
  __asm__ __volatile__ ("%(nop%)" : :);
}

void _nmi_handler() {

}

void _on_bootstrap() {
  /* nothing */
  __asm__ __volatile__ ("%(nop%)" : :);
}

void _bootstrap_exception_handler() {
  while (1) {
  __asm__ __volatile__ ("%(nop%)" : :);
  }
};

void _general_exception_context() {
/* The provided implementation
 * of this function saves context, calls an application handler function, restores context
 * and performs a return from exception instruction. The context saved is the hi and lo
 * registers and all general purpose registers except s0-s8, which are defined to be
 * preserved by all called functions and so are not necessary to actively save again here.
 * The values of the Cause and Status registers are passed to the application handler
 * function (_general_exception_handler())
 */
 
 /* XXX TODO: write this function */
 _general_exception_handler(0,0);
};


void _general_exception_handler(unsigned cause, unsigned status) {
  while (1) {
  __asm__ __volatile__ ("%(nop%)" : :);
  }
};
