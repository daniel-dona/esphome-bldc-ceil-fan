import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import button
from esphome.const import CONF_ID

from .. import CONF_CEILING_FAN_RF_ID, CeilingFanRf, ceiling_fan_rf_ns

CONF_BUTTON_CODE = "button_code"

CeilingFanRfButton = ceiling_fan_rf_ns.class_("CeilingFanRfButton", button.Button, cg.Component)

CONFIG_SCHEMA = button.button_schema(CeilingFanRfButton).extend(
    {
        cv.GenerateID(CONF_CEILING_FAN_RF_ID): cv.use_id(CeilingFanRf),
        cv.Required(CONF_BUTTON_CODE): cv.uint8_t,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await button.register_button(var, config)
    parent = await cg.get_variable(config[CONF_CEILING_FAN_RF_ID])
    cg.add(var.set_parent(parent))
    cg.add(var.set_button_code(config[CONF_BUTTON_CODE]))
