#include "unity.h"
#include "climatizacion.h"


void setUp (void)  {

}

void tearDown (void)  {

}

void test_ClimatizacionOff(void)  {
   //creamos un control virtual de encendido_apagado
   bool on_off_virtual = false;

   Climatizacion_create(&on_off_virtual);
   Climatizacion_OnOff(true);
   TEST_ASSERT_EQUAL(true,on_off_virtual);
}

void test_ClimatizacionOn(void)  {
   //creamos un control virtual de encendido_apagado
   bool on_off_virtual = false;

   Climatizacion_create(&on_off_virtual);
   Climatizacion_OnOff(false);
   TEST_ASSERT_EQUAL(false,on_off_virtual);
}
