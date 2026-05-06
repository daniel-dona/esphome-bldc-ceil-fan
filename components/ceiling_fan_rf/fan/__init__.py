import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import fan

from .. import CONF_CEILING_FAN_RF_ID, CeilingFanRf, ceiling_fan_rf_ns

CeilingFanRfFan = ceiling_fan_rf_ns.class_("CeilingFanRfFan", fan.Fan, cg.Component)

CONFIG_SCHEMA = fan.fan_schema(CeilingFanRfFan).extend(
    {
        cv.GenerateID(CONF_CEILING_FAN_RF_ID): cv.use_id(CeilingFanRf),
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = await fan.new_fan(config)
    await cg.register_component(var, config)
    parent = await cg.get_variable(config[CONF_CEILING_FAN_RF_ID])
    cg.add(var.set_parent(parent))
