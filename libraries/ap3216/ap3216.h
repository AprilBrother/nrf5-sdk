#ifndef AP3216_H
#define AP3216_H

#include "nrf_twi_sensor.h"
#include "ap3216_internal.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Possible sensor addresses.
 */
#define AP3216_BASE_ADDRESS             0x1EU

typedef void (* ap3216_data_callback_t)(ret_code_t result, uint8_t * p_data);

#define AP3216_INSTANCE_DEF(_ap3216_inst_name, _p_twi_sensor, _sensor_address) \
    AP3216_INTERNAL_INSTANCE_DEF(_ap3216_inst_name, _p_twi_sensor, _sensor_address)

ret_code_t ap3216_init(ap3216_instance_t * p_instance);

ret_code_t ap3216_boot(ap3216_instance_t * p_instance);

ret_code_t ap3216_pd(ap3216_instance_t * p_instance);

ret_code_t ap3216_als_read(ap3216_instance_t *       p_instance,
                           ap3216_data_callback_t    user_callback,
                           uint16_t *                p_data);

#ifdef __cplusplus
}
#endif

#endif // AP3216_H
