/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_HARDWARE_H
#define _MOCK_HARDWARE_H

#include "hardware.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_hardware_Init(void);
void mock_hardware_Destroy(void);
void mock_hardware_Verify(void);




#define getADC_value_IgnoreAndReturn(cmock_retval) getADC_value_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void getADC_value_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint16_t cmock_to_return);
#define getADC_value_ExpectAndReturn(cmock_retval) getADC_value_CMockExpectAndReturn(__LINE__, cmock_retval)
void getADC_value_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint16_t cmock_to_return);
typedef uint16_t (* CMOCK_getADC_value_CALLBACK)(int cmock_num_calls);
void getADC_value_StubWithCallback(CMOCK_getADC_value_CALLBACK Callback);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif