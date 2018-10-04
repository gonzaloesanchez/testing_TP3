#include "climatizacion.h"

static struct _climatizacionCtrl g_sControl_climatizacion;

void Climatizacion_create (bool *IO, uint8_t *setTemp)  {
  g_sControl_climatizacion.IO_ctrl = IO;
  g_sControl_climatizacion.temp_setting = setTemp;
}

void Climatizacion_OnOff (bool X)  {
  *(g_sControl_climatizacion.IO_ctrl) = X;
}


void Climatizacion_SetTemp (uint8_t temp)  {
    *(g_sControl_climatizacion.temp_setting) = temp;
}


uint8_t Climatizacion_readTemp(void)  {

}

bool Climatizacion_Calefaccion(uint8_t tempAmbiente)  {
  
}
