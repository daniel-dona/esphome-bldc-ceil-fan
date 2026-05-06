import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import remote_base
from esphome.const import CONF_ID

DEPENDENCIES = ["remote_transmitter"]
AUTO_LOAD = ["remote_base"]

CONF_CEILING_FAN_RF_ID = "ceiling_fan_rf_id"
CONF_FAN_ID = "fan_id"

ceiling_fan_rf_ns = cg.esphome_ns.namespace("ceiling_fan_rf")
CeilingFanRf = ceiling_fan_rf_ns.class_("CeilingFanRf", cg.Component)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(CeilingFanRf),
        cv.GenerateID(remote_base.CONF_TRANSMITTER_ID): cv.use_id(
            remote_base.RemoteTransmitterBase
        ),
        cv.Required(CONF_FAN_ID): cv.hex_uint16_t,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    transmitter = await cg.get_variable(config[remote_base.CONF_TRANSMITTER_ID])
    cg.add(var.set_transmitter(transmitter))
    cg.add(var.set_fan_id(config[CONF_FAN_ID]))
