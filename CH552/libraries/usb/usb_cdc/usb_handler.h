// ===================================================================================
// USB Handler for CH551, CH552 and CH554                                     * v1.3 *
// ===================================================================================

#pragma once
#include <stdint.h>
#include "usb_descr.h"

// ===================================================================================
// Variables
// ===================================================================================
#define USB_SetupBuf     ((PUSB_SETUP_REQ)EP0_buffer)
extern volatile uint8_t  USB_SetupReq, USB_SetupTyp;
extern volatile uint16_t USB_SetupLen;

// ===================================================================================
// Custom External USB Handler Functions
// ===================================================================================
uint8_t CDC_control(void);
void CDC_EP_init(void);
void CDC_EP0_OUT(void);
void CDC_EP2_IN(void);
void CDC_EP2_OUT(void);

// ===================================================================================
// USB Handler Defines
// ===================================================================================
// Custom USB handler functions
#define USB_INIT_endpoints  CDC_EP_init       // custom USB EP init handler
#define USB_CTRL_NS_handler CDC_control       // handle custom non-standard requests

// Endpoint callback functions
#define EP0_SETUP_callback  USB_EP0_SETUP
#define EP0_IN_callback     USB_EP0_IN
#define EP0_OUT_callback    CDC_EP0_OUT
#define EP2_IN_callback     CDC_EP2_IN
#define EP2_OUT_callback    CDC_EP2_OUT

// ===================================================================================
// Functions
// ===================================================================================
void USB_interrupt(void);
void USB_init(void);
