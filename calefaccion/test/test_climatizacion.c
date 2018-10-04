#include "unity.h"
#include "climatizacion.h"


void setUp (void)  {

}

void tearDown (void)  {

}

/*****************************************************************************
    TEST Correspondientes a requerimiento AUTO-ER-0001-REQ0019
*******************************************************************************/
void test_ClimatizacionOff(void)  {
   //creamos un control virtual de encendido_apagado
   bool on_off_virtual = false;
   uint8_t selector_temp_virtual = 24;

   Climatizacion_create(&on_off_virtual, &selector_temp_virtual);
   Climatizacion_OnOff(true);
   TEST_ASSERT_EQUAL(true,on_off_virtual);
}

void test_ClimatizacionOn(void)  {
   //creamos un control virtual de encendido_apagado
   bool on_off_virtual = false;
   uint8_t selector_temp_virtual = 24;

   Climatizacion_create(&on_off_virtual, &selector_temp_virtual);
   Climatizacion_OnOff(false);
   TEST_ASSERT_EQUAL(false,on_off_virtual);
}
//-----------------------------------------------------------------------------


/*****************************************************************************
    TEST Correspondientes a requerimiento AUTO-ER-0001-REQ0018
*******************************************************************************/
void test_ClimatizacionSetTemp(void)  {
    //creamos un selector de temperatura virtual con valor por defecto
    bool on_off_virtual = false;
    uint8_t selector_temp_virtual = 24;

    Climatizacion_create(&on_off_virtual, &selector_temp_virtual);
    Climatizacion_SetTemp(26);
    TEST_ASSERT_EQUAL_UINT8(26,selector_temp_virtual);
}

//-----------------------------------------------------------------------------
