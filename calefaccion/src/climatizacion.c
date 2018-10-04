#include "climatizacion.h"
#include "hardware.h"

static struct _climatizacionCtrl g_sControl_climatizacion;
static bool g_bCalefactor = false;

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


void Climatizacion_setEstadoCalefactor (bool X)  {
  g_bCalefactor = X;
}

bool Climatizacion_getEstadoCalefactor (void)  {
  return g_bCalefactor;
}

uint8_t Climatizacion_readTemp(void)  {
  uint8_t rawValue;

  rawValue = getADC_value();
  return rawValue;
}


bool Climatizacion_Calefaccion(uint8_t tempAmbiente)  {
  bool Ret;
  if (*(g_sControl_climatizacion.IO_ctrl))  {
    if (tempAmbiente < (*(g_sControl_climatizacion.IO_ctrl) - 2 ))  {
      Climatizacion_setEstadoCalefactor(true);
    }
    else  {
      Climatizacion_setEstadoCalefactor(false);
    }
  }
  Ret = Climatizacion_getEstadoCalefactor();

  return Ret;
}
