/****************************************************************************
 * \file irioHandlerAnalog.h
 * \authors Mariano Ruiz (Universidad Politécnica de Madrid, UPM)
 * \authors Diego Sanz (Universidad Politécnica de Madrid, UPM)
 * \authors Sergio Esquembri (Universidad Politécnica de Madrid, UPM)
 * \authors Enrique Bernal (Universidad Politécnica de Madrid, UPM)
 * \authors Alvaro Bustos (Universidad Politécnica de Madrid, UPM)
 * \brief Analog I/O handler methods for IRIO Driver
 * \date Sept., 2010 (Last Review July 2015)
 * \copyright (C) 2010-2015 Universidad Politécnica de Madrid (UPM)
 * \par License:
 * 	\n This project is released under the GNU Public License version 2.
 * \cond
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * \endcond
 *****************************************************************************/

#pragma once

#include "irioDataTypes.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Read an analog input
 *
 * Reads the value from an analog input port.
 * Errors may occur if the port was not found or while reading from the port.
 *
 * @param[in] p_DrvPvt 	Pointer to the driver session structure
 * @param[in] n Number of the analog input to read (AIn)
 * @param[out] value  Current value of the analog input
 * @param[out] status	Warning and error messages produced during the execution of this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_getAI(irioDrv_t *p_DrvPvt, int n, int32_t *value, TStatus *status);

/**
 * Read an auxiliary analog input
 *
 * Reads the value from an auxiliary analog input port.
 * Errors may occur if the port was not found or while reading from the port.
 *
 * @param[in] p_DrvPvt 	Pointer to the driver session structure
 * @param[in] n Number of the auxiliary analog input to read (AIn)
 * @param[out] value  Current value of the auxiliary analog input
 * @param[out] status	Warning and error messages produced during the execution of this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_getAuxAI(irioDrv_t *p_DrvPvt, int n, int32_t *value, TStatus *status);

/**
 * Read a 64 bits auxiliary analog input
 *
 * Reads the value from a 64 bits auxiliary analog input port.
 * Errors may occur if the port was not found or while reading from the port.
 *
 * @param[in] p_DrvPvt 	Pointer to the driver session structure
 * @param[in] n Number of the auxiliary analog input to read (AIn)
 * @param[out] value  Current value of the auxiliary analog input
 * @param[out] status	Warning and error messages produced during the execution of this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_getAuxAI_64(irioDrv_t *p_DrvPvt, int n, int64_t *value,
		TStatus *status);

/**
 * Read an analog output
 *
 * Reads the value from an analog output port.
 * Errors may occur if the port was not found or while reading from the port.
 *
 * @param[in] p_DrvPvt 	Pointer to the driver session structure
 * @param[in] n Number of the analog output to read (AOn)
 * @param[out] value  Current value of the analog output
 * @param[out] status	Warning and error messages produced during the execution of this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_getAO(irioDrv_t *p_DrvPvt, int n, int32_t *value, TStatus *status);

/**
 * Write an analog output
 *
 * Writes the given value in an analog output port.
 * Errors may occur if the port was not found or while writing to the port.
 *
 * @param[in] p_DrvPvt 	Pointer to the driver session structure
 * @param[in] n Number of the analog output to write (AOn)
 * @param[in] value Value to write
 * @param[out] status	Warning and error messages produced during the execution of this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_setAO(irioDrv_t *p_DrvPvt, int n, int32_t value, TStatus *status);

/**
 * Read an Analog Output Enable
 *
 * Reads from the FPGA whether a analog output port is enabled or not.
 * Errors may occur if the port was not found or while reading from the port
 *
 * @param[in] p_DrvPvt 	Pointer to the driver session structure
 * @param[in] n Number of the analog output port which enable signal will be read (AOEnablen)
 * @param[out] value   Current value of analog output enable
 * @param[out] status	Warning and error messages produced during the execution of this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_getAOEnable(irioDrv_t *p_DrvPvt, int n, int32_t *value,
		TStatus *status);

/**
 * Enable or disable an analog output
 *
 * Writes in a FPGA register to enable or disable the output for a analog output port.
 * Errors may occur if the port was not found or while writing to the port
 *
 * @param[in] p_DrvPvt 	Pointer to the driver session structure
 * @param[in] n Number of the analog output to enable/disable (AOEnablen)
 * @param[in] value 0=Disable Analog Output, 1=Enable Analog Output
 * @param[out] status	Warning and error messages produced during the execution of this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_setAOEnable(irioDrv_t *p_DrvPvt, int n, int32_t value,
		TStatus *status);

/**
 * Read an auxiliary analog output
 *
 * Reads the value from an auxiliary analog output port.
 * Errors may occur if the port was not found or while reading from the port
 *
 * @param[in] p_DrvPvt 	Pointer to the driver session structure
 * @param[in] n Number of the auxiliary analog output to read (auxAOn)
 * @param[out] value  Current value of the auxiliary analog output
 * @param[out] status	Warning and error messages produced during the execution of this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_getAuxAO(irioDrv_t *p_DrvPvt, int n, int32_t *value, TStatus *status);

/**
 * Read a 64 bits auxiliary analog output
 *
 * Reads the value from a 64 bits auxiliary analog output port.
 * Errors may occur if the port was not found or while reading from the port
 *
 * @param[in] p_DrvPvt 	Pointer to the driver session structure
 * @param[in] n Number of the auxiliary analog output to read (auxAOn)
 * @param[out] value  Current value of the auxiliary analog output
 * @param[out] status	Warning and error messages produced during the execution of this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_getAuxAO_64(irioDrv_t *p_DrvPvt, int n, int64_t *value,
		TStatus *status);

/**
 * Write an auxiliary analog output
 *
 * Writes the given value in an auxiliary analog output port.
 * Errors may occur if the port was not found or while writing to the port.
 *
 * @param[in] p_DrvPvt 	Pointer to the driver session structure
 * @param[in] n Number of the auxiliary analog output to write (auxAOn)
 * @param[in] value Value to write
 * @param[out] status	Warning and error messages produced during the execution of this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_setAuxAO(irioDrv_t *p_DrvPvt, int n, int32_t value, TStatus *status);

/**
 * Write a 64 bits auxiliary analog output
 *
 * Writes the given value in a 64 bits auxiliary analog output port.
 * Errors may occur if the port was not found or while writing to the port.
 *
 * @param[in] p_DrvPvt 	Pointer to the driver session structure
 * @param[in] n Number of the auxiliary analog output to write (auxAOn)
 * @param[in] value Value to write
 * @param[out] status	Warning and error messages produced during the execution of this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_setAuxAO_64(irioDrv_t *p_DrvPvt, int n, int64_t value,
		TStatus *status);

/**
 * Returns the number of analog inputs found in the FPGA
 *
 * @param[in] p_DrvPvt	Pointer to the driver session structure
 * @param[out] value	Pointer to store the number of resources found
 * @param[out] status   Warning and error messages produced during the execution of
 * 						this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_getNumAI(irioDrv_t *p_DrvPvt, size_t *value, TStatus *status);

/**
 * Returns the number of analog outputs found in the FPGA
 *
 * @param[in] p_DrvPvt	Pointer to the driver session structure
 * @param[out] value	Pointer to store the number of resources found
 * @param[out] status   Warning and error messages produced during the execution of
 * 						this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_getNumAO(irioDrv_t *p_DrvPvt, size_t *value, TStatus *status);

/**
 * Returns the number of aux analog inputs found in the FPGA
 *
 * @param[in] p_DrvPvt	Pointer to the driver session structure
 * @param[out] value	Pointer to store the number of resources found
 * @param[out] status   Warning and error messages produced during the execution of
 * 						this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_getNumAuxAI(irioDrv_t *p_DrvPvt, size_t *value, TStatus *status);

/**
 * Returns the number of aux analog outputs found in the FPGA
 *
 * @param[in] p_DrvPvt	Pointer to the driver session structure
 * @param[out] value	Pointer to store the number of resources found
 * @param[out] status   Warning and error messages produced during the execution of
 * 						this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_getNumAuxAO(irioDrv_t *p_DrvPvt, size_t *value, TStatus *status);

/**
 * Returns the number of aux analog inputs 64 bits found in the FPGA
 *
 * @param[in] p_DrvPvt	Pointer to the driver session structure
 * @param[out] value	Pointer to store the number of resources found
 * @param[out] status   Warning and error messages produced during the execution of
 * 						this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_getNumAuxAI64(irioDrv_t *p_DrvPvt, size_t *value, TStatus *status);

/**
 * Returns the number of aux analog outputs 64 bits found in the FPGA
 *
 * @param[in] p_DrvPvt	Pointer to the driver session structure
 * @param[out] value	Pointer to store the number of resources found
 * @param[out] status   Warning and error messages produced during the execution of
 * 						this call will be added here.
 * @return \ref TIRIOStatusCode result of the execution of this call.
 */
int irio_getNumAuxAO64(irioDrv_t *p_DrvPvt, size_t *value, TStatus *status);

#ifdef __cplusplus
}
#endif