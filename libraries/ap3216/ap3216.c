#include "ap3216.h"
#include <string.h>

#define AP3216_WRITE(p_instance, msg)                   \
    nrf_twi_sensor_write(p_instance->p_sensor_data,     \
                         p_instance->sensor_addr,       \
                         msg,                           \
                         ARRAY_SIZE(msg),               \
                         true)

ret_code_t ap3216_init(ap3216_instance_t * p_instance) {
    ASSERT(p_instance != NULL);
    return NRF_SUCCESS;
}

ret_code_t ap3216_als_read(ap3216_instance_t *       p_instance,
                           ap3216_data_callback_t    user_callback,
                           uint16_t *                p_data) 
{
    ret_code_t err_code;
    uint8_t *p;
    ASSERT(p_instance != NULL);

    p = (uint8_t *)p_data;
    err_code = nrf_twi_sensor_reg_read(p_instance->p_sensor_data,
                                       p_instance->sensor_addr,
                                       AP3216_REG_ALS_DATA_L,
                                       NULL,
                                       p,
                                       1);

    return nrf_twi_sensor_reg_read(p_instance->p_sensor_data,
                                   p_instance->sensor_addr,
                                   AP3216_REG_ALS_DATA_H,
                                   (nrf_twi_sensor_reg_cb_t) user_callback,
                                   &p[1],
                                   1);
}

ret_code_t ap3216_boot(ap3216_instance_t * p_instance) {
    ASSERT(p_instance != NULL);
    uint8_t reg_val = AP3216_SYS_ALS_ONCE;
    uint8_t send_msg[] = {
        AP3216_REG_SYS_REG,
        reg_val
    };

    return AP3216_WRITE(p_instance, send_msg);
}

ret_code_t ap3216_pd(ap3216_instance_t * p_instance) {
    ASSERT(p_instance != NULL);
    uint8_t reg_val = 0;
    uint8_t send_msg[] = {
        AP3216_REG_SYS_REG,
        reg_val
    };

    return AP3216_WRITE(p_instance, send_msg);
}
