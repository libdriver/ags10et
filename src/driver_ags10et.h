/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_ags10et.h
 * @brief     driver ags10et header file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2024-10-31
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2024/10/31  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#ifndef DRIVER_AGS10ET_H
#define DRIVER_AGS10ET_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup ags10et_driver ags10et driver function
 * @brief    ags10et driver modules
 * @{
 */

/**
 * @addtogroup ags10et_base_driver
 * @{
 */

/**
 * @brief ags10et handle structure definition
 */
typedef struct ags10et_handle_s
{
    uint8_t (*iic_init)(void);                                                          /**< point to an iic_init function address */
    uint8_t (*iic_deinit)(void);                                                        /**< point to an iic_deinit function address */
    uint8_t (*iic_read_cmd)(uint8_t addr, uint8_t *buf, uint16_t len);                  /**< point to an iic_read_cmd function address */
    uint8_t (*iic_write_cmd)(uint8_t addr, uint8_t *buf, uint16_t len);                 /**< point to an iic_write_cmd function address */
    uint8_t (*iic_write)(uint8_t addr, uint8_t reg, uint8_t *buf, uint16_t len);        /**< point to an iic_write function address */
    void (*delay_ms)(uint32_t ms);                                                      /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);                                    /**< point to a debug_print function address */
    uint8_t inited;                                                                     /**< inited flag */
    uint8_t iic_addr;                                                                   /**< iic address */
} ags10et_handle_t;

/**
 * @brief ags10et information structure definition
 */
typedef struct ags10et_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[8];                 /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} ags10et_info_t;

/**
 * @}
 */

/**
 * @defgroup ags10et_link_driver ags10et link driver function
 * @brief    ags10et link driver modules
 * @ingroup  ags10et_driver
 * @{
 */

/**
 * @brief     initialize ags10et_handle_t structure
 * @param[in] HANDLE pointer to an ags10et handle structure
 * @param[in] STRUCTURE ags10et_handle_t
 * @note      none
 */
#define DRIVER_AGS10ET_LINK_INIT(HANDLE, STRUCTURE)      memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link iic_init function
 * @param[in] HANDLE pointer to an ags10et handle structure
 * @param[in] FUC pointer to an iic_init function address
 * @note      none
 */
#define DRIVER_AGS10ET_LINK_IIC_INIT(HANDLE, FUC)        (HANDLE)->iic_init = FUC

/**
 * @brief     link iic_deinit function
 * @param[in] HANDLE pointer to an ags10et handle structure
 * @param[in] FUC pointer to an iic_deinit function address
 * @note      none
 */
#define DRIVER_AGS10ET_LINK_IIC_DEINIT(HANDLE, FUC)      (HANDLE)->iic_deinit = FUC

/**
 * @brief     link iic_read_cmd function
 * @param[in] HANDLE pointer to an ags10et handle structure
 * @param[in] FUC pointer to an iic_read_cmd function address
 * @note      none
 */
#define DRIVER_AGS10ET_LINK_IIC_READ_CMD(HANDLE, FUC)    (HANDLE)->iic_read_cmd = FUC

/**
 * @brief     link iic_write_cmd function
 * @param[in] HANDLE pointer to an ags10et handle structure
 * @param[in] FUC pointer to an iic_write_cmd function address
 * @note      none
 */
#define DRIVER_AGS10ET_LINK_IIC_WRITE_CMD(HANDLE, FUC)   (HANDLE)->iic_write_cmd = FUC

/**
 * @brief     link iic_write function
 * @param[in] HANDLE pointer to an ags10et handle structure
 * @param[in] FUC pointer to an iic_write function address
 * @note      none
 */
#define DRIVER_AGS10ET_LINK_IIC_WRITE(HANDLE, FUC)       (HANDLE)->iic_write = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE pointer to an ags10et handle structure
 * @param[in] FUC pointer to a delay_ms function address
 * @note      none
 */
#define DRIVER_AGS10ET_LINK_DELAY_MS(HANDLE, FUC)        (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE pointer to an ags10et handle structure
 * @param[in] FUC pointer to a debug_print function address
 * @note      none
 */
#define DRIVER_AGS10ET_LINK_DEBUG_PRINT(HANDLE, FUC)     (HANDLE)->debug_print = FUC

/**
 * @}
 */

/**
 * @defgroup ags10et_base_driver ags10et base driver function
 * @brief    ags10et base driver modules
 * @ingroup  ags10et_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info pointer to an ags10et info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t ags10et_info(ags10et_info_t *info);

/**
 * @brief     initialize the chip
 * @param[in] *handle pointer to an ags10et handle structure
 * @return    status code
 *            - 0 success
 *            - 1 init failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 * @note      none
 */
uint8_t ags10et_init(ags10et_handle_t *handle);

/**
 * @brief     close the chip
 * @param[in] *handle pointer to an ags10et handle structure
 * @return    status code
 *            - 0 success
 *            - 1 deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ags10et_deinit(ags10et_handle_t *handle);

/**
 * @brief      read ethanol
 * @param[in]  *handle pointer to an ags10et handle structure
 * @param[out] *raw pointer to a raw data buffer
 * @param[out] *ppb pointer to a converted data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read ethanol failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 *             - 4 crc is error
 *             - 5 chip is busy
 * @note       none
 */
uint8_t ags10et_read_ethanol(ags10et_handle_t *handle, uint32_t *raw, uint32_t *ppb);

/**
 * @brief     zero point calibration
 * @param[in] *handle pointer to an ags10et handle structure
 * @param[in] raw raw data
 * @return    status code
 *            - 0 success
 *            - 1 zero point calibration failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      raw data unit is 0.1kohm
 */
uint8_t ags10et_zero_point_calibration(ags10et_handle_t *handle, uint16_t raw);

/**
 * @brief     reset zero point calibration
 * @param[in] *handle pointer to an ags10et handle structure
 * @return    status code
 *            - 0 success
 *            - 1 reset zero point calibration failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ags10et_reset_zero_point_calibration(ags10et_handle_t *handle);

/**
 * @brief     zero point calibration using current resistance 
 * @param[in] *handle pointer to an ags10et handle structure
 * @return    status code
 *            - 0 success
 *            - 1 current resistance zero point calibration failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ags10et_current_resistance_zero_point_calibration(ags10et_handle_t *handle);

/**
 * @brief      get resistance
 * @param[in]  *handle pointer to an ags10et handle structure
 * @param[out] *raw pointer to a raw data buffer
 * @param[out] *ohm pointer to a converted data buffer
 * @return     status code
 *             - 0 success
 *             - 1 get resistance failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 *             - 4 crc is error
 * @note       none
 */
uint8_t ags10et_get_resistance(ags10et_handle_t *handle, uint32_t *raw, double *ohm);

/**
 * @brief      get version
 * @param[in]  *handle pointer to an ags10et handle structure
 * @param[out] *version pointer to a version buffer
 * @return     status code
 *             - 0 success
 *             - 1 get resistance failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 *             - 4 crc is error
 * @note       none
 */
uint8_t ags10et_get_version(ags10et_handle_t *handle, uint8_t *version);

/**
 * @brief     modify slave address
 * @param[in] *handle pointer to an ags10et handle structure
 * @param[in] addr_7bit new slave address
 * @return    status code
 *            - 0 success
 *            - 1 modify slave address failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ags10et_modify_slave_address(ags10et_handle_t *handle, uint8_t addr_7bit);

/**
 * @brief     set slave address
 * @param[in] *handle pointer to an ags10et handle structure
 * @param[in] addr slave address
 * @return    status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note      none
 */
uint8_t ags10et_set_slave_address(ags10et_handle_t *handle, uint8_t addr);

/**
 * @brief      get slave address
 * @param[in]  *handle pointer to an ags10et handle structure
 * @param[out] *addr pointer to a slave address buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t ags10et_get_slave_address(ags10et_handle_t *handle, uint8_t *addr);

/**
 * @}
 */

/**
 * @defgroup ags10et_extend_driver ags10et extend driver function
 * @brief    ags10et extend driver modules
 * @ingroup  ags10et_driver
 * @{
 */

/**
 * @brief     set the chip register
 * @param[in] *handle pointer to an ags10et handle structure
 * @param[in] reg register address
 * @param[in] *buf pointer to a data buffer
 * @param[in] len length of data buffer
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ags10et_set_reg(ags10et_handle_t *handle, uint8_t reg, uint8_t *buf, uint16_t len);

/**
 * @brief      get the chip register
 * @param[in]  *handle pointer to an ags10et handle structure
 * @param[in]  reg register address
 * @param[out] *buf pointer to a data buffer
 * @param[in]  len length of data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t ags10et_get_reg(ags10et_handle_t *handle, uint8_t reg, uint8_t *buf, uint16_t len);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
