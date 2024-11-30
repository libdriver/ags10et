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
 * @file      driver_ags10et_read_test.c
 * @brief     driver ags10et read test source file
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

#include "driver_ags10et_read_test.h"
#include <stdlib.h>

static ags10et_handle_t gs_handle;        /**< ags10et handle */

/**
 * @brief     read test
 * @param[in] times test times
 * @return    status code
 *            - 0 success
 *            - 1 read failed
 * @note      none
 */
uint8_t ags10et_read_test(uint32_t times)
{
    uint8_t res;
    uint8_t version;
    uint8_t addr_7bit;
    uint16_t reg;
    double ohm;
    uint32_t i;
    uint32_t raw;
    uint32_t ppb;
    ags10et_info_t info;
   
    /* link interface function */
    DRIVER_AGS10ET_LINK_INIT(&gs_handle, ags10et_handle_t);
    DRIVER_AGS10ET_LINK_IIC_INIT(&gs_handle, ags10et_interface_iic_init);
    DRIVER_AGS10ET_LINK_IIC_DEINIT(&gs_handle, ags10et_interface_iic_deinit);
    DRIVER_AGS10ET_LINK_IIC_READ_CMD(&gs_handle, ags10et_interface_iic_read_cmd);
    DRIVER_AGS10ET_LINK_IIC_WRITE_CMD(&gs_handle, ags10et_interface_iic_write_cmd);
    DRIVER_AGS10ET_LINK_IIC_WRITE(&gs_handle, ags10et_interface_iic_write);
    DRIVER_AGS10ET_LINK_DELAY_MS(&gs_handle, ags10et_interface_delay_ms);
    DRIVER_AGS10ET_LINK_DEBUG_PRINT(&gs_handle, ags10et_interface_debug_print);

    /* get ags10et information */
    res = ags10et_info(&info);
    if (res != 0)
    {
        ags10et_interface_debug_print("ags10et: get info failed.\n");
       
        return 1;
    }
    else
    {
        /* print ags10et information */
        ags10et_interface_debug_print("ags10et: chip is %s.\n", info.chip_name);
        ags10et_interface_debug_print("ags10et: manufacturer is %s.\n", info.manufacturer_name);
        ags10et_interface_debug_print("ags10et: interface is %s.\n", info.interface);
        ags10et_interface_debug_print("ags10et: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        ags10et_interface_debug_print("ags10et: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        ags10et_interface_debug_print("ags10et: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        ags10et_interface_debug_print("ags10et: max current is %0.2fmA.\n", info.max_current_ma);
        ags10et_interface_debug_print("ags10et: max temperature is %0.1fC.\n", info.temperature_max);
        ags10et_interface_debug_print("ags10et: min temperature is %0.1fC.\n", info.temperature_min);
    }
    
    /* start basic read test */
    ags10et_interface_debug_print("ags10et: start read test.\n");
    
    /* ags10et init */
    res = ags10et_init(&gs_handle);
    if (res != 0)
    {
        ags10et_interface_debug_print("ags10et: init failed.\n");
       
        return 1;
    }
    
    /* get version */
    res = ags10et_get_version(&gs_handle, &version);
    if (res != 0)
    {
        ags10et_interface_debug_print("ags10et: get version failed.\n");
        (void)ags10et_deinit(&gs_handle);
       
        return 1;
    }
    
    /* print result */
    ags10et_interface_debug_print("ags10et: version is 0x%02X.\n", version);
    
    /* delay 2000 ms for read */
    ags10et_interface_delay_ms(2000);
    for (i = 0; i < times; i++)
    {
        /* read ethanol */
        res = ags10et_read_ethanol(&gs_handle, (uint32_t *)&raw, (uint32_t *)&ppb);
        if (res != 0)
        {
            ags10et_interface_debug_print("ags10et: read ethanol failed.\n");
            (void)ags10et_deinit(&gs_handle);
           
            return 1;
        }
    
        /* print result */
        ags10et_interface_debug_print("ags10et: ethanol is %dppb.\n", ppb);

        /* delay 2000 ms*/
        ags10et_interface_delay_ms(2000);
    }

    /* get resistance */
    res = ags10et_get_resistance(&gs_handle, &raw, &ohm);
    if (res != 0)
    {
        ags10et_interface_debug_print("ags10et: get resistance failed.\n");
        (void)ags10et_deinit(&gs_handle);
       
        return 1;
    }
    
    /* print result */
    ags10et_interface_debug_print("ags10et: resistance is %0.2fohm.\n", ohm);
    
    /* delay 2000 ms for read */
    ags10et_interface_delay_ms(2000);
    
    reg = rand() % 0xFFFFU;
    res = ags10et_zero_point_calibration(&gs_handle, reg);
    if (res != 0)
    {
        ags10et_interface_debug_print("ags10et: zero point calibration failed.\n");
        (void)ags10et_deinit(&gs_handle);
       
        return 1;
    }
    
    /* print result */
    ags10et_interface_debug_print("ags10et: zero point calibration 0x%04X.\n", reg);
    
    /* delay 2000 ms*/
    ags10et_interface_delay_ms(2000);
    
    /* current resistance zero point calibration  */
    res = ags10et_current_resistance_zero_point_calibration(&gs_handle);
    if (res != 0)
    {
        ags10et_interface_debug_print("ags10et: current resistance zero point calibration failed.\n");
        (void)ags10et_deinit(&gs_handle);
       
        return 1;
    }
    
    /* print result */
    ags10et_interface_debug_print("ags10et: current resistance zero point calibration.\n");
    
    /* delay 2000 ms*/
    ags10et_interface_delay_ms(2000);
    
    /* reset zero point calibration */
    res = ags10et_reset_zero_point_calibration(&gs_handle);
    if (res != 0)
    {
        ags10et_interface_debug_print("ags10et: reset zero point calibration failed.\n");
        (void)ags10et_deinit(&gs_handle);
       
        return 1;
    }
    
    /* print result */
    ags10et_interface_debug_print("ags10et: reset zero point calibration.\n");
    
    /* delay 2000 ms*/
    ags10et_interface_delay_ms(2000);
    
    addr_7bit = 0x1A;
    res = ags10et_modify_slave_address(&gs_handle, addr_7bit);
    if (res != 0)
    {
        ags10et_interface_debug_print("ags10et: modify slave address failed.\n");
        (void)ags10et_deinit(&gs_handle);
       
        return 1;
    }
    
    /* print result */
    ags10et_interface_debug_print("ags10et: modify slave address 0x%02X.\n", addr_7bit);
    
    /* finish read test */
    ags10et_interface_debug_print("ags10et: finish read test.\n");
    (void)ags10et_deinit(&gs_handle);
    
    return 0;
}
