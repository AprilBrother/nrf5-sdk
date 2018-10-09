#ifndef AP3216_INTERNAL_H
#define AP3216_INTERNAL_H

#ifdef __cplusplus
extern "C" {
#endif

#define AP3216_REG_SYS_REG              0x0
#define AP3216_REG_ALS_DATA_L           0x0C
#define AP3216_REG_ALS_DATA_H           0x0D

#define AP3216_SYS_ALS                  0x1 // b001
#define AP3216_SYS_ALS_ONCE             0x5 // b101

// For auto incrementing address, msb in register address must be set to 1.
#define AP3216_INCR_REG_MASK            0x80

/**
 * @brief Structure holding sensor instance
 */
typedef struct
{
    nrf_twi_sensor_t * const p_sensor_data;
    uint8_t const            sensor_addr;

    uint8_t                  sys_reg;
    uint8_t                  als_data_reg;
} ap3216_instance_t;


/**
 * @brief Macro creating hts221 sensor instance.
 */
#define AP3216_INTERNAL_INSTANCE_DEF(_ap3216_inst_name, _p_twi_sensor, _sensor_address)        \
    static ap3216_instance_t _ap3216_inst_name =                                               \
    {                                                                                          \
        .p_sensor_data = _p_twi_sensor,                                                        \
        .sensor_addr   = _sensor_address,                                                      \
    }

#ifdef __cplusplus
}
#endif

#endif // AP3216_INTERNAL_H
